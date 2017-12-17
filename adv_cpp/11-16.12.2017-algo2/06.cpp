#include <iostream>
#include <algorithm>
#include <vector>

//http://slides.com/uczelnia_bt_kw/stl-2#/5/4

/*
excercise

Implement a function that

    works on std::vector<int>
        find element that is closest to 0

*/
auto min(std::vector<int> v){
	auto it = min_element(std::begin(v), std::end(v), [](const int& x, const int& y){ return std::abs(x)<std::abs(y); });

	return *(it);
}


int main(){
	std::vector<int> v{1,2,3,4,5,6,0};
	std::cout << min(v) << std::endl;
	return 0;

}
