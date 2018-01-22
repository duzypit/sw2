#include <iostream>
#include <string>
#include <algorithm>
#include <chrono>
#include <ctime>


int main(){
    std::string s = "aqwertyui";
    std::sort(s.begin(), s.end());
    auto start = std::chrono::system_clock::now();
    do {
        std::cout << s << '\n';
    } while(std::next_permutation(s.begin(), s.end()));
     auto end = std::chrono::system_clock::now();

    std::chrono::duration<double> elapsed_seconds = end-start;
    std::time_t end_time = std::chrono::system_clock::to_time_t(end);

    std::cout << "finished computation at " << std::ctime(&end_time)
              << "elapsed time: " << elapsed_seconds.count() << "s\n";
}
