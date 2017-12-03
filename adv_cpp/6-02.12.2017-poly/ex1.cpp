#include <iostream>
#include <memory>
#include <vector>

using namespace std;
/*
    with class hierarchy
    objects are created by a factory function depends on user input
    collect objects at a container
    call a function special for a class of a object
    print out properties of all elements
*/

class Animal {
public:
    virtual void eat() const noexcept =0;
    virtual ~Animal() {
        cout << "- Destructing an animal" << endl;
    }
};

class Cat: public Animal {
public:
    virtual void eat() const noexcept override {
        cout << "Cat: I'm a cat and eating a rat." << endl;
    }

    void purr() const noexcept {
    	cout << "Cat: Purr! I'm a Cat!" << endl;
    }

    virtual ~Cat() {
        cout << "- Cat has left the party" << endl;
    }
};

class HouseCat: public Cat {
public:
	virtual void eat() const noexcept override{
		cout << "HouseCat: I'm a HouseCat and i'm eating Pedegree" << endl;
	}

	void meow() const noexcept{
		cout << "HouseCat: Meow! I'm HouseCat" << endl;
	}

	virtual ~HouseCat() {
		cout << "- HouseCat has left the party" << endl;
	}
};

enum class AnimalType{
	Cat, HouseCat
};

shared_ptr<Animal> create(AnimalType type){
	switch(type){
		case AnimalType::Cat:
			return make_shared<Cat>();
		case AnimalType::HouseCat:
			return make_shared<HouseCat>();
		default:
			return make_shared<Cat>();
	}
}

void action(const vector<shared_ptr<Animal>>& animals) {
    for (const auto a : animals) {
        a->eat();
		try {
            HouseCat& d = dynamic_cast<HouseCat&>(*a);

            d.meow();
        } catch (exception& e) {
            cout << "Exception: " << e.what() << endl;

        }    

        try{
        	Cat& d = dynamic_cast<Cat&>(*a);
        	d.purr();
        }  catch (exception& e) {
            cout << "Exception: " << e.what() << endl;

        }    
    }
}

int main(){
	vector<shared_ptr<Animal>> v;
    v.push_back(create(AnimalType::HouseCat));
    v.push_back(create(AnimalType::Cat));

    action(v);
}

