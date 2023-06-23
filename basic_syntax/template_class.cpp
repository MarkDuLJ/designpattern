//
//  template_class.cpp
//  design_patterns
//
//  Created by Mark Du on 2023-06-15.
//

#include <stdio.h>
#include <iostream>
#include <string>
#include <memory>
#include <exception>

using std::cout;
using std::endl;
using std::string;


namespace bw {

//simple exception class
class S_err : public std::exception{
    const char * msg;
public:
    S_err()=delete; // no default constructor
    explicit S_err(const char * s) noexcept: msg(s) {}
    const char * what() const noexcept {return msg;}
};

//---simple fixed-size LIFO stack template---
template <typename T>
class Stack {
    static const int default_size {10};
    static const int max_size {1000};
    int S_size {};
    int S_top {};
    std::unique_ptr<T[]> S_prt {};
public:
    explicit Stack(int s= default_size);
    ~Stack(){if(S_prt) S_prt.release();}
    T& push(const T&);
    T& pop();
    bool is_empty() const {return S_top < 0;}
    bool is_full() const {return S_top >= S_size - 1;}
    int top() const {return S_top;}
    int size() const {return S_size;}
};

// stack<T> constructor
template<typename T>
Stack<T>::Stack(int s){
    if(s > max_size || s<1) throw S_err("invalid stack size");
    else S_size=s;
    S_prt.reset(new T[S_size]);
    S_top = -1;
}

template<typename T>
T& Stack<T>::push(const T& i){
    if(is_full()) throw  S_err("full stack");
    return  S_prt[++S_top]=i;
}

template<typename T>
T& Stack<T>::pop( ){
    if(is_empty()) throw  S_err("empty stack");
    return  S_prt[S_top--];
}

} // namespace bw


int main12(){
    bw::Stack<int> s{5};
    
    auto full=s.is_full()? "full" : "not  ";
    for (int i:{1,2,3,4,5}) {
        cout<<"pushing... "<<i<<endl;
        s.push(i);
        cout<<s.size()<<"empty? "<< full<<"current: "<<s.top()<<endl;
    }
    cout<<"full? "<< full<<"current: "<<s.top()<<endl;
    
    while (!s.is_empty()) {
        cout<<"s is popping"<<s.pop()<<endl;
        cout<<s.size()<<"empty? "<< full<<"current: "<<s.top()<<endl;
    }
    
    bw::Stack<string> ss;
    cout<<ss.size()<<"empty? "<<ss.is_full()<<"current: "<<ss.top()<<endl;
    
    return 0;
}
