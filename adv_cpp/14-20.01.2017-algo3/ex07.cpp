#include <iostream>
#include <vector>



int main(){

    std::size_t i;
    std::cout << "n =";
    std::cin >> i;
        std::cout << std::endl;
    std::vector<float> v(i);
    //generat_n!
    for(std::size_t x= 0; x < i; ++x){
        std::cout << "give me float(" << x << "/" << "): ";
        float f;
        std::cin >> f;
        v.push_back(f);
    }

}
