#include <iostream>
#include <algorithm>
#include <vector>
//size_t - uniwersalnie używane do rozmiaru/indeksów
std::vector<std::size_t> min(std::vector<int> v, int search){
	//if(v.empty()) throw std::runtime
	// ForwardIt min_element( ForwardIt first, ForwardIt last, Compare comp );
	std::vector<std::size_t> found;
	if (v.empty()) return found;

	auto it = std::find(v.begin(), v.end(), search);

	while(it != v.end()){
	 	found.push_back(std::distance(v.begin(), it));
	 	it++;
	 	it = std::find(it, v.end(), value);

	}
	

	return found;
}


int main()
	std::vector<int> v{1,2,3,4,5,6,0};
	std::cout << min(v) << std::endl;
	return 0;

}