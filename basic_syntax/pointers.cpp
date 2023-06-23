//
//  pointers.cpp
//  design_patterns
//
//  Created by Mark Du on 2023-06-12.
//

//#include "pointers.hpp"
#include <iostream>

using  std::cout;
using  std::endl;

int main1111() {
    int x {7};
    int* ip=&x;
    int &y=x;
    
    cout << &x <<endl;
    
    cout << ip <<endl;
    cout << *ip <<endl;
    cout << &ip <<endl;
    cout << y <<endl;
    cout << &y <<endl;
    
    int z {73};
    ip=&z;// pointer ip point to value z
    
    cout << *ip <<endl;
    cout << &ip <<endl;
    
    *ip=55; //same as point to z, point to value 55
    cout << *ip <<endl;
    cout << &ip <<endl;
    return 0;
}

//int main() {
//    int x {7};
//    int y {42};
//    int* ip=&x;
//    y=*ip;
//
//    cout << &x <<endl;
//    cout << *ip <<endl;
//    cout << y <<endl;
//}
