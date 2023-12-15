/* need c++23;

Author: gamefunc:
website: https://www.gamefunc.top:9029
github: https://github.com/gamefunc
qq: 32686647
weixin: gamefunc
mail: fevefun@hotmail.com  

MIT;  */

#include <ranges>
#include <iostream>

// from "cppcoro":
#include "generator.hpp"


inline
cppcoro::generator<int64_t> 
range(int64_t start, int64_t end,  int64_t step = 1){
    if(start < end){
        if(step > 0){ 
            for(int64_t i: std::views::iota(start, end)
                | std::views::stride(step) ){
                    co_yield i;
            }// for in range(start, end, step);
        }// if(step > 0) ;
    }else{// start > end:
        if(step < 0){ 
            step *= -1;
            for(int64_t i: std::views::iota(end + 1, start + 1) 
                | std::views::reverse
                | std::views::stride(step) ){
                    co_yield i;
            }// for in range(end, start, step);
        }// if(step < 0) ;
    }// if else start end ;
}// range()



inline
cppcoro::generator<int64_t> 
range(int64_t end){
    for(auto i : range(0, end, 1)){ co_yield i; }
}// range()重载;



int main(){
    for(auto i : range(10)){
        std::cout << i << ", ";
    }// for(auto i : range(10));

    std::cout << "\n\n";

    for(auto i : range(10, 1, -3)){
        std::cout << i << ", ";
    }// for(auto i : range(10, 1, -3));

    return 0;
}// main()