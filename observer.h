//
// Created by Ben on 15/02/2022.
//
#include <vector>
#ifndef DESIGNPATTERNS_OBSERVER_H
#define DESIGNPATTERNS_OBSERVER_H

#endif //DESIGNPATTERNS_OBSERVER_H
class eventArgs{

};
class Observer{
    eventArgs* e;
public:
    Observer(eventArgs* e1){
        e=e1;
    }
    void notify(){

    } ;
};
class Observable{
    vector<Observer*> observerList;
    eventArgs* e;
public:
    Observable(Observer **observerList, eventArgs *e) : observerList(observerList), e(e) {}

    void notifyall(eventArgs* e){
        this->observerList.

};
void addObserver(Observer o){

    };

};