# флаги, используемые при компиляции
FLAGS = -Wall

all: 
	g++ $(FLAGS) geometry.cc figure.cc circle.cc -o geometry.exe
