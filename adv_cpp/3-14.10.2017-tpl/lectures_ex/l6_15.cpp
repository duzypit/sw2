#include <iostream>
#include <tuple>
#include <utility>
//function templates - template argument substitution
//pre c++17 function templates are super useful
//co tu się dzieje?


template<int N, typename T>
CustomString<T, N> getStr(T t) {
//auto getStr(T t)
	return CustomString<T,N> {t};
}

int main(void){
	auto p = std::make_pair(10,'c');
	std::cout << p.first << ", " << p.second << std::endl;
	auto w = std::make_tuple('a', nullptr, std::make_pair(10,10));
	std::cout << std::get<0>(w) << std::endl;

	auto str = getStr<10>('c');
    return 0;
}
