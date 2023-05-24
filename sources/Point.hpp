#pragma once
#include<stdio.h>
#include <string>


class Point{
    private:
    double x;
    double y;
    public:
    double get_x();
    double get_y();
    Point(double ,double );
    double distance(const Point &other);
    std::string print();
    static Point moveTowards( Point &base, Point &destination, double distance);
    std::string tostring();

    bool operator==(const Point&) const;


};