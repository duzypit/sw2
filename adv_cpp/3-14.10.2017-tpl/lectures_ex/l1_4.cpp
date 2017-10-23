#include <iostream>
#include <vector>
#include <algorithm>


int main(void){

	std::vector<int> vector;
	std::string str;

	std::vector<int> nums{3,4,2,8,15,267};
	std::for_each(nums.begin(), nums.end(), [](const auto& n){ std::cout << " " << n;});
	std::cout << std::endl;

	return 0;
}