//
//  optional_class.cpp
//  design_patterns
//
//  Created by Mark Du on 2023-06-16.
//

#include <iostream>
#include <optional>

using std::cout;
using std::endl;
using std::optional;


//use std::optional replace struct

//struct return_status {
//    long value;
//    bool has_value;
//};

optional<long> factor(long n){
//    return_status rs {0,false};//no struct needed with optional
    for(long i=2; i<= n/2; ++i){
        if( n % i ==0){
//            rs.value=i;
//            rs.has_value=true;
//            cout<<rs.value<<endl;
//            return here get lowest value
            return i;
        }
    }
    return {};
}

int main44(){
    long a{42};
    auto x =factor(a);
    
//    if(x.has_value()) cout<<"hooray"<<x.value()<<endl;
//    above same as below
    if(x) cout<<"hooray"<<*x<<endl;
    else cout <<"aha.. it's prime"<<endl;
    return 0;
}
