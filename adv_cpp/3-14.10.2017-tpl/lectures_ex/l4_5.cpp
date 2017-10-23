#include <iostream>
//co tu się dzieje?
// class template members - member type aliases
template<typename T>
struct Vestor{
	using value_type = T;
	using iterator = Vextor_iter<T>;
};



int main(void){



    return 0;
}