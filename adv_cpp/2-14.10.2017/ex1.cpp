//raii
//smart pointery


#include <iostream>
using namespace std;


class MyProblem: public exception
{
public:
	MyProblem() : exception(){};
	
	virtual const char* what() const _GLIBCXX_USE_NOEXCEPT {
		return "this is a serious poroblem!";
	};
	
	const char* PrintMe(){return "can be handled in here";};
	
	// ~MyProblem();
	
};

void f(){
	throw MyProblem();
}

int main(){ 
	try {
		f();
	} 
	// catch (exception& e){
	// 	std::cout << e.what() << std::endl;
	// }
	// catch(exception& e){
	// 	std::cout << e.what() << std::endl;
	// 	std::cout << e.PrintMe() << std::endl;
	// }

	catch(MyProblem& e){
		std::cout << e.what() << std::endl;
		std::cout << e.PrintMe() << std::endl;
	}	
	return 0;
}