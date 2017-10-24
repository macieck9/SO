main: main.cpp
	g++ main.cpp -o main -Wall -Werror -lpthread

run: 
	./main
