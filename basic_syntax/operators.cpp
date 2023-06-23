//
//  operators.cpp
//  design_patterns
//
//  Created by Mark Du on 2023-06-13.
//

//#include <stdio.h>
#include <iostream>
#include <cstdint>

using std::cout;
using std::endl;

using int_type=std::uint8_t;

void printp(const int_type* p){
    cout<< static_cast<const void*>(p)<<endl;
    cout<<"there"<< *p<<endl;
}

int findPrime(int i){
    bool res=true;
    for(int j=2;j<i;++j){
        if(i%j==0) {
            res=false;
            break;
        }
    }
    return res?i:0;
}

int main5(){
    int_type arr[]{1,2,3,4,5};
    int_type* p=arr;
    
    printp(p++);
    printp(p++);
 
    printp(p++);
    printp(p++);
    
    int i;
    for(i=2;i<100;i++){
        cout<<findPrime(i)<<endl;
    }

    return 0;
    
}
