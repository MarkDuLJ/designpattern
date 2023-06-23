//
//  constrain.cpp
//  design_patterns
//
//  Created by Mark Du on 2023-06-16.
//

#include <iostream>
#include <concepts>

using std::cout;
using std::endl;

template<typename T>
//generate type based on the compling pass s+"hi"
concept Str = requires(T s){
    s+"hi";
};
auto show (const Str auto s){
    return s;
}

template<typename T>
concept Num=std::integral<T> || std::floating_point<T>;

template<typename T>
//requires true => no constrian
requires Num<T>
T add42(const T& r){
    return r+42;
}


int main1123(){
    
//    auto a="0.8";
//    after add constrain, only int and float can work with add42 function
    auto a=0.8;
    cout<<"answer is "<<add42(a)<<endl;
    
    cout<<"string is "<<show(1)<<endl;
    
    return 0;
    
    
}
