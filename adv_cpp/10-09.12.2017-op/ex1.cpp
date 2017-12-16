#include <cstring>
#include <iostream>

class C {
public:
    C(char* text) {
        table = new char[strlen(text) + 1];
        strcpy(table, text);
    }
    ~C() {
        //error without []
        delete[] table;
    }

//assignment op
    C& operator=(const C& smtn) noexcept{
        if(this != &smtn){
            delete[] table;
            table = new char[strlen(smtn.table)+1];
            std::copy(smtn.table, smtn.table + strlen(smtn.table)+1, table);
        }

        return *this;
    }

    char* getStr() {
        return table;
    }

private:
    char* table;
};


int main(){
    C myChar("text");
    C myNextChar("text222");
    myChar = myNextChar;
    std::cout << myChar.getStr() << std::endl;
}