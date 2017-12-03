#include <iostream>
#include <set>
/*excercise

Implement a simple dictionary:

    has a set of predefined words
    case insensitive

struct Dictionary {
  void addWord(string); noexcept
  void removeWord(string);
  bool check(string) const noexcept;
};

set lub unordered set
*/

struct Dictionary{
	void addWord(std::string s){
		//insert nie dokłada jeśli słowo istnieje
			this->_data.insert(s);
		
	} //noexcept
  	void removeWord(std::string s){
  		//nie trzeba spawdzac czy jest w secie, jesli nie ma funkcja zwraca 0
  			this->_data.erase(s);
  	}

  	bool check(std::string s) const noexcept{
  		return this->_data.find(s);
  		/*for (auto &v : this -> _data){
  			if (v == s) {
  				return true;
  			}
  		}

  		return false;*
  	}

private:
	std::set<std::string> _data;
};

int main(){
	Dictionary d;
	d.addWord("test");
	d.addWord("test1");
	d.addWord("Test2");
	std::cout << (d.check("test") ? "jest" : "nie ma") << std::endl;
	return 0;
}