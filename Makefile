main: cv.pdf

cv.pdf: cv.tex _data/publications.yml _data/cv.yml _data/teaching.yml
	jekyll build
	pdflatex _site/cv.tex
