//
//  functor.cpp
//  design_patterns
//
//  Created by Mark Du on 2023-06-15.
//

#include <iostream>

using std::cout;
using std::endl;


class MultBy {
    int mult {};
public:
    MultBy (int n=1):mult(n) {}
    int operator () (int n) const {return mult*n;}
};

int main113 (){
    const MultBy time4(4);
    const MultBy time10(10);
//    same as using lamba funtion
    const auto time15=[](int n){return n*15;};
    
    
    cout<<time4(6)<<endl;
    cout<<time10(8)<<endl;
    cout<<time15(3)<<endl;
    
    return  0;
}
