#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

bool allUpper(std::string s){
    return std::all_of(s.begin(), s.end(), [](const char& i){ return (isupper(i)) == 0; });
}

int main(){
    std::vector<std::string> v;
    v.push_back("TEST");
    v.push_back("testT");
    v.push_back("test");
    std::replace_if(v.begin(), v.end(), [] (std::string s) {return allUpper(s); }, "bummer" );
    for(auto& x : v){
        std::cout << x << std::endl;
    }
}

