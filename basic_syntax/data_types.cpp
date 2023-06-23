//
//  data_types.cpp
//  design_patterns
//
//  Created by Mark Du on 2023-06-12.

#include <iostream>

#include <stdio.h>
#include <typeinfo>
#include <vector>

using  std::cout;
using  std::endl;

int func(){
//    int x {5};
     static int x {5};
    return ++x;
}

int main6(){

    const size_t byte {8};
    float f {50.0};
    double  df {};
    long double  ldf {};
    
    df=0.1+0.1+0.1;

    cout<<sizeof(f)*byte<<endl;
    cout<<sizeof(df)*byte<<endl;
    cout<<sizeof(ldf)*byte<<endl;
    
    cout<<f<<endl;
    if(df==0.3)cout<<"TRUE"<<endl;
    
    auto str="this is a string";
    auto s=str;
    cout << typeid(s).name()<< endl;
    cout << typeid(str).name()<< endl;
    
     std::vector<int> vi {1,2,3,4,5};
//    with auto type
//    for(auto i=vi.begin();i != vi.end();++i){
    
//      without auto type
    for(std::vector<int>::iterator i =vi.begin(); i != vi.end(); ++i){
        cout <<*i<< endl;
        cout <<&i<< endl;
        
    }
    
//    qualifiers
    cout<< func()<<endl;
    cout<< func()<<endl;
    cout<< func()<<endl;
    cout<< func()<<endl;
    
    return  0;
}
