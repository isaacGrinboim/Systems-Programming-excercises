#include <iostream>
#include <vector>
#include <memory>
class AirCraft;
using namespace std;

class Radar{

private:
     vector<unique_ptr<AirCraft>> airCrafts;
public:
     friend class Conditional_iterator;
     Radar() = default;
     Radar(const Radar& other){
          for(unique_ptr<AirCraft>> craft : other.airCrafts){
               unique_ptr<AirCraft> new_craft = unique_ptr(craft.clone());
               airCrafts.push_back(move(new_craft));
          }
     }
     Radar& operator=(const Radar& other){
          if(&other == this){
               return *this;
          }
          delete[] airCrafts;
          vector<unique_ptr<AirCraft>> airCrafts;
          for(unique_ptr<AirCraft>> craft : other.airCrafts){
               unique_ptr<AirCraft> new_craft = unique_ptr(craft.clone());
               airCrafts.push_back(move(new_craft));
          }
          this->airCrafts = airCrafts;

     }
     ~Radar() = default;
     void track(const AirCraft& craft);
     friend ostream& operator<<(ostream& os);

     Conditional_iterator conditional_begin(Condition cond) const;
     Conditional_iterator conditional_end() const;

     template <class Condition> 
     class Conditional_iterator{
     private:
          int index;
          Condition cond;
          const Radar* radar;
          Conditional_iterator(Radar* radar, Condition cond):
          radar(radar),cond(cond){}
     public:
          const AirCraft& operator*()const;

          Conditional_iterator& operator++(){
               while(index<airCrafts.end()){
                    if(cond(airCrafts[++index])){
                         break;
                    }
               }
               return *this;
          }
          bool operator!=(const Conditional_iterator& other)const;
     };



};
void Radar::track(const AirCraft& craft){
     unique_ptr<AirCraft> new_craft = unique_ptr(craft.clone());
     airCrafts.push_back(move(new_craft));
}
ostream& operator<<(ostream& os, const Radar& radar){
     for(unique_ptr<AirCraft> craft : airCrafts){
          craft->print(os);
     }
     return os;
}

