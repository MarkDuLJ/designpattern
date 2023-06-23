//
//  class_obj.cpp
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

const string unk {"unknown"};
const string clone_prefix {"prefix-"};

class Animal{
    string a_name;
    string a_type;
    string a_sound;
    
public:
    Animal();//default constructor
    Animal(const string& name,const string& type,const string& sound);//para constructor
    Animal(const Animal&); //copy constructor
    ~Animal();//destructor
    Animal& operator=(const Animal&);//copy/assignment operator
    
    void print() const;
    
    
};

//-----implementation------
Animal::Animal():a_name(unk),a_type(unk),a_sound(unk){
    cout<<"this is default constructor\n"<<endl;
};

Animal::Animal(const string& name,const string& type,const string& sound):a_name(name),a_type(type),a_sound(sound){
    cout<<"this is constructor with parameters  "<<a_name<<a_type<<a_sound<<endl;
};

Animal::Animal(const Animal& a){
    cout<<"this is a copy constructor  "<<endl;
    a_name=clone_prefix  + a.a_name;
    a_type=a.a_type;
    a_sound=a.a_sound;
};


Animal::~Animal(){
    cout<<"destructor"<<endl;
}

Animal& Animal::operator=(const Animal& a){
    cout<<"this is copy/assignment constructor"<<endl;
    if(this != &a){
        a_name=clone_prefix  + a.a_name;
        a_type=a.a_type;
        a_sound=a.a_sound;
    }
    return *this;
}

void Animal::print() const {
    cout<<"this is print"<<a_name<<a_type<<a_sound<<endl;
    
}


int main2(){
    Animal a;
    a.print();
    
    const Animal b {"bob","dog","wowwow..."};
    b.print();
    
    const Animal c =b;
    c.print();
    
    a=c;
    a.print();
    
    cout<<"this is end of main()"<<endl;
    return 0;
    
}
