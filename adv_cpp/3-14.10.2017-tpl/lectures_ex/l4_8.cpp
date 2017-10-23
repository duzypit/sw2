#include <iostream>
//co tu się dzieje?
// class template members - friendship
template<typename T>
struct Array{
	friend std::ostream&
		operator<<(std::ostream& os, const Array<T>& arr);
}



int main(void){



    return 0;
}