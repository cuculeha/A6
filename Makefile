run-test: main.cpp playerType.o
	g++ -std=c++20 -Wall -Werror -o run-test main.cpp playerType.o

playerType.h: playerType.cpp
	g++ -std=c++20 -Wall -Werror playerType.cpp

clean:
	-rm *.o run-test
