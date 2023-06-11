#include "Character.hpp"
#include "Ninja.hpp"
#include "Point.hpp"
#include <iostream>
#include <string>
namespace ariel{}


Character::Character(string name,const Point &location)
:location(location),name(name),ismember(false),is_Ninja(false){
   
}

Character::Character(string name,const Point &location,int hp)
:location(location),name(name),hp(hp),ismember(false),is_Ninja(false){
}

Character::~Character(){}

void Character::setismember(bool flag){
    ismember=flag;

}

bool Character::getismember(){
    return ismember;
}
void Character::set_isninja(bool flag){
    is_Ninja=flag;

}

bool Character::get_isninja(){
    return is_Ninja;
}

int Character::gethp(){
    return this->hp;
}

bool Character::operator==(const Character &other) const{
    if (this->name==other.name && this->location==other.location) {
        return true;
    }
    return false;
}

void Character::set_location(Point new_point){
    this->location=new_point;
}

Point Character::getLocation(){
    return this->location;
}

string Character::getName(){
    return this->name;
}

bool Character::isAlive(){
    if (this->hp>0) {
        return true;
    }
    return false;
}
    


double Character::distance( Character *other){
    Point this_loc =this->location;
    Point other_loc=other->location;
    return this_loc.distance(other_loc);
}

void Character::hit(int hits){
    if (hits<0) {
        throw invalid_argument("Damage can't be negative");
    }
    this->hp=this->hp-hits;
    if (this->hp<0) {
        this->hp=0;
    
    }
}

string Character::print(){
    string res;

    
    res= " {" + this->getName() + "," +std::to_string(this->hp)  + "," + 
    (this->location).print() + "} ";
    return res;
    
    return  res;
}


