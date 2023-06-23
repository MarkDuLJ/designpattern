//
//  var_class.cpp
//  design_patterns
//
//  Created by Mark Du on 2023-06-20.
//

#include <iostream>
#include <string_view>
#include <vector>
#include <variant>

using std::cout;
using std::endl;
using std::string_view;

//constexpr auto newline=[]{cout<<'\n';};

class Animal {
    string_view _name{};
    string_view _sound{};
public:
    Animal()=delete;
    Animal(string_view n, string_view s): _name{n},_sound{s}{}
    
    void speak() const{
        cout<<_name<<" speak: "<<_sound<<endl;
    }
    
    void sound(string_view s) {
        _sound = s;
    }
};

class Cat :public Animal {
public:
    Cat(string_view n): Animal(n, "meow") {}
};

class Dog :public Animal {
public:
    Dog(string_view n): Animal(n, "warf!") {}
};

struct animal_speak {
    void operator () (const Cat& c) const {c.speak();}
    void operator () (const Dog& d) const {d.speak();}
};

int main22(){
    
//    Cat c{"woho"};
//    c.speak();
//
    
    using v_animal = std::variant<Cat, Dog>;
    std::vector<v_animal> pets {Cat{"lowki"}, Dog{"puppy"}, Cat{"cindy"}};
    
    for(const v_animal& a:pets){
        auto idx= a.index();
        if(idx==0) get<Cat>(a).speak();
        if(idx==1) get<Dog>(a).speak();
    }
    
    // get_if method
    for(const v_animal& a:pets){
        if(const auto& o= get_if<Cat>(&a); o) o->speak();
        if(const auto& o= get_if<Dog>(&a); o) o->speak();
    }
    
    //visit method
    for(const v_animal& a:pets){
        std::visit(animal_speak{}, a);
    }
    
    return 0;
}
