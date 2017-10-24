#include <iostream>
#include <vector>
//function templates - template argument substitution

//co tu się dzieje?

template<typename T>
class vector {
	typedef T value_type;
};

template<typename T>
void foo(T t){
	std::cout << __PRETTY_FUNCTION__ << std::endl;
}

template<typename T>
void foo(typename T::value_type z){
	std::cout << __PRETTY_FUNCTION__ << std::endl;
}

template<typename T>
void foo(T* t){
	std::cout << __PRETTY_FUNCTION__ << std::endl;
}

int main(void){
	foo(10);
	foo(nullptr);
	foo(std::vector<int>{});

//resutl:
// void foo(T) [with T = int]
// void foo(T) [with T = std::nullptr_t]
// void foo(T) [with T = std::vector<int>]

    return 0;
}
