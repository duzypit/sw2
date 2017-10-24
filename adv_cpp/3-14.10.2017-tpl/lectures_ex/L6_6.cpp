#include <iostream>
//function templates
//argument deduction
//templaet operators
//co tu się dzieje?

template<typename CharType>
std::ostream& operator<<(
	std::ostream& od,
	const std::basic_string<CharType>& str);

int main(void){
	std::cout << "hell'o janke" << std::endl;

    return 0;
}