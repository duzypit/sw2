main: Picture.cpp Rectangle.cpp Triangle.cpp main.cpp
	g++ -o run.out -Wall -Wextra Picture.cpp Rectangle.cpp Triangle.cpp main.cpp -std=c++11

test: 
	#Picture.cpp Rectangle.cpp Triangle.cpp test.cpp
	g++ -o run.out -Wall -Wextra Picture.cpp Rectangle.cpp Triangle.cpp test.cpp -std=c++11 -pthread -lgmock

lab3: 
	#Picture.cpp Rectangle.cpp Triangle.cpp test.cpp
	g++ -I/home/meq/sw2/unit_testing/2-08_10_2017/lab2/gtest/googlemock/include/ -I/home/meq/sw2/unit_testing/2-08_10_2017/lab2/gtest/googletest/include/ -o run.out -Wall -Wextra Picture.cpp Rectangle.cpp Triangle.cpp lab3.cpp -std=c++11 -lgmock -pthread

run:
	./run.out

clean:
	rm -rf run.out


