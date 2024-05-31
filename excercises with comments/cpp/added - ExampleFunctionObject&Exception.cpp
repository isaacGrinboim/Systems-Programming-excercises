#include <iostream>
#include <vector>
#include <memory>
using std::string;
using std::cout;

template <class T>
class Cond {
    public:
        virtual bool operator()(const T& x)const{
            return true;
        }
        virtual ~Cond() = default;
    };

template <class T>
class CondAnd: public Cond<T>{
    private:
        Cond<T> cond1;
        Cond<T> cond2;
    public:
        CondAnd(const Cond<T>& a,const Cond<T>& b):cond1(a),cond2(b){}
        
        bool operator()(const T& x)const override{
            return cond1(x)&&cond2(x);
        }
        ~CondAnd()=default;
};
template <class T>
CondAnd<T> operator&&(const Cond<T>& a,const Cond<T>& b){
            return CondAnd<T>(a,b);
        }

class DevideByZero: public std::exception{
    const char* what() const noexcept override{
        return "Cannot devide by 0!";
    }
};

class Devides : public Cond<int>{
    private:
        int k;
    public:
        Devides(int k):k(k){}
        bool operator()(const int x)const override{
            if(k==0){throw DevideByZero();}
            return x%k==0;
        }
        
        ~Devides() = default ;
    };
    







int main(){
    Devides a(3);
    Devides b(0);
    CondAnd<int> combined = a && b;
    cout<<combined(21)<<std::endl<<combined(0);


    return 0;
}