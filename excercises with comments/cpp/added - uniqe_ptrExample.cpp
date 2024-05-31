#include <vector>
#include <memory>
#include <iostream>


class Player{
     public:
          virtual void printDetails() const{
               std::cout << 1 << std::endl;
          }

};
class Wizard:  public Player{
     
     public:
          void printDetails() const override{
               std::cout<<3;
          }
};


int main()
{
     std::vector<std::unique_ptr<Player>> players;          //יש סיבה שיימחק הזכרון בסוף

     std::unique_ptr<Player> a_ptr(new Player());
     players.push_back(std::move(a_ptr));
     std::unique_ptr<Player> w_ptr(   (Player*)  new Wizard());//casting
     players.push_back(std::move(w_ptr));

     for(const std::unique_ptr<Player>& player: players){ //  קונסט רפרנס כי אין מימוש להעתקה
          player->printDetails(); 
     }

    


return 0;

}