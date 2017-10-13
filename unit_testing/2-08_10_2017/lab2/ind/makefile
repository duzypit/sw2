main: Picture.cpp Rectangle.cpp Triangle.cpp main.cpp
	g++ -o run.out -Wall -Wextra Picture.cpp Rectangle.cpp Triangle.cpp main.cpp -std=c++11

test: 
	#Picture.cpp Rectangle.cpp Triangle.cpp test.cpp
	g++ -o run.out -Wall -Wextra Picture.cpp Rectangle.cpp Triangle.cpp test.cpp -std=c++11 -pthread -lgmock

run:
	./run.out

clean:
	rm -rf run.out


