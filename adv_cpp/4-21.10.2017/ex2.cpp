
// excercise

// Implement min() function that:

//     accepts two args: array, function pointer
//     works on C-style array (arr, ptr) (yes, template)
//     returns void
//     when min element is found function pointer is invoked
//     function pointer has signature: void ()(const TYPE &t)


#include <iostream>
template<typename T>
using fup_ptr = void (*)(T);

template<typename T>
void minElement(T* array, std::size_t size, fup_ptr<T> fn){
	auto v = *(std::min_element(array, array+size))

	fn(v);
}

static float smallest;
void f(float f) {smallest = f}

int main(void){

    return 0;
}