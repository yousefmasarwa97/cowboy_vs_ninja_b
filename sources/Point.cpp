#include "Point.hpp"
#include <iostream>
#include<stdio.h>
#include <string>
#include <cmath>


namespace ariel {}

Point::Point(double x,double y):x(x),y(y){}
double Point::get_x(){return x;}
double Point::get_y(){return y;}

double Point::distance(const Point &other){
    double x_dis=pow(other.x-this->x,2);
    double y_dis=pow(other.y-this->y,2);
    return sqrt(x_dis+y_dis);
}

std::string Point::print(){
    
    return " {" +std::to_string(this->x)  +"," +std::to_string(this->y) +"} ";
}


Point Point::moveTowards( Point &base, Point &destination, double distance){
    if (distance<0) {
        throw std::invalid_argument("distance must be positive");
    
    }
    double dist=base.distance(destination);
    if(dist<=distance){
        return destination;
    }

    double ratio = distance / dist;
    double x = (base.x*(1 - ratio)) + (ratio * destination.x);
    double y = (base.y*(1 - ratio)) + (ratio * destination.y);
    return Point(x,y);
}

std::string Point::tostring(){
    std::string res="{"+std::to_string(this->get_x()) +","+std::to_string(this->get_y())+"}";
    return res;
}

bool Point::operator==(const Point &other) const{
    if (this->x==other.x && this->y==other.y) {
        return true;
    }
    return false;
}



