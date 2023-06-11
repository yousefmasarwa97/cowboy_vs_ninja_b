#pragma once
#include <string>
#include "Point.hpp"
namespace ariel{}
using namespace std;

class Character{
    private:
    Point location;
    int hp;
    string name;
    bool ismember;
    bool is_Ninja;


    public:
    
    Character(string name,const Point &location);
    Character(string name,const Point &location,int );
    
    virtual ~Character();
    

    
    void setismember(bool);
    bool getismember();
    void set_isninja(bool);
    bool get_isninja();

    bool operator==(const Character&) const;
    void set_location(Point);
    bool isAlive();
    void hit(int hits);
    string getName();
    Point getLocation();
    int gethp();
    virtual string print();
    double distance( Character *other);
    virtual void attack(Character *other)=0;





};