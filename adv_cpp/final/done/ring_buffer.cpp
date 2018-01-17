/*
Napisać implementację RingBuffer:
RingBuffer - potrafi przechowywać maksymalnie N elementów
https://en.wikipedia.org/wiki/Circular_buffer
RingBuffer ma być kontenerem STL
ma wspierać range for oraz podstawowe algorytmy STL'a
nie ma gwaracji co do stanu iteratorów
jeżeli RB zostanie zaimplementowany jako adaptor - std::list ma zostać wyłączony z możliwości użycia
*/

#include <iostream>
//#include <gtest/gtest.h>
#include <initializer_list>
#include <algorithm>
#include <string>
#include <array>

template<typename T, std::size_t N>
class CircularBuffer{
public:
    CircularBuffer(){
        this->_currentIndex = 0;
        this->_fill = 0;
    }

    CircularBuffer(const std::initializer_list<T>& list) {
        if(N < list.size()) throw std::out_of_range("To many args!");

        std::copy(list.begin(), list.end(), this->_data.begin());
        this->_currentIndex = list.size() -1;
        this->_fill = list.size();
    }

    const T& operator[](std::size_t index) const {
        return this -> _data[index];
    }

    void push(const T& t) {
		this->updateFill();
        if (this->_currentIndex == this->_data.size()){
            this->_currentIndex = 0;
        }
        this->_data[_currentIndex] = t;
        this->_currentIndex++;
        this->updateFill();
    }

    std::size_t size(){
        return this->_fill;
    }

	auto begin(){
		return _data.begin();
	}

	auto end(){
		return _data.end();
	}

friend std::ostream& operator<<(std::ostream& os, const CircularBuffer<T, N>& buffer) {
    for(const auto& v : buffer._data) {
        os << v;
   }
   return os;
}

private:
    void updateFill(){
        if(this->_fill < this->_data.size()){
            this->_fill = _data.size();
			this->_currentIndex = this -> _fill;
        }
    }

    std::size_t _fill;
    std::array<T, N> _data;
    std::size_t _currentIndex;
};

int main(){
	CircularBuffer<std::string, 5> buffer{{"one", "two", "three"}};

	std::fill(buffer.begin(), buffer.end(), "seven");

	buffer.push("five");
	buffer.push("six");
	buffer.push("one");
	for(auto& v : buffer){
		std::cout << "buff val: " << v << std::endl;
	}

	return 0;
}
