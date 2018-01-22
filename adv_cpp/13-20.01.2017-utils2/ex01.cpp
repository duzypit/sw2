#include <iostream>
#include <functional>
#include <vector>
#include <algorithm>
/*
void free_fun(int a, char c){};
void free_fn2( const std::function<void(int, char)>& fn)
{ fn ( 10, 'a'); }

int main(int, char *[]) {
    std:elem:function<void(int, char)> fn{free_fun};
    free_fn2(fn);
    return 0*
 */

void callback(int i){
        std::cout << "callback " << i << std::endl;
}
//find bigger than int
void func(const std::vector<int>& v,int needle, const std::function<void(int)>& fn){
    //auto i = std::max_element(v.begin(), v.end());
    //if(i != v.end()) fn();i
    for(const auto& i : v){
        if(needle < i){
            fn(i);
        }
    }
}




int main(){
    std::vector<int> v{1,2,3,4,5};
    std::function<void(int)> fn(callback);
    func(v,4, fn);

}
