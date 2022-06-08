//
// Created by Ben on 28/03/2022.
//

#ifndef DESIGNPATTERNS_BUILDER_H
#define DESIGNPATTERNS_BUILDER_H

#endif //DESIGNPATTERNS_BUILDER_H
using namespace std;
class Pizza{
public:
    vector<string>toppings;

    Pizza( int size,const vector<string> &toppings,string type) : toppings(toppings), size(size),type(type) {}

    int size;
    string type;
    void printWhatsOnThePizza(){
        cout<<"type of pizza is: "<<type<<"\nand has:\n";
        for(auto x:toppings){
            cout<<x<<" \n";
        }
    }
};
class PizzaBuilder{
//    int size;
//    vector<string>toppings;
public:
//    PizzaBuilder(int size, const vector<string> &toppings) : size(size), toppings(toppings) {}

    virtual Pizza* buildPizza()=0;
//        return new Pizza(this->size,this->toppings);

    virtual Pizza* chooseSize(int size2)=0;
//        this->size=size2;

    virtual Pizza* addToppings(string top)=0;
//        this->toppings.push_back(top);


};
class  Orderer{
    PizzaBuilder* builder;
public:
    Orderer(PizzaBuilder *builder) : builder(builder) {}
    void changeBuilder(PizzaBuilder *builder2){
        builder=builder2;
    }
    Pizza* make(){
        builder->buildPizza();
    }

};

class NapoliPizzaBuilder:public PizzaBuilder{
    Pizza* p;
public:
    NapoliPizzaBuilder() {
        p=new Pizza(15,{"Olives"},("Napoli!"));
    }

public:
//    NapoliPizzaBuilder(): PizzaBuilder(15,{"Olives"}) {}
    Pizza *buildPizza() override {
        return p;
    }

    Pizza* chooseSize(int size2) override {
    p->size=size2;
    return p;
    }

    Pizza* addToppings(string top) override {
        p->toppings.push_back(top);
        return p;
    }
};
class AmericanPizzaBuilder:public PizzaBuilder{
    Pizza* p;
public:
    AmericanPizzaBuilder() {
        p=new Pizza(25,{"Extra meatt"},("American!"));
    }
    Pizza *buildPizza() override {
        return p;
    }

    Pizza* chooseSize(int size2) override {
        p->size=size2;
        return p;
    }

    Pizza* addToppings(string top) override {
        p->toppings.push_back(top);
        return p;
    }
};

