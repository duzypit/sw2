#include <iostream>

class MyExceptionBase {};
class MyExceptionDerived: public MyExceptionBase {};

void f(MyExceptionBase& e) {
    // ...
    throw e;
}

void g() {
    MyExceptionDerived e;
    try {
        f(e);
    } catch (MyExceptionDerived& e) {
        // ...code to handle MyExceptionDerived...
        std::cout << 1 << std::endl;
    } catch (...) {
        // ...code to handle other exceptions...
        std::cout << 2 << std::endl;

    }
}

int main(){
	g();
	return 0;
}

