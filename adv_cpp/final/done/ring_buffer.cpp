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
#include <gtest/gtest.h>
#include <initializer_list>
#include <algorithm>
#include <string>
#include <array>

template<typename T, std::size_t N>
class CircularBuffer{
public:
    CircularBuffer(){
        _currentIndex = 0;
        _fill = 0;
    }

    CircularBuffer(const std::initializer_list<T>& list) {
        if(N < list.size()) throw std::out_of_range("To many args!");
        std::copy(list.begin(), list.end(), _data.begin());
        _currentIndex = list.size() -1;
        _fill = list.size();
    }

    const T& operator[](std::size_t index) const noexcept {
        return this -> _data[index];
    }

    void push(const T& t) noexcept {
        ++_fill;
        if (_currentIndex == _data.size()){
            _currentIndex = 0;
            if (_fill != _data.size()){
                _fill = _data.size();
            }
        }
        _data[_currentIndex] = t;
        _currentIndex++;
    }

    std::size_t size() noexcept {
        return _fill;
    }

	auto begin() noexcept {
		return _data.begin();
	}

	auto end() noexcept {
		return _data.end();
	}

friend std::ostream& operator<<(std::ostream& os, const CircularBuffer<T, N>& buffer) {
    for(const auto& v : buffer._data) {
        os << v;
   }
   return os;
}

private:
    std::size_t _fill;
    std::array<T, N> _data;
    std::size_t _currentIndex;
};

TEST(CircularBuffer, initializer_list){
	CircularBuffer<std::string, 5> buffer{{"one", "two", "three"}};

    EXPECT_EQ(buffer[2], std::string("three"));
}

TEST(CircularBuffer, initializer_list_exception){
    try {
        CircularBuffer<std::string, 2> buffer{{"one", "two", "three"}};
    } catch(std::out_of_range const& e){
        EXPECT_EQ(e.what(), std::string("To many args!"));
    }
}

TEST(CircularBuffer, std_fill){
	CircularBuffer<std::string, 5> buffer{{"one", "two", "three"}};
	std::fill(buffer.begin(), buffer.end(), std::string("seven"));

    EXPECT_EQ(buffer[2], std::string("seven"));
}
TEST(CircularBuffer, empty_size_is_zero) {
    CircularBuffer<std::string, 10> buffer;
    EXPECT_EQ(buffer[0].size(), 0);
}

TEST(CircularBuffer, stream_operator) {
    CircularBuffer<std::string, 2> buffer{{std::string{"one"}}};
    std::stringstream ss;
    ss << buffer;
    EXPECT_EQ(ss.str(), "one");
}

TEST(CircularBuffer, small_buffer) {
    CircularBuffer<std::string, 2> buffer;
    buffer.push("asd");
    buffer.push("asd");
    buffer.push("dd");
    buffer.push("bb");
    EXPECT_EQ(buffer[0], "dd");
    EXPECT_EQ(buffer[1], "bb");
}

TEST(CircularBuffer, size_after_double_push){
    CircularBuffer<std::string,3> buffer;
    buffer.push("aa");
    buffer.push("bb");
    EXPECT_EQ(buffer.size(),2);
    buffer.push("cc");
    buffer.push("dd");
    EXPECT_EQ(buffer[0],"dd");
    EXPECT_EQ(buffer.size(), 3);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
