//
//  absfactory.cpp
//  design_patterns
//
//  Created by Mark Du on 2023-06-23.
//

#include <iostream>
#include <string>

using namespace std;

class Iuser{
public:
    virtual void insert()=0;
    virtual void getUser()=0;
};

class ServerUser : public Iuser{
public:
    virtual void insert(){
        cout<<"insert user into database"<<endl;
    };
    virtual void getUser(){
        cout<<"Get user info from server"<<endl;
    };
};

class MysqlUser : public Iuser{
public:
    virtual void insert(){
        cout<<"create user in mysql"<<endl;
    };
    virtual void getUser(){
        cout<<"Get user info from mysql"<<endl;
    };
};

class Idepartment {
public:
    virtual void insert()=0;
    virtual void getDepartment()=0;
};

class FrontDep : public Idepartment{
public:
    virtual void insert(){
        cout<<"insert front end department into database"<<endl;
    };
    virtual void getDepartment(){
        cout<<"Get front end info from database"<<endl;
    };
};

class BackDep : public Idepartment{
public:
    virtual void insert(){
        cout<<"insert back end department into database"<<endl;
    };
    virtual void getDepartment(){
        cout<<"Get back end info from database"<<endl;
    };
};


//abstract factory
class Factory{
public:
    virtual Iuser* createUser()=0;
    virtual Idepartment* createDepartment()=0;
};

class ServerFactory : public Factory{
    virtual Iuser* createUser(){
        return  new ServerUser();
    }
    virtual Idepartment* createDepartment(){
        return new BackDep();
    }
};

class FrontFactory : public Factory{
    virtual Iuser* createUser(){
        return  new MysqlUser();
    }
    virtual Idepartment* createDepartment(){
        return new FrontDep();
    }
};


int mainafs(){
    Factory* af;
    FrontFactory ff;
    af=&ff;
   
    Iuser* user= af->createUser();
    Idepartment* dep=af->createDepartment();
    
    user->getUser();
    dep->getDepartment();
    
    return 0;
}
