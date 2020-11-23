main: cv.pdf

cv.pdf: cv.tex
	jekyll build
	pdflatex _site/cv.tex
