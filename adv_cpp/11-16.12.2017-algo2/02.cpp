#include <iostream>
#include <algorithm>
#include <vector>
//http://slides.com/uczelnia_bt_kw/stl-2#/4/2

/*
Implement for_each that prints a container

    with free function
    with predicate
    with lambda
*/



template<typename T>
void print(T && c){
	std::cout << "[ ";
	auto endIt = std::end(c);
	std::advance(endIt, -1);
	std::for_each(std::begin(c), endIt, [](auto val) {
		std::cout << val << ", ";
	});
	std::cout << *(endIt);
	std::cout << " ]" << std::endl;

}

int main(){
	std::vector<std::string> t{"1","2"};
	print(t);
	int tab[] = {0,1,2,3};
	print(tab);
	return 0;

}
