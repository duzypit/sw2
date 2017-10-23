#include <iostream>
#include <string>

template <class T>
class String{
public:	
	String() {};

	String(const Char* str){
		//skopiować znak po znaku
		//atd::strlen\
		//std:COPY
	}

	String(const std::basic_string<Char&>){
		//std::copy
	}
	
	//cpy ctor
    String(const String& rhs){
    	//std::copy z rhs lub =
    }

	String& operator+=(const String<T>& classObj) {
  		// std::foreach
  		return *this;
	}

private:
	std::string elems;

};

int main(){

}
//simple str template
// += op
// constructed from const char* and std::string
// copy ctor
//basic_string <moj tyup>