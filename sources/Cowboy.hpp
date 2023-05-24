#pragma once
#include "Character.hpp"
namespace ariel{}



class Cowboy : public Character{
    private:
    int boolets;
    
    public:
    Cowboy(string name,const Point& lacation);
    void set_boolets(int);
    
    
    void shoot( Character* enemy);
    bool hasboolets();
    void reload();
    string print();
    int boolets_num();
    void attack(Character*);



};