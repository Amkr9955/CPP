// similar class name
// no return type
// automatic call when one creates an object
// if not given by user compiler will creates itself

// 3 types:deafult, parameterized,copy constructor

#include<iostream>
using namespace std;

class Point {
    double x;
    double y;
    
    public:

    //default constructor
    Point(){ x=0;y=0; }

    //parameterized constructor
    Point(double X,double Y){ x=X;y=Y; }

    //copy constructor
    Point(const Point& cpc ){ x=cpc.x; y=cpc.y;}

    //getters
    double getX(){return x;}
    double getY(){return y;}

};

int main(){

    Point p1;
    Point p2(2.4,6.5);
    Point p3=p1;

    cout<<p1.getX()<<endl;
    cout<<p2.getX()<<endl;
    cout<<p3.getX()<<endl;

    return 0;
}