#include <iostream>

// class example
template<class Char>
class String{
public:
	String() {

	};

	Char& operator[](int n){

	}

	String& operator+=(Char c){

	}

	template<typename OtherChar>
	String& operator+(const String<OtherChar>&){

	}

private:
	/* impl */
};

int main(void){

	String<char> st;


    return 0;
}