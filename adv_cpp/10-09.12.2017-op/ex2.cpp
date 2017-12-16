#include <cstring>
#include <iostream>
//tworzymy obiekt - konstruktor kopiujacy
//juz stworzony - kopiujemy z innego obiektu mv
template <typename T>
class C {
public:
    C(T* data, size_t size) {
        s = size;
        table = new T[size];
        std::copy(data, data + size, table);
    }
    ~C() {
        delete [] table;
    }

   C& operator=(const C& smtn) noexcept{
        if(this != &smtn){
            delete[] table;
            table = new T[smtn.s];
            std::copy(smtn.table, smtn.table + smtn.s, table);
        }

        return *this;
    }

    //move
    C& operator=(C&& smtn) noexcept {
        if (this != &smtn) {
            delete[] table;
            table = new T[smtn.s];
            std::copy(smtn.table, smtn.table + smtn.s, table);
        }
        return *this;
    }

    T* getTable() {
        return table;
    }

private:
    size_t s; //ize of table
    T* table;
};

int main(){
    char* source = new char[strlen("frytki")+1];
    memcpy(source,"frytki", 7);
    char* source2 = new char[strlen("abecadlo")+1];
    memcpy(source2, "abecadlo", 9);
    C<char> myChar(source, 7);

   // C<char> myNextChar(source2, 9);
    //myChar = myNextChar;
    //std::cout<< myChar.getTable() << std::endl;

    C<char> myMoveChar(source2,9); 
    myMoveChar = std::move(myChar);
    std::cout<< myMoveChar.getTable() << std::endl;
}