#include <iostream>
#include <list>
#include <vector>
#include <algorithm>
// excercise

// Implement a function that inserts values from 1 to 10 to a list 

//     use std::generate
//     use function object
//     use lambd

// auto fn =[&object](int){print(object)};
// fn();

struct Pred{
	Pred() : counter(0){};
	int operator()(){ return counter++;}
private:
	int counter;
};

int main(){
	std::vector<int> y(10);
	Pred p;
	std::generate(y.begin(), y.end(), p);
	
	for(auto i : y){
		std::cout << i << "  ";
	}
	std::cout << std::endl;


	std::vector<int> v(10);
	v.reserve(10);
	int n = 0;
	std::generate(v.begin(), v.end(), [&n] () {return n++; });
	for(auto i : v){
		std::cout << i << "  ";
	}
	std::cout << std::endl;
}