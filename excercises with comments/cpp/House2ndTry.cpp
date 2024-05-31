#include <iostream>
#include <vector>
#include <list>
#include <memory>
using namespace std;

class House{
protected:
     string street;
     int houseNum;
     int id;
     float area;

public:
     House(const string& street, int houseNum, int id, float area):
     street(street),houseNum(houseNum),id(id),area(area){}
     House(const House& other) = default;
     virtual ~House() = default;
     House& operator=(const House& other) = default;
     int getOwner () const{
          return id;
     }
     int setOwner(int newId){
          int prev = id;
          id = newId;
          return prev;
     }
     virtual float calcArnona() const = 0;

     void print(ostream& os) const{
          os<<street<<" "<<id<<endl;
     }
};

class Office: public House{
private:
     float parkingArea;
public:
     Office(const string& street, int houseNum, int id, float area, float parkingArea):
     House(street,houseNum, id, area), parkingArea(parkingArea){}
     Office(const Office& other) = default;     
     Office& operator =(const Office& other) = default;
     ~Office() = default;

     float calcArnona()const override{
          return 2000+50*area+25*parkingArea;
     }

};

template<int N>
class Home: public House{
private:
     int residents[N];
public:
     Home(const string& street, int houseNum, int id, float area,int residents[N]):
     House(street,houseNum, id, area){
          for (int i=0; i<N; ++i){
               this->residents[i] = residents[i];
          }
     }
     Home(const Office& other) = default;     
     Home& operator =(const Office& other) = default;
     ~Home() = default;    

     float calcArnona()const override{
          return 25*(area/N);
     }
};

class CityHall{
private:
     vector<shared_ptr<House>> buildings;
public:
     CityHall() = default;
     ~CityHall() = default;

     void addHouse(const House& h);
     float calcTax(const list<int>& owners) const{
          float totalArnona = 0;
          for(int owner: owners){
               float tax = 0;
               for(shared_ptr<House> house: buildings){
                    if(house->getOwner() == owner){
                         tax += house->calcArnona();
                         house->print(cout);
                    }
               }
               cout<<tax<<endl;
               totalArnona += tax;
          }
          return totalArnona;
     }
};

