# флаги, используемые при компиляции
FLAGS = -Wall -Werror --std=c++11
EXE = bin/geometry.exe
TESTS = bin/test.exe
DIR_SRC = build/src
DIR_TEST = build/test
GTEST_D = thirdparty/googletest
LD_FLAGS = -L $(GTEST_D)/lib -lgtest_main -lpthread


all: $(EXE) $(TESTS) clean

$(EXE): $(DIR_SRC)/geometry.o $(DIR_SRC)/parse.o $(DIR_SRC)/figure.o $(DIR_SRC)/circle.o
	g++ $(FLAGS) $(DIR_SRC)/geometry.o $(DIR_SRC)/parse.o $(DIR_SRC)/figure.o $(DIR_SRC)/circle.o -o $(EXE)

$(DIR_SRC)/geometry.o: src/geometry.cc
	g++ $(FLAGS) -c src/geometry.cc -o $(DIR_SRC)/geometry.o

$(DIR_SRC)/parse.o: src/parse.h
	g++ $(FLAGS) -c src/parse.cc -o $(DIR_SRC)/parse.o

$(DIR_SRC)/figure.o: src/figure.cc
	g++ $(FLAGS) -c src/figure.cc -o $(DIR_SRC)/figure.o

$(DIR_SRC)/circle.o: src/circle.cc
	g++ $(FLAGS) -c src/circle.cc -o $(DIR_SRC)/circle.o

$(TESTS) : $(DIR_SRC)/parse.o $(DIR_SRC)/figure.o $(DIR_SRC)/circle.o $(DIR_TEST)/test.o
	g++ $(FLAGS)  $(LD_FLAGS) -I $(GTEST_D)/include -I $(DIR_SRC) $(DIR_SRC)/parse.o $(DIR_SRC)/figure.o $(DIR_SRC)/circle.o  $(DIR_TEST)/test.o -o $(TESTS)

$(DIR_TEST)/test.o: test/test.cpp
	g++ $(FLAGS) -I $(GTEST_D)/include -I src/ -c test/test.cpp -o $(DIR_TEST)/test.o

clean:
	rm -rf $(DIR_SRC)/*.o 
	rm -rf $(DIR_TEST)/*.o