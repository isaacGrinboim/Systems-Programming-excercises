#include <iostream>
#include <vector>
#include <memory>
using namespace std;


class Vehicle{
protected:
     int id;
     string currentOwner;


public:
     Vehicle(int id, const string& owner = "NotLeased"):id(id), currentOwner(owner){}
     Vehicle(const Vehicle& other) = default;
     Vehicle& operator=(const Vehicle& other) = default;
     virtual ~Vehicle() = default;
     
     int getId() const{
          return id;
     }
     void setOwner(const string& newOwner){
          currentOwner= newOwner;
     }

     virtual int calcPrice(int daysNum) const = 0;
     virtual void print(ostream& os) const =0;
     virtual Vehicle* clone() const = 0;


     friend ostream& operator<<(ostream& os, const Vehicle& vehicle){
          os << "Vehicle ID: " << vehicle.id << endl;
          os << "Current Owner: " << vehicle.currentOwner << endl;
          vehicle.print(os);
          return os;
     }
};

class Truck: public Vehicle{
private:
     int maxWeight;
public:
     Truck(int id,int maxWeight, const string& owner = "NotLeased"):Vehicle(id,owner),maxWeight(maxWeight){}
     Truck(const Truck& other) = default;
     Truck& operator=(const Truck& other) = default;
     ~Truck() = default;

     int calcPrice(int daysNum) const override{
          return daysNum*(maxWeight + 20);
     }
     virtual void print(ostream& os) const override{
          os<< "Max weight on truck:________" << endl;
     }
     Vehicle* clone() const override{
          return new Truck(*this);
     }
};

template <int N>
class Car: public Vehicle{
     private:
          int sits;
     public:
          Car(int id, const string& owner = "NotLeased"):Vehicle(id,owner), sits(N){}
          Car(const Car& other) = default;
          Car& operator=(const Car& other) = default;
          ~Car() = default;

     int calcPrice(int daysNum) const override{
          return daysNum*(100*sits);
     }
     virtual void print(ostream& os) const override{
          os<< "Number of passengers:________" << endl;
     }
     Vehicle* clone() const override{
          return new Car<N>(*this);
     }
};

// הגדרה של מחלקה ספציפית עם 2:
typedef Car<2> PersonalCar; 


class LeasingCompany{
private:
     vector<shared_ptr<Vehicle>> vehicles;
public:
     


};