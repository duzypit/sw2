#include <iostream>
#include <functional>
//function templates
//argument deduction
//templaet operators
//DRAWBACKS3
//co tu się dzieje?

template<typename T>
void fun(T t){
	std::cout << t << std::endl;
}

int main(void){
	int a = 0;
	int& b = a;
	fun(std::ref(b));
	fun(std::cref(b));
    return 0;
}