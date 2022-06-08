//
// Created by Ben on 28/03/2022.
//

#ifndef DESIGNPATTERNS_FACTORY2_H
#define DESIGNPATTERNS_FACTORY2_H

class Product{
public:
    int size,weight,height;
    string name;
    Product(int size, int weight, int height, const string &name) : size(size), weight(weight), height(height),
                                                                    name(name) {}
};
class ConcProduct1:public Product{
public:
    ConcProduct1():Product(20,3,10,"product number 1"){}
};
class ConcProduct2:public Product{
public:
    ConcProduct2():Product(1234,12,43,"product number 2"){}
};
class Factory{
public:
    virtual Product* createProduct()=0;
};
class ConcFactory1:public Factory{
public:
    ConcFactory1(){}
    Product* createProduct(){
        return new ConcProduct1();
    }
};
class ConcFactory2:public Factory{
public:
    ConcFactory2(){}
    Product* createProduct(){
        return new ConcProduct2();
    }
};
class Creator{
    vector<Product*>vec;
    Factory* f;
public:
    Creator():f(new ConcFactory1()){}
    Creator(Factory *ftag){
        f=ftag;
    }
    void createProduct(){
        Product* p= this->f->createProduct();
        this->vec.push_back(p);
    }
    void printProducts(){
        for(int i =0;i<vec.size();i++){
            cout<<"\n"<<vec[i]->name<<" "<<vec[i]->size<<" "<<vec[i]->weight<<" "<<vec[i]->height;
        }
    }
    void changeFactory(Factory* f2){
        f=f2;
    }

};


#endif //DESIGNPATTERNS_FACTORY2_H
