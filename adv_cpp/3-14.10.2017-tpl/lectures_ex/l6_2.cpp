#include <iostream>
//function templates
//co tu się dzieje?
// template<typename T>
// void print(T t){
// 	std::cout << "template t: " << t << std::endl;
// }

template<typename T>
void print(const T& t) {
	std::cout << "template 2 t: " << t << std::endl;
}


void print(int i){
	std::cout << "free function i: " << i << std::endl;
}



int main(void){
	print<char>('c');
	print<int>('k');
	print(10);


    return 0;
}