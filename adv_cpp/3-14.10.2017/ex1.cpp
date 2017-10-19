//http://slides.com/uczelnia_bt_kw/advanced-c#/2/6

// excercise
// Simple String template:
// works! // can store values - letters
// has operator+=
// has operator==
// can be constructed from const char* and std::string
// has copy ctor
#include <iostream>
#include <vector>

//https://stackoverflow.com/questions/34593263/c-overloading-operator

// template<std::size_t s, typename t, bool use_heap>
// class Array{
// public:
// 	Array(std::size_t s, t type, bool){
// 		if(stdarray){
// 			std::array<s, 
// 		}
// 	};


// private:
// 	std::array<s, T> _array;
// 	std::vector<T> _vector;
// };




// class example
template<class Char>
class String{
public:
	String() {

	};

	String(const char* text){
		std::string temp = text;
		this->fill_vec_with_data(text);
	}

	String(const std::string text){
		this->fill_vec_with_data(text);
	}

	Char& operator[](int n){
		return this->data[n];
	}

	String& operator+=(Char c){

	}

	String& print_data(){
		for(char c : this->data){
			std::cout << c << " ";
			
		}	
		std::cout << std::endl;	

		return *this;
	}

	template<typename OtherChar>
	String& operator+(const String<OtherChar>&){

	}

private:
	void fill_vec_with_data(const std::string text){
		for(char c : text){
			this -> data.push_back(c);
		}
	}


	std::vector<Char> data;
};

int main(void){

	
	const char* testdata = "the quick brown fox jumps over the lazy dog.";
	String<char> st(testdata);
	st.print_data();
	std::cout << st[1] << std::endl;

    return 0;
}