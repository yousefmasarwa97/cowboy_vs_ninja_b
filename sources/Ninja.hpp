#pragma once
#include "Character.hpp"
#include <string>

namespace ariel
{
}

class Ninja : public Character{
    private:
    int speed;

    public:
    Ninja(string name,const Point &location);
    Ninja(string name,const Point &location,int);
    Ninja(string name,const Point &location,int,int);
    ~Ninja();
    void move( Character* enemy);
    virtual void slash( Character* enemy);
    void attack(Character*);
    string print();


};