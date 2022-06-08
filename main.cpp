#include <iostream>
#include <stdio.h>
#include <string.h>
#include <iostream>
#include <iostream>
#include <vector>
#include "prototype.h"
#include "abstractFactory.h"
#include "factory.h"
#include <map>
#include "command.h"
#include "factory2.h"
#include "builder.h"
#include "adapter.h"
#include "bridge.h"
#include <list>
using namespace std;
//class A
//{
//public:
//    virtual void f()
//    {cout<<"A";}
//    void h()
//    {cout<<"a";}
//    void g()
//    {
//        f();
//        h();
//    }
//};
//class B : public A
//{
//public:
//    virtual void f()
//    {cout<<"B";}
//    void h()
//    {cout<<"b";}
//};
//class C : public B
//{
//public:
//    virtual void f()
//    {cout<<"C";}
//    void h()
//    {cout<<"c";}
//};
//
//
//
//class Employee{
//    std::string _name;
//    int _age;
//    int _salary;
//public:
//    Employee(std::string name,int age,int salary){
//        this->_name = name;
//        this->_age = age;
//        this->_salary = salary;
//    }
//
//};
//
//class Builder{
//    int _age;
//    int _salary;
//    std::string _name;
//public:
//    Builder():_age(18),_salary(10000),_name("default"){
//    }
//
//    Builder* setAge(int age) {
//        _age = age;
//        return this;
//    }
//
//    Builder* setSalary(int salary) {
//        _salary = salary;
//        return this;
//    }
//
//    Builder* setName(const std::string &name) {
//        _name = name;
//        return this;
//    };
//
//    Employee* build(){
//        return new Employee(_name, _age, _salary);
//    }
//};
//
//
//struct Sqr{
//    template<class T>
//    void operator()(T& number) const {
//        number = number * number;
//    }
//};
//struct Print {
//    template<class T>
//    void operator()(T& printable) const{
//        cout << printable << " ";
//    }
//};
//
//template <class T, class func>
//void applyOnArray(T* array, int size, const func& f){
//    for (int i = 0; i < size; i++)
//        f(array[i]);
//}
//template<class T,class Func>
//class Property{
//          T p;
//          Func f;
//    Property<T>* l;
//public:
//    Property() : p(nullptr), f(nullptr) {}
//    void opreator=(T x){
//        if (p) {
//        if (p != x) {
//            this->p = x;
//            if (f)
//                f(p);
//            if(l){
//                l=x;
//            }
//        }
//        }
//          }
//          T get(){
//              return this->p;
//          }
//          void onSet(Func ft){
//              this->f=ft;
//          }
//          void bindTo(Property<T>& r){
//              l=&r;
//          }
//        };
class Employee{
public:
    const int age;
    const string name;
    Employee(int age,string name):age(age),name(name){}
};

