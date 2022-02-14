#include <iostream>
#include <stdio.h>
#include <string.h>
#include <iostream>
#include <iostream>
#include <vector>
#include "prototype.h"
#include "abstractFactory.h"
#include <map>
using namespace std;

int main(){
//prototype check
//    Circle* c1 =  new Circle(5,5,12);
//    Circle* c2 = c1.clone();

//abstract factory check
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


