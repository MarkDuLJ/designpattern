//
//  factory.cpp
//  design_patterns
//
//  Created by Mark Du on 2023-06-22.
//

#include <iostream>

using namespace std;

class Coffee{
protected:
    char _type[15];
public:
    Coffee(){}
    char *getType(){return _type;}
};

//concrete class to do the real creation job
class Espresso : public Coffee{
public:
    Espresso() : Coffee() {
        strcpy(_type, "Espresso");
        cout<<endl<<"Making Espresso...."<<endl;
        cout<<"doing something to get a cup of espresso..."<<endl;
        cout<<"grinding bean..."<<endl;
        cout<<"brewing..."<<endl;
    }
};

class Cappuccino : public Coffee{
public:
    Cappuccino() : Coffee() {
        strcpy(_type, "Cappuccino");
        cout<<endl<<"Making Cappuccino...."<<endl;
        cout<<"grinding bean..."<<endl;
        cout<<"brewing..."<<endl;
        cout<<"heating and foaming milk..."<<endl;
    }
};

class Latte : public Coffee{
public:
    Latte() : Coffee() {
        strcpy(_type, "Latte");
        cout<<endl<<"Making Latte...."<<endl;
        cout<<"doing something to get a cup of Latte..."<<endl;
    }
};

//creator class
class CoffeeMaker {
private:
    Coffee * _coffee;
public:
    Coffee * GetCoffee(){
        int choice;
        cout<<"select coffer type: "<<endl;
        cout<<"1: Espresso "<<endl;
        cout<<"2: Cappuccino "<<endl;
        cout<<"3: Latte "<<endl;
        cout<<"Selection: "<<endl;
        cin >> choice;
        
        switch (choice) {
            case 1:
                return new Espresso;
            case 2:
                return new Cappuccino;
            case 3:
                return new Latte;
                
            default:
                cout<<"not the right choice"<<endl;
                return NULL;
        }
    }
};

class Computer {
public:
    virtual void price()=0;
    virtual void description()=0;
    virtual ~Computer(){};
};

class Laptop: public Computer{
public:
    void price(){
        cout<<"$3000"<<endl;
    }
    
    void description(){
        cout<<"portable computer"<<endl;
    }
    virtual ~Laptop(){};
};

class Desktop: public Computer{
public:
    void price(){
        cout<<"$1500"<<endl;
    }
    
    void description(){
        cout<<"better to put on a desk"<<endl;
    }
    virtual ~Desktop(){};
};

class ComputerFactory {
public:
    static Computer *NewC(const string &type){
        if(type=="laptop") return  new Laptop;
        if(type=="pc") return  new Desktop;
        return  NULL;
    }
};


int mainfa (){
//    CoffeeMaker machine;
//    Coffee * cup;
//
//    cup=machine.GetCoffee();
//    cout<<endl<<cup->getType()<<" is ready."<<endl;
    
    ComputerFactory cf;
    Computer *c;//
    c=cf.NewC("laptop");
//    Computer *c = ComputerFactory::NewC("pc");
    c->price();
    c->description();
    delete c;
    
    return 0;
}
