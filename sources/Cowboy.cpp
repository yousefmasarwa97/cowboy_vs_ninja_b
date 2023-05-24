#include "Cowboy.hpp"
#include <cstddef>
#include <stdexcept>
#include <string>
#include <type_traits>
#include "Character.hpp"

namespace ariel {}

Cowboy::Cowboy(string name,const Point& location):
Character(name,location,110),boolets(6){
}

void Cowboy::set_boolets(int n){
    this->boolets=n;
}

void Cowboy::attack(Character* enemy){
    shoot(enemy);
}



void Cowboy::shoot( Character *enemy){
    if (enemy==nullptr) {
        throw ("enemy is null");
    }
    if(!enemy->isAlive()){
        throw runtime_error("the enemy is dead!!!!");
    }
    if(!this->isAlive()){// throw error when the cowboy is dead
        throw std::runtime_error("You are dead!!!");
    }
    if(this == enemy){ // throw error when the input is us
        throw std::runtime_error("You can't shoot yourself");
    }
    
    else if(enemy->isAlive() && hasboolets()){ 
        enemy->hit(10);
        boolets--;
    }
    else if(!hasboolets()){ 
        reload();
    }
}
     
    

bool Cowboy::hasboolets(){
    if(this->boolets>0){
        return true;
    }
    return false;
}


void Cowboy::reload(){
    if (this->isAlive()) {
        this->set_boolets(6);
    }
    else{
        throw std::runtime_error("You are dead!!!");
    }
    
}



string Cowboy::print(){ 
    string res;
    if (isAlive()) {
       res= " {" + this->getName() + "," +std::to_string(this->gethp())  + "," + 
        (this->getLocation()).print() + "} ";
    }
    else if(!isAlive())  {
   
    res="C ("+this->getName()+")";
    }
    return res;
}

int Cowboy::boolets_num(){
    return boolets;
}

