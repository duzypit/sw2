#include <iostream>
#include <algorithm>
#include <vector>

int odds(std::vector<int> v){
	int retval = 0;
	std::count(std::begin(v), std::end(v),[&retval](int i) {
		if(i % 2 == 0){
			++retval;
		}
	});

	return retval;
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
	std::vector<int> v{1,2,3,4,5,6};
	std::cout<<odds(v)<<std::endl;
	return 0;

}