#include <iostream>
#include <stdio.h>
#include <string.h>
#include <iostream>
using namespace std;
//Prototype Design Pattern.
//class Shape{
//    int x;
//    int y;
//public:
//    int getX() const {
//        return x;
//    }
//
//    int getY() const {
//        return y;
//    }
//
//    Shape(int x1,int y1){
//        x=x1;
//        y=y1;
//    }
//    virtual Shape* clone()=0;
//};
//class Rectangle: public Shape{
//int width;
//int height;
//public:
//    int getWidth() const {
//        return width;
//    }
//
//    int getHeight() const {
//        return height;
//    }
//
//public:
//    Rectangle(int x1, int y1, int width, int height) : Shape(x1, y1), width(width), height(height) {}
//    Rectangle* clone() override{
//        Rectangle* r = new Rectangle(getX(),getY(),getWidth(),getHeight());
//        return r;
//    }
//};
//class Circle : public Shape{
//double radius;
//public:
//    double getRadius() const {
//        return radius;
//    }
//
//    Circle(int x1, int y1, double radius) : Shape(x1, y1), radius(radius) {}
//
//    Circle* clone() override{
//        Circle* r = new Circle(getX(),getY(),getRadius());
//        return r;
//    }
//};
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
//        return ProductB2();
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

int main(){
//    Circle* c1 =  new Circle(5,5,12); // prototype
//    Circle* c2 = c1.clone();
ConcreteFactory1* f1 = new ConcreteFactory1();
Client* c1 = new Client(f1);
ConcreteFactory2* f2 = new ConcreteFactory2();
Client* c2 = new Client(f2);
ProductA* a1 = c1->createSword();
ProductB* b1 =c1->createShield();
ProductA* a2 = c2->createSword();
ProductB* b2 =c2->createShield();
cout<<"Client Number 1 Sword:  "<<a1->print()<<"\t  Shield: "<<b1->print()<<endl;
cout<<"Client Number 2 Sword:  "<<a2->print()<<"\t  Shield: "<<b2->print()<<endl;
return 0;
}


