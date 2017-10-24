#include <iostream>
//function templates
//argument deduction
//co tu się dzieje?

template<typename T>
void print(T t){
	std::cout << t << std::endl;
}

int main(void){
	print<char>('c');
	print('c');
	print(10);

    return 0;
}