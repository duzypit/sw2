#include <iostream>
//function templates
//argument deduction
//templaet operators
//DRAWBACKS2 - what type is T
//co tu się dzieje?

template<typename T>
void fun(T){
	std::cout << T << std::endl;
}

int main(void){
	int a = 0;
	int& b = a;
	fun(b);

    return 0;
}