#pragma once
#include "Character.hpp"
#include "Ninja.hpp"


namespace ariel{}

class TrainedNinja: public Ninja{
    private:
    int speed;
   
    public:
    TrainedNinja(string name,const Point &location);

};