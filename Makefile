main: cv.pdf

cv.pdf: cv.tex _config.yml _data/publications.yml _data/cv.yml _data/teaching.yml _data/academia.yml _data/gallery.yml
	jekyll build
	pdflatex _site/cv.tex
