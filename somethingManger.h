//
// Created by Ben on 16/02/2022.
//

#ifndef DESIGNPATTERNS_SOMETHINGMANGER_H
#define DESIGNPATTERNS_SOMETHINGMANGER_H

#endif //DESIGNPATTERNS_SOMETHINGMANGER_H
#include <vector>
class CycleException{/*...*/};
class Employee{
public:
    virtual void print(){
        cout<<"Employee"<<endl;
    }
    virtual ~Employee(){}
};
class Engineer:public Employee{
public:
    virtual void print(){
        cout<<"Engineer"<<endl;
    }
};








class Manager : public Employee{
    vector<Employee*> vEmployee;
    Manager* parent;
public:
    Manager() {
        vEmployee = nullptr;
        parent = nullptr;
    }

    virtual void print(){
        cout<<"Manager"<<endl;
    }
    void addEmployee(Employee* e) throws CycleException{
        Employee* e1 = dynamic_cast<Manager*>(e);
        if(!e1){
                if(!CheckHeritance(e)) {
                    vEmployee.push_back(e);
                }
            }
        else if(e1!=this*) {
                vEmployee.push_back(e);
        }
        else{
                throw CycleException;
            }

    }
    bool CheckHeritance(Employee* e){
        if(parent){
            if(parent.vEmployee.find(e)!=parent.vEmployee.end()){
                return true;
            }
            if(parent==e){
                return false;
            }
            return parent.checkHeritance(e);
        }
        return false;
    }
    virtual ~Manager() {
    for_each(vEmployee.begin(),vEmployee.end(),[](vector<Employee*> vEmployee,
        Manager* parent){delete vEmployee;
        delete parent;});
    }
};