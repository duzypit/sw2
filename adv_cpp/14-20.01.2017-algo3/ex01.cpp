#include <iostream>
#include <vector>
#include <algorithm>


int main(){

    std::vector<int> i {-1,-2,-3,-4};
    std::transform(i.begin(), i.end(), i.begin(), [](char c) -> char { return std::abs(c); });

    for(const auto& x : i){
        std::cout << x << " " << std::endl;
    }
}
