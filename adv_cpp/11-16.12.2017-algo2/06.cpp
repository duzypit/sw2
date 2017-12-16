#include <iostream>
#include <algorithm>
#include <vector>

auto min(std::vector<int> v){
	//if(v.empty()) throw std::runtime
	// ForwardIt min_element( ForwardIt first, ForwardIt last, Compare comp );
	auto it = min_element(std::begin(v), std::end(v), [](const int& x, const int& y){ return std::abs(x)<std::abs(y); });

	return *(it);
}

float mean(const std::vector<int> v){
	if (v.begin() == v.end()){
		return 0;
	}
	float sum = 0;
	std::for_each(std::begin(v), std::end(v), [&sum](int i){ sum += static_cast<float>(i);});
	return sum / static_cast<float>(v.size());
}

int main(){
	std::vector<int> v{1,2,3,4,5,6,0};
	std::cout << min(v) << std::endl;
	return 0;

}