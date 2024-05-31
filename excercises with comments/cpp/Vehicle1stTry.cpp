#include <iostream>
#include <vector>

using namespace std;

class Car{
     protected:
          int id;
          string tempOwner;
     public:
          Car(int id,const string& tempOwner = "NotLeased"):id(id),tempOwner(tempOwner){}
          Car(const Car& other)=default;
          Car& operator=(const Car& other)=default;
          virtual ~Car() = default;// כל אחד קורא לדיסטרקטור של האב ולכן אסור שיהיה =0

          int getId()const{
               return id;
          }
          void setTempOwner(const string& newOwner){
               tempOwner=newOwner;
          }
          virtual int calculatePrice(int days)const  = 0;
          virtual void print(ostream& os) const = 0;
          friend ostream& operator<<(ostream& os, const Car& car){// אופרטור הדפסה לא יכול להיות וירטואלי
               os<<"Vehicle ID: "<<car.id<<endl<<"Current Owner: "<<car.tempOwner<<endl;
               car.print(os);// כי משמאל צריך אוסטרי, כלומר זה חיצוני למחלקה ולכן אין וירטואליות בכלל
          }
          // קלוון: אנחנו רוצים תחליף לקופי קונסטרקטור כשקיבלנו רק פוינטר לאבסטרקטי
          virtual Car* clone() const = 0;
};
class Truck: public Car{
     private:
          int maxWeight;
     public:
          Truck(int id, int maxWeight, const string& tempOwner = "NotLeased"):Car(id,tempOwner),maxWeight(maxWeight){}     
          Truck(const Truck& other)=default;
          Truck& operator= (const Truck& other) = default;
          ~Truck() = default;// יקרא קוד להורס של אינט חדש שלו ורק אז לישן של האב.

          int calculatePrice(int days) const override{
               return days*(maxWeight+20);
          }
          void print(ostream& os) const override{
               os<<"Max weight on truck: "<<maxWeight<<endl;
          }
          Car* clone() const{
               return new Truck(*this);
          }
};
template <int N>
class PassengersCar: public Car{
     private:
          int numOfPassengers;
     public:
          PassengersCar<N>(int id,const string& tempOwner = "NotLeased"):Car(id,TempOwner),numOfPassengers(N){}
          Passengers(const PassengersCar& other) = default;
          PassengersCar& operaotr=(const PassengersCar& other) = default;
          ~PassengersCar() = default;


          int calculatePrice(int days) const override{
               return days*(100*numOfPassengers);
          }
          void print(ostream& os) const override{
               os<<"Number of passengers: "<<numOfPassengers<<endl;
          }
          Car* clone() const{
               return new PassengersCar<N>(*this);// יש פה אן גדול כי יצרנו אובייקט, צריך להגיד איזה
          }

};

typedef PassengersCar<2> PrivateCar;


class VehicleException: public std::exception{

};
class VehicleAlreadyExist: public VehicleException{

};
class VehicleAlreadyExist: public VehicleException{

}
class LeasingCompany{
     private:
          vector<Car*> vehicles;
     public:
          LeasingCompany() = default; // לוקטור יש קונסטרקטור משלו
          LeasingCompany(const LeasingCompany& other) = delete; 
          LeasingCompany& operator=(const LeasingCompany& other) = delete;
          ~LeasingCompany() = default;

          void	addVehicle(const Car& car){ // אפשר לשים קונסט בלי לחשוש כי קאר נוצר כבר קודם
               for(Car* vehicle: vehicles){
                    if( vehicle->getId()==car.getId()){
                         throw VehicleAlreadyExist();
                    }
               }
               vehicles.push_back(car.clone());// קלוון יגרום שהפוינטר יחיה לאורך כל התכנית
          };//הקלוון פותר את הבעיה שהכנסנו קונסט, ואנחנו עושים שכפול ואז אפשר לשנות את העותק
          


template <class Condition>
void leaseVehicle(const string& name, int days, int toPay, Condition condition){
     for(Car* vehicle: vehicles){
          if( (toPay>=vehicle->calculatePrice(days)) && condition((*vehicle)) )
               vehicle->setTempOwner(name);
               cout<<(*vehicle);
               return; 
     }
     throw CanNotFindAppropriateVehicle();

}
};


