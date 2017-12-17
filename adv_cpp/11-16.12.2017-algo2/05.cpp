#include <iostream>
#include <algorithm>
#include <vector>

//http://slides.com/uczelnia_bt_kw/stl-2#/5/2

/*
excercise

Implement a function that

    works on std::vector<int>
        counts odd elements
*/

int odds(std::vector<int> v){
	int retval = 0;
	std::count(std::begin(v), std::end(v),[&retval](int i) {
		if(i % 2 == 0){
			++retval;
		}
	});

	return retval;
}

int main(){
	std::vector<int> v{1,2,3,4,5,6};
	std::cout<<odds(v)<<std::endl;
	return 0;

}
