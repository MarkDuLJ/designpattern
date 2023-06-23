//
//  abstractfactory.cpp
//  design_patterns
//
//  Created by Mark Du on 2023-06-22.
//

#include <iostream>

using namespace std;


//create different door for different cars
class Door{
public:
    Door(){}
    virtual void open()=0;
};

class SedanDoor : public Door{
public:
    SedanDoor(){
        cout<<"Making a sedan door..."<<endl;
    }
    void open (){
        cout<<"biu biu"<<endl;
    }
};

class TruckDoor : public Door{
public:
    TruckDoor(){
        cout<<"Making a truck door..."<<endl;
    }
    void open (){
        cout<<"bom bom"<<endl;
    }
};


//create different engine for different cars
class Engine{
public:
    Engine(){}
    virtual void Run()=0;
};

class SedanEngine : public Engine{
public:
    SedanEngine(){
        cout<<"Making a sedan engine"<<endl;
    }
    void  Run() {
        cout<<"woom woom..."<<endl;
    }
};

class TruckEngine : public Engine{
public:
    TruckEngine(){
        cout<<"Making a truck engine"<<endl;
    }
    void  Run() {
        cout<<"vroom vroom..."<<endl;
    }
};


//---implention abstract factory pattern---
class CarFactory{
public:
    virtual Door * BuildDoor()=0;
    virtual Engine * BuildEngine()=0;
};

class SedanFactory : public CarFactory{
public:
    Door* BuildDoor(){
        return new SedanDoor();
    }
    
    Engine* BuildEngine(){
        return new SedanEngine();
    }
};

class TruckFactory : public CarFactory{
public:
    Door* BuildDoor(){
        return new TruckDoor();
    }
    
    Engine* BuildEngine(){
        return new TruckEngine();
    }
};


int mainaf(){
    CarFactory* carplant;
    int choice{0};
    
    cout<<"select a car type: "<<endl;
    cout<<"1: Sedan"<<endl;
    cout<<"2: Truck"<<endl;
    cout<<"selection ";
    cin>>choice;
    
    switch (choice) {
        case 1:
            carplant= new SedanFactory;
            break;
            
        case 2:
            carplant= new TruckFactory;
            break;
            
        default:
            cout<<"invalid selection..."<<endl;
            carplant=NULL;
            break;
    }
    if(carplant){
        Door* mydoor=   carplant->BuildDoor();
        Engine* myengine= carplant->BuildEngine();
        mydoor->open();
        myengine->Run();
    }
    
    return 0;
}
