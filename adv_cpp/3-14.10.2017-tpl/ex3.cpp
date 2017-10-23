#include <iostream>
#include <vector>

template <class T>
std::ostream& operator<< (std::ostream& os, const std::vector<T>& vec) {
    // for (typename std::vector<T>::const_iterator ii = v.begin(); ii != v.end(); ++ii)
    // {
    //     os << " " << *ii;
    // }

    for(T v : vec)
    	os << v;

    return os;
}

int main(){
	std::vector<int> v = {7, 5, 16, 8};
	std::cout << v << std::endl;
	return 0;
}

