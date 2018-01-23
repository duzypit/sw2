/*
Inteligentny wskaźnik
Napisz swoją implementację wskaźnika:
z licznikiem referencji
szablon
kopiowanie + przenposzenie
blok kontrolny
brak weak_ptr
operatory * -> == != < <= > >=
void swap(?, ?)
funkcja get()
*/
#include <iostream>

template<typename T>
class ptr_shared{
    public:
    ptr_shared() : {}


    //copy constructible

    //copy assignable


    private:
    T _ptr;
    std::size_t _refCount = 0;
};


int main()
{
    ptr_shared<int> t;
}
