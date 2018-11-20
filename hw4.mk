Resultados_hw4.pdf: Resultado_hw4.tex
	pdflatex Resultado_hw4.tex

Resultados_hw4.tex: *.jpg 


*.jpg: PDE.cpp compilapde.o *.txt ODE.cpp compilaode.o
	python3 Plots_hw4.py

*.txt: PDE.cpp	compilapde.o ODE.cpp compilaode.o 
	./compilapde.o
	./compilaode.o


compilapde.o compilaode.o: PDE.cpp ODE.cpp	
	c++ PDE.cpp -o compilapde.o
	c++ ODE.cpp -o compilaode.o

clean:
	rm -f *.txt  *.o *.jpg *.aux *.log *.out 
