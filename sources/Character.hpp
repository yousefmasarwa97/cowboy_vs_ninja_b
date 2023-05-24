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


    public:
    
    Character(string name,const Point &location);
    Character(string name,const Point &location,int hp);
    //Character();
    virtual ~Character();
    Character() = delete; 
    Character(const Character &) = delete;
    Character& operator =(Character const&) = delete;
    Character(Character&&) = delete;
    Character& operator=(Character&&) = delete;

    
    void setismember(bool);
    bool getismember();

    bool operator==(const Character&) const;
    void set_location(Point);
    bool isAlive();
    void hit(int hits);
    string getName();
    Point getLocation();
    virtual string print();
    double distance( Character *other);
    virtual void attack(Character *other)=0;





};