class InvalidDivision: public exception{
     const char* what() const override{
          return "Cannot divide by 0!";
     }
};

class Divides: public Cond<int>{
private:
     int n;
public:
     Divides(int n):Cond<int>(n){
          if(n==0){throw InvalidDivision();}
     }
     bool operator()(int m)const override{  
          return m%n==0;
     }
};

template<class T>
class Cond{
private:
     T n;
public:
     Cond(const T& n):n(n){}
     virtual ~Cond() = default;
     virtual bool operator()(const T& m)const{
          return true;
     }
};

template <class T>
class CondAnd: public Cond<T>{
private:
     Cond<T> cond1;
     Cond<T> cond2;
public:
     CondAnd(const Cond<T>& c1, const Cond<T>& c2):cond1(c1),cond2(2){}
     bool operator()(const T& k)const override{         
          return cond1(k)&&cond2(k);
     }
};
template<class T>
CondAnd operator&&(const Cond& a, const Cond& b)const{
     return CondAnd<T>(a,b);
     }