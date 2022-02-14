//
// Created by Ben on 14/02/2022.
//

#ifndef DESIGNPATTERNS_ABSTRACTFACTORY_H
#define DESIGNPATTERNS_ABSTRACTFACTORY_H

#endif //DESIGNPATTERNS_ABSTRACTFACTORY_H
class ProductA{
char* sword;
public:
    ProductA():sword("type of sword is: "){}
    virtual char* print(){
        return sword;
    }
};
class ProductB{
    char* shield;
public:
    ProductB():shield("type of shield is: "){}
    virtual char* print(){
        return shield;
    }
};
class ProductA1:public ProductA{
    char* swordA;
public:
    ProductA1():swordA("Steel"){}
    virtual char* print(){
       return swordA;
    }
};
class ProductB1:public ProductB{
    char* shieldB;
public:
    ProductB1():shieldB("Wooden"){}
    virtual char* print(){
        return shieldB;
    }
};
class ProductA2:public ProductA{
    char* swordA;
public:
    ProductA2():swordA("Light Saber"){}
    virtual char* print(){
        return swordA;
    }
};
class ProductB2:public ProductB{
    char* shieldB;
public:
    ProductB2():shieldB("Light Shield"){}
    virtual char* print(){
        return shieldB;
    }
};
class AbstractFactory{
public:
    virtual ProductA * createProductA()=0;
    virtual ProductB * createProductB()=0;
};
class ConcreteFactory1:public AbstractFactory{
    ProductA* createProductA() override {
        ProductA1* a = new ProductA1();
        return a;
    }

    ProductB* createProductB() override {
        ProductB1* a = new ProductB1();
        return a;
    }
};
class ConcreteFactory2:public AbstractFactory{
    ProductA* createProductA() override {
        ProductA2* a = new ProductA2();
        return a;
    }

    ProductB* createProductB() override {
        ProductB2* a = new ProductB2();
        return a;
    }
};

class Client{
    AbstractFactory* f;
public:
    Client(AbstractFactory* f1){
        f = f1;
    }
    ProductA* createSword(){
        return f->createProductA();
    };
    ProductB* createShield(){
        return f->createProductB();
    };
};