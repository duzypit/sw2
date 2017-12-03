#include <iostream>
#include <memory>

using namespace std;

class Animal {
public:
    virtual void eat() const noexcept {
        cout << "I'm eating generic food." << endl;
    }
};

class Cat: public Animal {
public:
    virtual void eat() const noexcept {
        cout << "I'm eating a rat." << endl;
    }
};

class HomeCat: public Cat{
public:
	virtual void eat() const noexcept{
		Cat::eat();
		cout << "I'm eating Pedegree Pal today." << endl;
	}

};

void f(){
	shared_ptr<Animal> a {make_shared<HomeCat>()};
	a->eat();
}

int main(){
	//unique_ptr<Animal> a { make_unique<HomeCat>() };
	/*
	HomeCat c;
	cout << "Cat is going to kitchen ;)" << endl;
 	a.eat();
 	*/
 	f();
}