#include <iostream>
#include <algorithm>
#include <vector>

template<typename T>
void print(T && c){
	// auto p = [](const auto& n) { std::cout << " " << n; };
	std::cout << "[ ";
	auto endIt = std::end(c);
	std::advance(endIt, -1);
	//std::for_each(std::begin(c), std::end(c), [](typename T::value_type val) {});
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