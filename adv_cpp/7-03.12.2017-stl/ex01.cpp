#include <iostream>
#include <list>



int main(){
	std::list<int> i {1,2,3,4,5,6,7};
	for(auto& a : i){
		std::cout << a << std::endl;
	}
//operator[] does not exists
	for(int x = 0; x < i.size(); x++ ){
		std::cout << i[x] << std::endl;
	}
}