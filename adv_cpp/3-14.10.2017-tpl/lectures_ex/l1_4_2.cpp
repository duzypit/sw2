#include <iostream>
#include <vector>
#include <algorithm>


int main(void){

	std::vector<int> vector;
	std::string str;

	std::vector<int> nums{3,4,2,8,15,267};
	std::for_each(nums.begin(), nums.end(), [](const auto& n){ std::cout << " " << n;});
	std::cout << std::endl;

	template<typename T, typename Alloc = std::allocator<T>>
	class vector {};

	template<typename Iter, typename Funcion>
	Function for_each(Iter first, Iter last, Function f);

	using string = std::basic_string<char>;
	using wstring = std:;basic_string<wchar>;

	return 0;
}