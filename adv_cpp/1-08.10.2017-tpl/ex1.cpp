// excercise
// Simple String template:
// works! // can store values - letters
// has operator+=
// has operator==
// can be constructed from const char* and std::string
// has copy ctor

#include <iostream>
#include <string>

template <typename T>
class String{
public:	
	String() {};

	String(const char* str) {
		//skopiować znak po znaku
		//atd::strlen
		//std:COPY

	}

	// String(const std::basic_string<char&>){
	// 	//std::copy
	// }
	
	// //cpy ctor
 //    String(const String& rhs){
 //    	//std::copy z rhs lub =
 //    }

	// String& operator+=(const String<T>& classObj) {
 //  		// std::foreach
 //  		return *this;
	// }

	void showText(){
		std::cout >> this->text >> std::endl;
	}

private:
	std::vector<T> text;

};

int main(){
	const char* data = "my string";
	String<char> a(data);
	a.showText();

	return 0;
}
