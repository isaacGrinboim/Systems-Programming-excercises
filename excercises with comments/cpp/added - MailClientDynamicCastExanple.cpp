using namespace std;
#include <stdio.h>
#include <iostream>
#include <vector>

class Client{
    public:
        virtual ~Client(){}
        virtual void processEvent(const Event& event){
            cout<<event.description();
        }
};
class MailClient: public Client{
    public:
        void processEvent(const Event& event) override{
            const NewMailEvent *mailEvent = dynamic_cast<NewMailEvent*>(&event); 
            if(mailEvent != nullptr)
                cout<<event.description();
            else
               throw BadEvent();
        }
};



class Server{
    private:
        std::vector<Client*> clients;
    public:
        Server()=default;
        ~Server() = default;
        Server(const Server& server) = delete;
        Server& operator=(const Server& server) = delete;

        void register(Clients* c){
            for(int i=0; i<clients.size(); i++){
                if(Clients[i]==c){return;}
            }
            clients.assign(c);
            }
        void notify(const Event& event){
            for(const Client* c :clients){
                clients[c].processEvent(event);
            }
        }    

};











class Event {
private:


public:
virtual std::string description() const { return ""; }; 

};

class Client {
public:
    
    virtual ~Client() {}

    virtual void processEvent(const Event& event){
        cout<<event.description();
    } 

};
class Apple: public Client{
    private:
        std::string name = "APPLE";
    public:
        Apple()=default;
        ~Apple()=default;

};
class Server {
    private:
        std::vector<Client*> clients;
            
    public:
        Server() = default;
        ~Server() = default;
        
        void registeer(Client *c){
            if(!clients.contain(c))
                clients.assign(c);
        };
        void notify(Event event){
            for(Client* c: clients)
            {

            }
        }
};


class A{
    A(){cout<<"constructor A"<<endl;}
    ~A(){cout<<"destructor A"<<endl;}

};


int main()
{
    
    Complex* pArray = new Complex[3];
    for(int i = 0;i<3;i++)
    {
        pArray[i].print_complex();
    }
    Complex e(pArray[1]);
    e.print_complex();
    Complex::show();

    return 0;
}


