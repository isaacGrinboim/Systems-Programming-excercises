#include <iostream>

using namespace std;
class House{
protected:

    string street;
    int houseNum;
    int ownerId;
    float area;   
public:
     //סימטריה - כי אם כן הייתי רוצה המרה, House +3 אז הייתי רוצה אולי גם מבצד השני
     House(const string& street, int HouseNum, int ownerId, float area);
     House(const House& other): street(other.street){
          
     }
     House& operator=(const House& other){
          //עוברים אחד אחד. // אם אין משהו מתוחכם שאנחנו צריכים לדאוג לזכרון שלו, גקכשו
     }
     virtual ~House() = default; //למחוק את כל השדות שאולי  House לא מכיר.
     House&
     int getId()const;
     virtual float calcArnona() const = 0;// אני לא יודע לממד במחלקת אב, ולכן אין מימוש - =0
     friend ostream& operator<<(ostream& os,const House& house);// רפרנס לאוסטרים כי - זה אובייקט אי אפשר להעתיק
     //אם הייתי מעביר וליו זה היה קורא לקופי קונסטרקטור של האוס ואולי מוחק דברים
     virtual void print(ostream& os){ //יש מצב שנראה אחר כך שצריך שהיא תהיה וירטואלית
          os<<street<<" "<<houseNum;// זה נוותן אפשרות להבדלים.
     }

     

};
ostream& operator<<(ostream& os,const House& house){
     os<<house.ownerId;
}



class Office: public House{
     private:
          float parkingArea;
     public:
     Office(const string& street,int houseNum, int ownerId, float area, float parkingArea)
     : House(street,houseNum,ownerId,area),parkingArea(parkingArea){}
     float calcArnona() const override{
          מימוש
     }
     };

template <int N>
class Home: public House{
     private:
          int identities [N]; // לא מאתחלים כאן
     Home(const string& street,int houseNum, int ownerId, float area, int idents[N]):
     House(street,houseNum,ownerId,area){
          for (int i=0; i<N; ++i){
               identities[i]=ident[i];
          }
     }
     //קופי צריך מימוש בגל המערך.
     //השמה גם
     class CityHall{
          private: 
               vector<House*> houses; // כי אולי יש בתים שונים
          public:
               CityHall() = default;
               void addHouse(House* to_add);
               float calcTax(const list<int>& idents){
                    for(int id : idents){
                         for(House* house : houses){
                              
                         }
                    }
               }
          
     };
      

};


int main(){
     House house1("amir", 1, 2, 3.0);
     cout << house1;
     
     return 0;
}