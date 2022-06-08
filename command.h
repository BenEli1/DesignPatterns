//
// Created by Ben on 15/02/2022.
//

#ifndef DESIGNPATTERNS_COMMAND_H
#define DESIGNPATTERNS_COMMAND_H

#endif //DESIGNPATTERNS_COMMAND_H
using namespace std;
class Command{
public:
    virtual void execute()=0;
};
class CommandHamburger:public Command {
    string descrpition;
public:


    CommandHamburger():descrpition("Hambruger oh yeah"){}
    virtual void execute()  {
    cout<<descrpition<<endl;
    }
};
class CommandPizza:public Command{
    string descrpition;
public:
    CommandPizza() : descrpition("Pizza is nice") {}

    virtual void execute() {
        cout<<descrpition<<endl;

    }
};
class CommandSushi:public Command{
    string descrpition;
public:
    CommandSushi() : descrpition("Aima le Sushi") {}
    virtual void execute() {
        cout<<descrpition<<endl;

    }


};