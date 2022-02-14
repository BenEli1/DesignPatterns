//
// Created by Ben on 14/02/2022.
//

#ifndef DESIGNPATTERNS_SINGELTON_H
#define DESIGNPATTERNS_SINGELTON_H

#endif //DESIGNPATTERNS_SINGELTON_H
class Singleton{
private:
    static Singleton* s1;
    char* name;
    Singleton(char* name2){
        this->name= name2;
    };
    Singleton(Singleton &other) = delete;
    /**
     * Singletons should not be assignable.
     */
    void operator=(const Singleton &) = delete;
public:
    static Singleton* getInstance(){
        if(s1 == nullptr){
            s1 = new Singleton("created once");
        }else{
            return s1;
        }
    }
};
Singleton* Singleton::s1= nullptr;
