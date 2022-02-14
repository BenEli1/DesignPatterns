//
// Created by Ben on 14/02/2022.
//

#ifndef DESIGNPATTERNS_PROTOTYPE_H
#define DESIGNPATTERNS_PROTOTYPE_H

#endif //DESIGNPATTERNS_PROTOTYPE_H
//Prototype Design Pattern.
class Shape{
    int x;
    int y;
public:
    int getX() const {
        return x;
    }

    int getY() const {
        return y;
    }

    Shape(int x1,int y1){
        x=x1;
        y=y1;
    }
    virtual Shape* clone()=0;
};
class Rectangle: public Shape{
int width;
int height;
public:
    int getWidth() const {
        return width;
    }

    int getHeight() const {
        return height;
    }

public:
    Rectangle(int x1, int y1, int width, int height) : Shape(x1, y1), width(width), height(height) {}
    Rectangle* clone() override{
        Rectangle* r = new Rectangle(getX(),getY(),getWidth(),getHeight());
        return r;
    }
};
class Circle : public Shape{
double radius;
public:
    double getRadius() const {
        return radius;
    }

    Circle(int x1, int y1, double radius) : Shape(x1, y1), radius(radius) {}

    Circle* clone() override{
        Circle* r = new Circle(getX(),getY(),getRadius());
        return r;
    }
};