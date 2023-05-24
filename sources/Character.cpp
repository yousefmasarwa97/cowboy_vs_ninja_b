#include "Character.hpp"
// #include <cstddef>
#include "Ninja.hpp"
#include "Point.hpp"
#include <iostream>
#include <string>
namespace ariel{}


Character::Character(string name,const Point &location)
:location(location),name(name),ismember(false){
   
}

Character::Character(string name,const Point &location,int hp)
:location(location),name(name),hp(hp),ismember(false){
}
// Character::Character():location(0,0),ismember(false){
// }
Character::~Character(){}

void Character::setismember(bool flag){
    ismember=flag;

}

bool Character::getismember(){
    return ismember;
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

    if (isAlive()) {
        res= " {" + this->getName() + "," +std::to_string(this->hp)  + "," + 
        (this->location).print() + "} ";
       return res;
    }
    res="("+this->name+")";
    return  res;
}
