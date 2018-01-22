#include <iostream>
#include <vector>
int main(){
    std::vector<std::uint8_t> v {1,2,3,4,5,6,10,15};
    std::ios::fmtflags old = std::cout.flags();
    for(auto& x : v){
        std::cout << std::oct << "0x" << static_cast<int>(x) << " " << std::hex << "0x" << static_cast<int>(x);
        std::cout.setf(old);
        std::cout << " " << static_cast<int>(x) <<std::endl;
    }

}
