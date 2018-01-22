/*
excercisercise

Implement a function that

    returns std::pair<> from my_std::atoi
    exercises/excercise_pair.cpp
*/
#include <iostream>


namespace my_std{
std::pair<int, bool> atoi(std::string s){
    bool error = false;

    if(s.c_str()[0] != '0' && std::atoi(s.c_str()) == 0 ){
        error = true;
    }

    return std::make_pair(std::atoi(s.c_str()), error);
}



}

int main(){
    std::string t("456 test");
    std::cout << my_std::atoi(t).first << ", error: " << my_std::atoi(t).second << std::endl;
    std::string c("test");
    std::cout << my_std::atoi(c).first << ", error: " << my_std::atoi(c).second << std::endl;
    std::string d("0");
    std::cout << my_std::atoi(d).first << ", error: " << my_std::atoi(d).second << std::endl;
  return 0;
}

