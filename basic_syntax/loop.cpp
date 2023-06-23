//
//  loop.cpp
//  design_patterns
//
//  Created by Mark Du on 2023-06-12.
//

//#include "loop.hpp"
#include <iostream>

using std::cout;
using std::endl;

int main1(){
    int array[] {1,2,3,4,5};
    int i {0};
    
    while(i<5){
        std::cout << i<< endl;
        std::cout << array[i] << endl;
//        ++i;
        i++;
        
    }
    
    for(int j {0};j<5;j++){
        cout<<"j is "<<j<<" array vlue is "<<array[j]<<endl;
    }
    
    // for string, because all string are numbers, use string[i] as condition
    const char string[]{"hello world"};
    for(int j {0};string[j];j++){
        cout<<"j is "<<j<<" string vlue is "<<string[j]<<endl;
    }
    
    //use pointer
    for(auto * p=string;*p;p++){
        cout<<"j is "<<&p<<" string vlue is "<<*p<<endl;
    }
    
//    range based loop
    for(const auto e:array){
        cout<<"this is value from array: "<<e<<endl;
    }
    
    return  0;
}
