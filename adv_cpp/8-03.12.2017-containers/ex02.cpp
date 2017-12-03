#include <iostream>
#include <vector>
#include <algorithm>


// excercise

// Implement a function that

//     works on std::vector<int> 

//     finds a value in container and prints the index of the value



std::size_t findV(std::vector<int> vec, int val){
	return distance(vec.begin(), std::find(vec.begin(), vec.end(), val));
	
}

int main(){
	std::vector<int> vec {1,2,3,4,5};
	std::cout << findV(vec, 3) << std::endl;
}