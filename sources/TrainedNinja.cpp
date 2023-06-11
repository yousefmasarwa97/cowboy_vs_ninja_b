#include"TrainedNinja.hpp"
#include"Character.hpp"

namespace ariel{}

TrainedNinja::TrainedNinja(string name,const Point &location)
:Ninja(name, location,120,12){
    this->set_isninja(true);

}