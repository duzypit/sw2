#include <algorithm>
#include <iostream>
#include <iterator>
#include <vector>
#include <chrono>
#include <ctime>

int main()
{
    std::vector<int> v = {3,4,5,6,7,8,1,2,9,10,11,12};
    std::vector<int> x(v);
    std::sort(v.begin(), v.end());
    std::sort(x.begin(), x.end());

    auto start = std::chrono::system_clock::now();
    auto it = std::stable_partition(v.begin(), v.end(), [](int i){return i % 2 == 0;});
//    std::cout << v[0] <<  " i " << *it << std::endl;
//    for(auto &i : v) {std::cout << i << " "; }
//    std::cout << std::endl;
    auto end = std::chrono::system_clock::now();
    std::chrono::duration<double> elapsed_seconds = end-start;
    std::time_t end_time = std::chrono::system_clock::to_time_t(end);

    std::cout << "finished computation at " << std::ctime(&end_time)
              << "elapsed time: " << elapsed_seconds.count() << "s\n";

    auto elem = std::min_element(x.begin(), x.end());


    auto it2 = std::partition(x.begin(), x.end(), [](int i){return i % 2 == 0;});
    std::cout << x[0] <<  " i " << *it2 << std::endl;
    for(auto &i : x) {std::cout << i << " "; }
    std::cout << std::endl;

}

