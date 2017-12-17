//equal/mismatch
#include <iostream>
#include <algorithm>
#include <string>
//http://slides.com/uczelnia_bt_kw/stl-2#/5/10
/*
excercise
Implement a function that
checks if a string is palindrome
using std::mismatch/std::equal
*/


bool pali (std::string s1){

	return std::equal(s1.begin(), s1.end(), s1.rbegin(), s1.rend());
}

int main(){
	std::string s{"kayak"};
	std::cout << (pali(s) ? "true" : "false") << std::endl;
	return 0;

}
