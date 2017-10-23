#include <iostream>

// class templates???
template<typename T>
struct CustomString{};

int main(void){

	CustomString<char> str;
	CustomString<wchar_t> widestring;

	struct Tag{};

	CustomString<Tag> wtf;


    return 0;
}