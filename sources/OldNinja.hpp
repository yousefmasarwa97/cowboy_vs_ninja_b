#pragma once
#include "Character.hpp"
#include "Ninja.hpp"


namespace ariel{}

class OldNinja: public Ninja{
    private:
    int speed;
   
    public:
    OldNinja(string name,const Point &location);

};