class EmployeeBuilder{
    int age;
    string name;
    static map<string,Employee*> flyweight2; // static map 10 points
public:
    EmployeeBuilder():age(18),name("default"){}
    EmployeeBuilder& setAge(int age){ // return *this by ref 5 points
        this->age=age;
        return *this;
    }
    EmployeeBuilder& setName(string name){
        this->name=name;
        return *this;
    }
    Employee* build(){
        string key=name+","+to_string(age); // unique key 5 points
// if key not found, insert 5 points
        auto it=flyweight2.find(key);
        if(it==flyweight2.end()){
            flyweight2[key]=new Employee(age,name);
        }
        return flyweight2[key];
    }
    static void clear() {
// free every pointer 5 points
        for (auto it: flyweight2) {
        delete it.second;
            flyweight2.clear(); // clear the map 5 points
    }
    }
};
int main(){
    Employee* e0=EmployeeBuilder().build(); // 18, "default"
    Employee* e1=EmployeeBuilder().setAge(40).setName("eli").build();
    Employee* e2=EmployeeBuilder().setName("eli").setAge(40).build();
    cout<<(e1==e2)<<endl; // true
    cout<<(e1==e0)<<endl; // false
    EmployeeBuilder::clear();
//abstract factory check
//ConcreteFactory1* f1 = new ConcreteFactory1();
//Client* c1 = new Client(f1);
//ConcreteFactory2* f2 = new ConcreteFactory2();
//Client* c2 = new Client(f2);
//ProductA* a1 = c1->createSword();
//ProductB* b1 =c1->createShield();
//ProductA* a2 = c2->createSword();
//ProductB* b2 =c2->createShield();
//cout<<"Client Number 1 Sword:  "<<a1->print()<<"\t  Shield: "<<b1->print()<<endl;
//cout<<"Client Number 2 Sword:  "<<a2->print()<<"\t  Shield: "<<b2->print()<<endl;
//delete f1;
//delete f2;
//delete c1;
//delete c2;
//delete a1;
//delete a2;
//delete b1;
//delete b2;
//        B* p;
//        p = new B;
//        p->g();
//        p->h();

//int x = 0;
//char* input;
//map<const char*,WorkerFactory*> factoryMap;
//WorkerFactory* taFactory = new TAFactory();
//factoryMap.insert(std::pair<const char*,WorkerFactory*>("TA",taFactory));
//
//while(x<10){
//    cin >> input;
//    if(input == "TA"){
//       arrayWorker[x] =
//    }
//    x++;
//}

//singleton
//    Singleton* s1 = Singleton::getInstance();
//    Singleton* s2= Singleton::getInstance();




//
//        Employee* e1 = Builder().build();
//        Employee* e2 = Builder().setAge(20)->setName("abc")->setSalary(20000)->build();
//

//CommandHamburger().execute();
//CommandPizza().execute();
//CommandSushi().execute();
//Creator* c = new Creator();
//Factory* f2=new ConcFactory2();
//Factory* f1=new ConcFactory1();
//int r=0;
//while(r<12) {
//    c->changeFactory(f2);
//    c->createProduct();
//    c->changeFactory(f1);
//    c->createProduct();
//    r++;
//}
////}
////c->printProducts();
//    PizzaBuilder* pbNapoli=new NapoliPizzaBuilder();
//    PizzaBuilder* pbAmerican=new AmericanPizzaBuilder();
//    int today=3;
//    if(today==3) {
//        pbNapoli->addToppings("Bazilikum");
//    }
//    if(today==4) {
//        pbNapoli->addToppings("Pork");
//    }
//    today=5;
//    if(today==5) {
//        pbAmerican->addToppings("Extra cheese you already know");
//    }
//Orderer* person=new Orderer(pbNapoli);
//Pizza* p=person->make();
//person->changeBuilder(pbAmerican);
//Pizza* p2=person->make();
//p->printWhatsOnThePizza();
//p2->printWhatsOnThePizza();
//Square* s1=new Square(4,7);
//cout<<"s1 size is:"<<s1->calcArea()<<"\n";
//Circle1* c=new Circle1(6);
//Adapter* adapt=new Adapter(c);
//
//cout<<"circle area is:"<<adapt->calcArea();
//    std::cout << "Client: I can work just fine with the Target objects:\n";
//    Target *target = new Target;
//    ClientCode(target);
//    std::cout << "\n\n";
//    Adaptee *adaptee = new Adaptee;
//    std::cout << "Client: The Adaptee class has a weird interface. See, I don't understand it:\n";
//    std::cout << "Adaptee: " << adaptee->SpecificRequest();
//    std::cout << "\n\n";
//    std::cout << "Client: But I can work with it via the Adapter:\n";
//    Adapter *adapter = new Adapter(adaptee);
//    ClientCode(adapter);
//    std::cout << "\n";
//
//    delete target;
//    delete adaptee;
//    delete adapter;
//House* h=new bigHouse();
//Builder2* b = new woodenBuilder();
//    Builder2* b2 = new glassBuilder();
//h->setB(b);
//h->setB(b2);
//
//    Property<int> p;
//    p.onSet([](int x){cout<<"change!"<<endl;});
//    p=5; // output: change!
//    p=6; // output: change!
//    p=6; //
//    p.onSet([](int x){cout<<"new value is "<<x<<endl;});
//    p=6; //
//    p=7; // output: new value is 7
//    cout<<p.get()<<endl; // output: 7
//    Property<int> p2;
//    p2.bindTo(p); // when p changes also p2
//    p2.onSet([](int x){cout<<"value of p2 is "<<x<<endl;});
//    p=8;
return 0;
}


