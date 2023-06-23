//
//  operator_overload.cpp
//  design_patterns
//
//  Created by Mark Du on 2023-06-14.
//

#include <stdio.h>
#include <iostream>
#include <string>


using std::cout;
using std::endl;
using std::string;


const string nostr {"denominator can't be zero"};

class Rational {
    int n {0};
    int d {1};
    
public:
    Rational(int numerator=0, int denominator=1):n(numerator),d(denominator){}
    Rational(const Rational & r):n(r.n),d(r.d){}// copy constructor
    ~Rational();
    int numerator() const {return n;};
    int denominator() const {return d;};
    Rational reduce() const;//reduce fraction
    string str() const;//return a formatted stl string
    string raw_str() const;//return a non-reduced stl string
    Rational & operator=(const Rational&); //assignment
    Rational operator + (const Rational&) const;
    Rational operator - (const Rational&) const;
    Rational operator * (const Rational&) const;
    Rational operator / (const Rational&) const;
};

//----implemetion----------
Rational Rational::reduce() const {
    if(n==0||d<=3) return *this;
    for(auto div=d-1;div;--div){
        if(n%div==0 && d%div==0){
            return Rational(n/div,d/div);
        }
    }
    return *this;
}

string Rational::str() const {
    if(d==0) return nostr;
    if(d==1 || n==0) return std::to_string(n);
    
    auto abs_n=std::abs(n);   //absolute value
    if(abs_n>d){
        auto whole=n/d;
        auto reminder=n%d;
        if(reminder) return std::to_string(whole) +" "+ Rational(reminder,d).str();
        else return std::to_string(whole);
        
    }else{
        return reduce().raw_str();
    }
}

string Rational::raw_str() const {
    return  std::to_string(n) + "/" + std::to_string(d);
}

Rational & Rational::operator = (const Rational& r) {
    if(this != &r){
        n=r.numerator();
        d=r.denominator();
    }
    return *this;
}

Rational Rational::operator + (const Rational& r) const{
    return  Rational(n*r.d+d*r.n,d*r.d);
}

Rational Rational::operator - (const Rational& r) const{
    return  Rational(n*r.d-d*r.n,d*r.d);
}

Rational Rational::operator * (const Rational& r) const{
    return  Rational(n*r.n,d*r.d);
}

Rational Rational::operator / (const Rational& r) const{
    return  Rational(n*r.d,d*r.n);
}

Rational::~Rational(){
    cout<<"destructor, reset default values..."<<endl;
    n=0;d=1;
}


int main11(){
    cout<<"hee"<<endl;
    
    Rational a(3,7);
    cout<<"formatted: "<<a.str()<<endl<<" raw data: "<<a.raw_str()<<endl;
    
    Rational b(24,16);
    cout<<"formatted: "<<b.str()<<endl<<" raw data: "<<b.raw_str()<<endl;
    
    auto c=b; //copy constructor
    cout<<"formatted: "<<c.str()<<endl<<" raw data: "<<c.raw_str()<<endl;
    
    Rational d; //default constructor
    cout<<d.str()<<endl;
    
    d=c; //assignment operator =
    cout<<d.str()<<endl<<" raw data: "<<d.raw_str()<<endl;
    
    auto& e=d; //reference d to e
    d=e;       //assignment to self
    cout<<e.str()<<endl<<" raw data: "<<e.raw_str()<<endl;
    cout<<d.str()<<endl<<" raw data: "<<d.raw_str()<<endl;
    
    cout<<(a+b).str()<<endl;
    cout<<(a-b).str()<<endl;
    
    cout<<"end of main()"<<endl;
    
    return 0;
}
