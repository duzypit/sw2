#include <iostream>

// class example
template<typename T>
struct X{
	int m = 7;
	T m2;
	X(const T& x) : m2(x){}
};

int main(void){

	X<int> xi{9};
	std::string a = "str  ";
	X<std::string> xs {a};


    return 0;
}