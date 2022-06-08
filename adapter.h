//
//class Square {
//    int height;
//    int width;
//public:
//    Square(int h, int w) : height(h), width(w) {}
//    Square(Square* s){
//        this->height=s->height;
//        this->width=s->width;
//    }
//    void setHeight(int height) {
//        Square::height = height;
//    }
//
//    void setWidth(int width) {
//        Square::width = width;
//    }
//
//    int calcArea(){
//        return width*height;
//    }
//};
//
//class Circle1{
//    int radius;
//public:
//    int getRadius() const {
//        return radius;
//    }
//
//    Circle1(int r):radius(r){}
//
//};
//class Adapter:public Square{
//    Circle1* c;
//public:
//    Adapter(Circle1* c) : c(c), Square(convertToCircle()) {}
//    Square* convertToCircle(){
//        return new Square(3,this->c->getRadius()*this->c->getRadius());
//    }
//};
#include <algorithm>

/**
 * The Target defines the domain-specific interface used by the client code.
 */
class Target {
public:
    virtual ~Target() = default;

    virtual std::string Request() const {
        return "Target: The default target's behavior.";
    }
};

/**
 * The Adaptee contains some useful behavior, but its interface is incompatible
 * with the existing client code. The Adaptee needs some adaptation before the
 * client code can use it.
 */
class Adaptee {
public:
    std::string SpecificRequest() const {
        return ".eetpadA eht fo roivaheb laicepS";
    }
};

/**
 * The Adapter makes the Adaptee's interface compatible with the Target's
 * interface.
 */
class Adapter : public Target {
private:
    Adaptee *adaptee_;

public:
    Adapter(Adaptee *adaptee) : adaptee_(adaptee) {}
    std::string Request() const override {
        std::string to_reverse = this->adaptee_->SpecificRequest();
        std::reverse(to_reverse.begin(), to_reverse.end());
        return "Adapter: (TRANSLATED) " + to_reverse;
    }
};

/**
 * The client code supports all classes that follow the Target interface.
 */
void ClientCode(const Target *target) {
    std::cout << target->Request();
}
