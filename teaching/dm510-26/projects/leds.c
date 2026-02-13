/* This code is from https://www.codeembedded.com/blog/raspberry_pi_gpio/ and has been modified slightly */

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <unistd.h>
#include <stdint.h>


#define BCM2835_PERI_BASE      0x3F000000   // For Raspberry Pi 2, 3, Zero

#define GPIO_BASE              (BCM2835_PERI_BASE + 0x200000) // GPIO controller base
#define BLOCK_SIZE             (4*1024)

// Pointer to the mapped memory
volatile unsigned int *gpio;

// Function to set up the memory mapping for GPIO access
void setup_gpio() {
    int mem_fd;
    void *gpio_map;

    if ((mem_fd = open("/dev/mem", O_RDWR | O_SYNC)) < 0) {
        perror("Failed to open /dev/mem, try running as root");
        exit(EXIT_FAILURE);
    }

    // Map GPIO memory to our address space
    gpio_map = mmap(
        NULL,                 // Any address in our space will do
        BLOCK_SIZE,           // Map length
        PROT_READ | PROT_WRITE, // Enable reading & writing to mapped memory
        MAP_SHARED,           // Shared with other processes
        mem_fd,               // File descriptor for /dev/mem
        GPIO_BASE             // Offset to GPIO peripheral
    );

    close(mem_fd);

    if (gpio_map == MAP_FAILED) {
        perror("mmap error");
        exit(EXIT_FAILURE);
    }

    // volatile pointer to prevent compiler optimizations
    gpio = (volatile unsigned int *)gpio_map;
}

// Set GPIO pin as output
void set_gpio_output(int pin) {
    int reg = pin / 10;
    int shift = (pin % 10) * 3;
    // Clear the 3 bits for the pin and set it to 001 (output)
    gpio[reg] = (gpio[reg] & ~(7 << shift)) | (1 << shift);
}

// Set GPIO function
void set_gpio(int pin) {
    gpio[7] = (1 << pin);
}

// Reset GPIO function
void reset_gpio(int pin) {
    gpio[10] = (1 << pin);
}

int main() {
    // Toggle GPIO pin 29
    const int pin = 29;
    setup_gpio();
    set_gpio_output(pin);
    printf("Toggling GPIO %d. Press Ctrl+C to exit.\n", pin);

    // Toggle loop: alternately set and clear the pin
    while (1) {
        set_gpio(pin);    // Set pin high
        sleep(1);        // Wait for 1 s
        reset_gpio(pin);  // Set pin low
        sleep(1);        // Wait for 1 s
    }
    return 0;
}
