#include <iostream>

template <typename t>
void fun(T val){
    std::cout << __PREETY_FUNCTION__ << std::endl;
}

int main(){
    int a = 0;
    int& b = a;
	fun(b);
	return 0;
}

