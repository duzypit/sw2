#include <iostream>
#include <algorithm>
#include <vector>

//http://slides.com/uczelnia_bt_kw/stl-2#/5/7
/*
excercise
Implement a function that

works on std::vector<int>
finds all occurrences of N
return a vector of indexes of N's
*/

//size_t - uniwersalnie używane do rozmiaru/indeksów
std::vector<std::size_t> min(std::vector<int> v, int search){
	std::vector<std::size_t> found;
	if (v.empty()) return found;

	auto it = std::find(v.begin(), v.end(), search);

	while(it != v.end()){
	 	found.push_back(std::distance(v.begin(), it));
	 	it++;
	 	it = std::find(it, v.end(), search);
	}


	return found;
}
template<typename T>
void print(T && c){
	std::cout << "[ ";
	auto endIt = std::end(c);
	std::advance(endIt, -1);
	std::for_each(std::begin(c), endIt, [](auto val) {
		std::cout << val << ", ";
	});
	std::cout << *(endIt);
	std::cout << " ]" << std::endl;
}


int main(){
	std::vector<int> v{1,2,3,4,5,6,0,6};
    std::vector<std::size_t> result;
    result = min(v, 6);
	print(result);
	return 0;

}
