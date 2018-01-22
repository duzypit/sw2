#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

bool haveNum(std::string s){
    return std::any_of(s.begin(), s.end(), [](const char& i){ return (isdigit(i)) != 0; });
}

int main(){
    std::vector<std::string> v;
    v.push_back("TEST");
    v.push_back("testTi2");
    v.push_back("t1est");
    auto it = std::remove_if(v.begin(), v.end(), [] (const std::string& s) {return haveNum(s); });
    v.erase(it, v.end());
    for(const auto& x : v){
        std::cout << x << std::endl;
    }
}

