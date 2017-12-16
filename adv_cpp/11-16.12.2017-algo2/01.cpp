#include <iostream>
#include <algorithm>
#include <list>

struct gen{
	int operator()(){return ++_val;};
	int _val {0};
};

std::list<int> foo() {
	std::list <int> obj;
	//obj.resize(10);
	//gen g;
	int counter = 0;
	//std::generate_n(std::back_inserter,obj, 10, g);
	//std::generate(obj.begin(), obj.end(), g);
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