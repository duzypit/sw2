#include <iostream>
#include <memory>
#include <vector>
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

void f() {
    vector<shared_ptr<Animal>> v;
    v.push_back(make_shared<Animal>());
    v.push_back(make_shared<Cat>());

    for(const auto e : v){
        e->eat();
    }
}

int main(){
    f();    
}