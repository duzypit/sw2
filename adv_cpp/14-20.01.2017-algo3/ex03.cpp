#include <iostream>
#include <vector>
#include <algorithm>




int main(){
    std::vector<int> v {1,2,4,3,4,5,6};
    auto i = std::remove(v.begin(), v.end(), 4);

    for(auto& x : v){
        std::cout << x << " ";
    }
    std::cout << std::endl;
    std::cout << "result " <<  *i << std::endl;

    v.erase(i, v.end());

    for(auto& x : v){
        std::cout << x << " ";
    }
    std::cout << std::endl;

}
