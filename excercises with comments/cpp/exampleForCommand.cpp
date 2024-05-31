using namespace std;
#include <memory>
#include <string>
#include <map>
#include <vector>
//כל העניין זה שיוצרים אינסטנסים של אובייקט אקשן
//ואז אפשר לרשת ממנו, וקיימים אובייקטים שאני אומר להם לבצע קומנד
//בשביל לבצע אנדו, יש וקטור של אקשנס ואיתו אפשר להגיד לפי האחרון בוקטור
//לאיזה אנדו לקרוא
class BankSystem {
private:
     map<int, unique_ptr<Account>> accounts;
public:
     BankSystem() = default;
     int addAccount(const string& name, double balance = 0);
     void deposit(int id, double money); // כנראה שגם הלקוחות יהיו מוגנים אם היה קונסט
     void withdraw(int id, double money);
     void undoLastAction(int id);
     void transfer(int source_id,int dest_id, double money);
     double getBalance(int id) const;

};

void BankSystem::transfer(int source_id,int dest_id, double money){
     Account* user = accounts[source_id].get();
     Account* reciever = accounts[dest_id].get();
     Transfer* trans = new Transfer(money,user,reciever);
     trans->apply();
     unique_ptr<Action> trans_ptr((Action*) trans);
     user->actions.push_back(move(trans_ptr));
}


class Account{
     int id;
     string name;

public:

     Account(const string& name, int id, double balance = 0):name(name), id(id), balance(balance){}
     Account(const Account& other) = delete;
     Account& operator=(const Account& other) = delete;

     double balance;
     vector<unique_ptr<Action>> actions;

};

class Action{
protected:
     double usedMoney;
     Account* user;     
public:
     Action(double money, Account* user):usedMoney(money),user(user){}
     virtual ~Action();
     virtual void undo() = 0;
     virtual void apply() = 0;
};
class Transfer: public Action{
Account* reciever;
public:
     Transfer(double money, Account* user, Account* reciever):
     Action(money, user),reciever(reciever);
     void apply() override{
          user->balance -= usedMoney;
          reciever->balance += usedMoney;
     }
     void undo() override{
          user->balance += usedMoney;
          reciever->balance -= usedMoney;
     }
};

