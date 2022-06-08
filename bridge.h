//
// Created by Ben on 28/03/2022.
//

#ifndef DESIGNPATTERNS_BRIDGE_H
#define DESIGNPATTERNS_BRIDGE_H

#endif //DESIGNPATTERNS_BRIDGE_H
class Builder2{
public:

    virtual string buildDoors()=0;
    virtual string buildWindow()=0;
};
class House{
    Builder2* b;
    int size;
    string door;
    string window;
public:
    House(int size) : size(size) {}

    House(Builder2* b) : size(45),b(b) {
        door=b->buildDoors();
        window=b->buildWindow();
    }

    void setB(Builder2 *b) {
        House::b = b;
        door=b->buildDoors();
        window=b->buildWindow();
    }

};

class woodenBuilder:public Builder2{
public:
    virtual string buildDoors(){
        return "wooden door";
    };
    virtual string buildWindow(){
        return "wooden window";
    };
};
class glassBuilder:public Builder2{
public:

    virtual string buildDoors(){
        return "glass door";

    };
    virtual string buildWindow(){
        return "glass window";
    };
};
class bigHouse:public House{
public:
    bigHouse():House(500) {}

};
class smallHouse:public House{
public:
    smallHouse():House(5) {}
};