#include <iostream>
#include <algorithm>
#include <list>
//http://slides.com/uczelnia_bt_kw/stl-2#/3/5

/*
Implement a function that inserts values from 1 to 10 to a list

    use function object
    use std::generate
*/

struct gen{
	int operator()(){return ++_val;};
	int _val {0};
};

std::list<int> foo() {
	std::list <int> obj;
	int counter = 0;
	std::generate_n(std::back_inserter(obj), 10, [&counter]() mutable { return ++counter; });
	return obj;


}

int main(){
	std::list<int> t;
	t = foo();
	for(const auto& v: t){
		std::cout<< v << " ";
	}
	std::cout << std::endl;
}
