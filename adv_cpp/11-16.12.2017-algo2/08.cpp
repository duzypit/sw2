//equal/mismatch
#include <iostream>
#include <algorithm>
#include <string>
//size_t - uniwersalnie używane do rozmiaru/indeksów
bool pali (std::string s1){

	return std::equal(s1.begin(), s1.end(), s1.rbegin(), s1.rend());
}

int main(){
	std::string s{"kayak"};
	std::cout << (pali(s) ? "true" : "false") << std::endl;
	return 0;

}