#include "Ninja.hpp"
#include "Character.hpp"
#include"Point.hpp"
#include <stdexcept>

namespace ariel {
}


Ninja::Ninja(string name,const Point &location):Character(name,location),speed(){
    this->set_isninja(true);           
}

Ninja::Ninja(string name,const Point &location,int hp)
:Character(name,location,hp),speed(){       
}
Ninja::Ninja(string name,const Point &location,int hp,int speed)
:Character(name,location,hp),speed(speed){       
}


Ninja::~Ninja(){}

void Ninja::move( Character *enemy){
    double dist = this->getLocation().distance(enemy->getLocation());
    
    if (dist > speed) {
        double ratio = speed / dist;
        double _x = this->getLocation().get_x() + (enemy->getLocation().get_x() - this->getLocation().get_x()) * ratio;
        double _y = this->getLocation().get_y() + (enemy->getLocation().get_y() - this->getLocation().get_y()) * ratio;
        this->set_location(Point(_x, _y));
    } 

    else {
        this->set_location(enemy->getLocation());
    }
}

void Ninja::attack(Character *enemy){
    if (this->distance(enemy) >= 1)
    {
        move(enemy);
    }
    else
    {
        slash(enemy);
    }
}

    


void Ninja::slash( Character *enemy){
    if (enemy==nullptr) {
        throw ("enemy is null"); 
    }    
    else if(!this->isAlive() ){ // throw error when the enemy or we dead
        throw std::runtime_error("you are dead!!!");
    }

    else if( !enemy->isAlive()){ // throw error when the enemy or we dead
        throw std::runtime_error("enemy is dead!!!");
        
    }
    
    else if (this==enemy) {
        throw std::runtime_error("You can't slash yourself");
    
    }
   
    else if (this->isAlive() && enemy->isAlive() &&
        this->distance(enemy)<1) {
        enemy->hit(40);
    
    }   
}

string  Ninja::print(){ 
    string res;
    if (isAlive()) {
        res= " {" + this->getName() + "," +std::to_string(this->gethp())  + "," + 
        (this->getLocation()).print() + "} ";
    }
    else if(!isAlive()) {
   
    res="N ("+this->getName()+")";
    }
    return res;
}



