//
//  fs.cpp
//  design_patterns
//
//  Created by Mark Du on 2023-06-21.
//

#include <iostream>
using namespace std;

class Background{
public:
    Background();
};

class DarkBg : public Background{
public:
    DarkBg() : Background(){
        cout<<"dark background"<<endl;
    }
};

class LightBg : public Background{
public:
    LightBg() : Background(){
        cout<<"light background"<<endl;
    }
};

class ThemeCreator {
public:
    ThemeCreator() {};
    virtual void createBackground()=0;
    virtual void createDefaultText()=0;
    virtual void createGreenText()=0;
};

class DarkFactory : public ThemeCreator{
public:
    void createBackground(){
        cout<<"dark background factory creating..."<<endl;
    }
    void createDefaultText(){
        cout<<"dark background factory creating..."<<endl;
    }
    void createGreenText(){
        cout<<"dark background factory creating..."<<endl;
    }
};


class LightFactory : public ThemeCreator{
public:
    void createBackground(){
        cout<<"light background factory creating..."<<endl;
    }
    void createDefaultText(){
        cout<<"light background factory creating..."<<endl;
    }
    void createGreenText(){
        cout<<"\033[1;32m ";
        cout<<"\033[1;32m light background factory creating..."<<endl;
    }
};



int maintheme(){
   
    ThemeCreator* theme;
    theme=new LightFactory();
    theme->createBackground();
    theme->createGreenText();
    theme->createDefaultText();
    
    return 0;

}

