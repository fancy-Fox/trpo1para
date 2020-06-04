.PHONY: clean all
CC = g++
CXXFLAGS = -Wall -Werror --std=c++17
EXE = bin/geometryT
TESTS = bin/test
DIR_SRC = build/src
DIR_INCLUDE = include
DIR_TEST = build/test
GTEST_D = thirdparty/googletest
LD_FLAGS = -L $(GTEST_D)/lib -lgtest_main -lpthread
CFLAG += -isystem $(GTEST_D)/include
CXX += -g -Wall -Wextra -pthread -std=c++17

all: $(EXE) $(TESTS)

$(EXE): $(DIR_SRC)/main.o $(DIR_SRC)/geometry.o $(DIR_SRC)/Triangle.o $(DIR_SRC)/Circle.o
	$(CC) $(CXXFLAGS) $(DIR_SRC)/main.o $(DIR_SRC)/geometry.o $(DIR_SRC)/Triangle.o $(DIR_SRC)/Circle.o -o $(EXE)

$(DIR_SRC)/main.o: src/main.cpp
	$(CC) $(CXXFLAGS) -I $(DIR_INCLUDE) -c src/main.cpp -o $(DIR_SRC)/main.o

$(DIR_SRC)/geometry.o: src/geometry.cpp
	$(CC) $(CXXFLAGS) -I $(DIR_INCLUDE) -c src/geometry.cpp -o $(DIR_SRC)/geometry.o

$(DIR_SRC)/Triangle.o: src/Triangle.cpp
	$(CC) $(CXXFLAGS) -I $(DIR_INCLUDE) -c src/Triangle.cpp -o $(DIR_SRC)/Triangle.o

$(DIR_SRC)/Circle.o: src/Circle.cpp
	$(CC) $(CXXFLAGS) -I $(DIR_INCLUDE) -c src/Circle.cpp -o $(DIR_SRC)/Circle.o

$(TESTS) : $(DIR_SRC)/geometry.o $(DIR_SRC)/Triangle.o $(DIR_SRC)/Circle.o $(DIR_TEST)/test.o
	$(CXX) $(CFLAG)  $(LD_FLAGS) -I $(GTEST_D)/include -I $(DIR_INCLUDE) -I src/ $(DIR_SRC)/geometry.o $(DIR_SRC)/Triangle.o $(DIR_SRC)/Circle.o  $(DIR_TEST)/test.o -o $(TESTS)

$(DIR_TEST)/test.o: test/test.cpp
	$(CXX) $(CFLAG) -I $(GTEST_D)/include -I $(DIR_INCLUDE) -I src/ -c test/test.cpp -o $(DIR_TEST)/test.o

clean:
	rm -rf $(DIR_SRC)/*.o 
	rm -rf $(DIR_TEST)/*.o
	bin/*.exe
