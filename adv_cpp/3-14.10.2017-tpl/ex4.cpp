// excercise - l6_16
//For Array<N, T, bool> implement a template getArray() function that can deduce T

#include <iostream>
#include <vector>
#include <array>
#include <algorithm>

template<std::size_t N, typename T, bool B>
Array getArray(T t){
	return Array<N, T, B> {t};
}

template<std::size_t size, typename T, bool use_heap>
class Array{
public:
	Array() {};

	Array(std::size_t s, T type, bool b){
		
		if(b){
			this->heap = 1;
			this->_vector.reserve(s); 
		} else {
			this->heap = 0;
			//this->_array.fill(0);
		}
	}

	T& operator[](int n){
		if(this->heap){
			return this->_vector[n];
		} else {
			return this->_array[n];
		}
	}


	T max(){
		if(this->heap){
			return std::max_element(this->_vector.begin(), this->_vector.end());
		} else {
			return std::max_element(this->_array.begin(), this->_array.end());
		}
	}


private:
	bool heap;
	std::array<T, size> _array; //stack
	std::vector<T> _vector; //heap
};



int main(void){

	Array<10, int, 0> test;
	std::cout << test.max() <<std::endl;

	auto _arr = getArray(10); 

    return 0;
}

