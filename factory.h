//
// Created by Ben on 14/02/2022.
//

#ifndef DESIGNPATTERNS_FACTORY_H
#define DESIGNPATTERNS_FACTORY_H

#endif //DESIGNPATTERNS_FACTORY_H
class Worker{
};
class TA:public Worker{
};
class Lecturer:public Worker{

};
class Admin:public Worker{
};
class WorkerFactory{
    virtual Worker* create()=0;
};
class TAFactory:public WorkerFactory{
    Worker * create() override{
        return new TA();
    }
};
class LecturerFactory:public WorkerFactory{
    Worker * create() override{
        return new Lecturer();
    }
};
class AdminFactory:public WorkerFactory{
    Worker * create() override{
        return new Admin();
    }
};