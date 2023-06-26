//
//  builder.cpp
//  design_patterns
//
//  Created by Mark Du on 2023-06-23.
//

#include <iostream>
#include <string>

using namespace std;

class ComboMeal{
private:
    string mainfood_;
    string side_;
    string drink_;
public:
    void getEntree(const string& mainfood){
        mainfood_ = mainfood;
    }
    
    void getSide(const string& side){
        side_=side;
    }
    
    void getDrink(const string& drink){
        drink_=drink;
    }
    
    void display() const {
        cout<<"entree with "<<mainfood_<<" side dish with "<<side_<<", drink with "<<drink_<<endl;
    }
};

class MealBuilder{
public:
    virtual void buildEntree()=0;
    virtual void buildSide()=0;
    virtual void buildDrink()=0;
    virtual ComboMeal* getMeal()=0;
};

class BurgerBuilder : public MealBuilder{
private:
    ComboMeal* meal_;
public:
    BurgerBuilder(){meal_=new ComboMeal();}
    void buildEntree() override{
        meal_->getEntree("Burger");
    }
    
    void buildSide() override{
        meal_->getSide("Fries");
    }
    
    void buildDrink() override{
        meal_->getDrink("Soda");
    }
    
    ComboMeal* getMeal() override{
        return meal_;
    }
};

class HotDogBuilder : public MealBuilder{
private:
    ComboMeal* meal_;
public:
    HotDogBuilder(){meal_= new ComboMeal();}
    
    void buildEntree()override{
        meal_->getEntree("hotdog");
    }
    
    void buildSide() override{
        meal_->getSide("salad");
    }
    
    void buildDrink() override{
        meal_->getDrink("milk");
    }
    
    ComboMeal* getMeal() override{
        return meal_;
    }
};

class Instructor {
private:
    MealBuilder* builder_;
public:
    void setMealBuilder(MealBuilder* builder){
        builder_ = builder;
    }
    
    void constructMeal(){
        
        builder_->buildEntree();
        builder_->buildDrink();
        builder_->buildSide();
    }
};

int mainbuild(){
    Instructor instructor;
    BurgerBuilder builder;
    
    instructor.setMealBuilder(&builder);
    instructor.constructMeal();
    ComboMeal* meal =builder.getMeal();
    meal->display();
    
    HotDogBuilder hdbuilder;
    instructor.setMealBuilder(&hdbuilder);
    instructor.constructMeal();
    ComboMeal* hdcombo=hdbuilder.getMeal();
    hdcombo->display();
    
    delete meal;
    delete hdcombo;
    return 0;
}
