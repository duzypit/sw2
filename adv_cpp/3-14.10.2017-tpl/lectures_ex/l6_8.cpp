#include <iostream>
//function templates
//argument deduction
//templaet operators
//DRAWBACKS - obcina floaty, jeśli int zadeklarują
//co tu się dzieje?

template<typename T1, typename T2, typename T3>
void fun(T1 t1, T2 t2, T3 t3){
	std::cout << "t1: " << t1 << ", t2: " << t2 << ", t3: " << t3 << std::endl;
}

int main(void){
	fun(1,2,3);
	fun<int>(1.0,2,3);
	fun<int, int>(1.2,3.3,3);

    return 0;
}