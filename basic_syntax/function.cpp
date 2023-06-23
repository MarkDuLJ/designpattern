//
//  function.cpp
//  design_patterns
//
//  Created by Mark Du on 2023-06-13.
//

#include <stdio.h>
#include <iostream>

using std::cout;
using std::endl;

//call by pointer
void funcp(int* p){
    ++*p;
}

//call by reference
void func(int& r){
    ++ r;
}

const int factorial(int n){
    if(n<2) return 1;
    return n*factorial(n-1);
}

const int factor(int n){
    if(n<2) return 1;
    auto re=1;
    for(auto i=2;i<n+1;++i){
        re=re*i;
    }
    return re;
}

int main3(){
    int a {8};
    //call by pointer
    funcp(&a);
    //call by reference
    func(a);
    
    cout<<a<<endl;
    
    auto r=factor(5);
    cout<<r<<endl;
    
    return 0;
}
