cmake_minimum_required(VERSION 3.5.1)
set(CMAKE_CXX_STANDARD 14)
project(final)
add_definitions(-std=c++14 -Wall -Wextra -g)
set(PROJECT_SOURCE_DIR done)
find_package (Threads REQUIRED)

add_executable(matrix ${PROJECT_SOURCE_DIR}/matrix.cpp)
target_link_libraries(matrix gtest pthread )


add_executable(ring_buffer ${PROJECT_SOURCE_DIR}/ring_buffer.cpp)
target_link_libraries(ring_buffer gtest pthread)

add_executable(prime_numbers ${PROJECT_SOURCE_DIR}/prime_numbers.cpp)
target_link_libraries(prime_numbers pthread gmp)

add_executable(ptr_shared ${PROJECT_SOURCE_DIR}/ptr_shared.cpp)
#target_link_libraries(ptr_shared pthread)
