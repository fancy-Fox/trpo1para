# флаги, используемые при компиляции
FLAGS = -Wall -Werror --std=c++11
EXE = bin/geometry.exe
DIR_SRC = build/src
DIR_TEST = build/test

all: $(EXE)

$(EXE): $(DIR_SRC)/geometry.o $(DIR_SRC)/figure.o $(DIR_SRC)/circle.o
	g++ $(FLAGS) $(DIR_SRC)/geometry.o $(DIR_SRC)/figure.o $(DIR_SRC)/circle.o -o $(EXE)

$(DIR_SRC)/geometry.o: src/geometry.cc
	g++ $(FLAGS) -c src/geometry.cc -o $(DIR_SRC)/geometry.o

$(DIR_SRC)/figure.o: src/figure.cc
	g++ $(FLAGS) -c src/figure.cc -o $(DIR_SRC)/figure.o

$(DIR_SRC)/circle.o: src/circle.cc
	g++ $(FLAGS) -c src/circle.cc -o $(DIR_SRC)/circle.o


clean:
	rm -rf $(DIR_SRC)/*.o 
	rm -rf $(DIR_TEST)/*.o