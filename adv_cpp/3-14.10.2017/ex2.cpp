// excercise - l5_3
// custom Array<10,T, false>
// uses std::array(stack) or std::vector(heap) based on 2nd template parameter
// provides a typical interface (operator[], begin(), end())
// has a max()/min() method

#include <iostream>
#include <vector>
#include <array>

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

	// begin(){

	// }

	// end(){

	// }

	// max(){

	// }

	// min(){

	// }

private:
	bool heap;
	std::array<T, size> _array; //stack
	std::vector<T> _vector; //heap
};



int main(void){

	Array<10, int, 0> test;
	std::cout << test[1] <<std::endl;

    return 0;
}

