#include <iostream>

// class template members - member function
template<typename T>
struct X{
	void mf1() {};
	T mf2();
};

template<typename T>
T X<t>::mf2() {};

int main(void){

	X<int> xi{9};
	std::string a = "str  ";
	X<std::string> xs {a};


    return 0;
}