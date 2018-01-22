#include <iostream>


int main(int argc, char *argv[]){
    if(argc > 1){
        std::istream i(argv[1]);
        std::string s;
        i >> s;
        std::cout << s << std::endl;
    }
}
