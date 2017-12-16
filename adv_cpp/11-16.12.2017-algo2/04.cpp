#include <iostream>
#include <algorithm>
#include <vector>

template<typename T>
void print(T && c){
	

	std::cout << "[ ";
	auto endIt = std::end(c);
	std::advance(endIt, -1);
	//std::for_each(std::begin(c), std::end(c), [](typename T::value_type val) {});
	std::for_each(std::begin(c), endIt, [](auto val) {
		std::cout << val << ", ";	
	});
	std::cout << *(endIt);
	std::cout << " ]" << std::endl;

}

std::string lc(const std::string& c){
	std::string buffer;
	std::transform(c.begin(), c.end(), std::back_inserter(buffer), 
        [](auto val){ return std::toupper(val); } 
    );
    return buffer;
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
	std::string t{"a","b"};
	t = lc(t);
	print(t);
	//int tab[] = {0,1,2,3};
	//print(tab);
	return 0;

}