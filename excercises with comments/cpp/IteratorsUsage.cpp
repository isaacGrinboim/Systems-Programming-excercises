#include <iostream>
#include <vector>


class IsFar{
    private:
        double distance;
    public:
        IsFar(double distance):distance(distance){}
        bool operator()(const Point& point) const{
            return point.distance(Point(0,0))>distance;
        }
};



template <class T>
class ConditionalStack: public Stack<T>{
    public:

        class NotFound: public Stack<T>::Exception{
            const char* what() const override{
                return "not found";
            }
        }


        ConditionalStack(int max_size = 100):Stack<T>(max_size){}
        template<class Filter>
        void popConditional(Filter filter){
            while(getSize()>0 && !filter(top())){
                pop();
            }
            if(getSize()==0){
                throw NotFound();
            }

        }
};

template<class Iterator>
void printContainer(Iterator begin, Iterator end, std::ostream os){
    os<<"[";

    for(Iterator i=begin; i!=end-1; i++){
        os<<*i<<',';
    }
    os<< *(end-1);

    os<<"]";      
}

template <class T>
class stack {
T* array;
int next_index;
int max_size;


    public:
        void printStack(std::ostream& os) const{
            printContainer(array,array+max_size,std::cout)
        }
        
        friend std::ostream& operator<<(ostream& os, const Stack<T>& stack){
            stack.printStack(os);
            return os;
        }
};



int main(){

    // std::vector<int> a;
    // for(int i=0; i<10; i++)
    // a.push_back(i);
    
    int a[3]={1,2,3};
    printContainer(a,a+3,std::cout);
    return 0;
}












// class Point {
// public:
// // creates a new point with coordinates x,y;
// public: Point(double x, double y);
// // returns the distance between the current point and another point.
// double distance(const Point& p) const;
// };
































// template<class T>
// friend ostream& operator<<(ostream& os, const stack<T>& s){

// }












// template <class Iterator>
// void printGeneric(Iterator begin, Iterator end, std::ostream& os) {
// Iterator first = begin;
// os << "[";
// for (Iterator current = begin; current != end; ++current) {
// if (current != first)
// os << " ,";
// os << current;
// }
// os << "]";
// }






// template<class T>
// void printLine(T* container, std::ostream& os){
//     os<<"[";

//     for(T& element = container.std::begin();
// element != container.std::end(); ++element)
// {
//         os<<element;
        
//     }
//     os<<"]";

// }










template <class T>
class ConditionalStack: public Stack{
public:
    ConditionalStack(int max_size = 100):Stack<T>(max_size){}
    class NotFound: public Stack<T>::Exception{
        const char* what() const override{return "not found";}
    }

    template <class Condition>
    void popConditional(Condition c) {
        while(getSize()>0 && !c(top()))
        {
            pop();
        }
        if (getSize == 0){throw NotFound();} 

    }



// };










class IsFar{
private:
    double distance;

public:
    IsFar(const double distance):distance(distance){}
    bool operator()(const Point& point) const{
        return point.distance(Point(0,0))>distance;
    }
    
// };

// class Point {
// private:
// double x;
// double y;
// public:
//     // creates a new point with coordinates x,y;
//     Point(double x, double y):x(x),y(y){}  

//     // returns the distance between the current point and another point.
//     double distance(const Point& p) const;
// };













//function object example - devides by:
class DevidesBy{
    private:
        int n;
    public:
        DevidesBy(const int n):n(n){}
        bool operator()(int m)const{
            return m%n==0;
        }    
};


int main(){
    DevidesBy devidesBy_13(13);
    int a = 150;
    int sum=0;
    for(int i=1; i<=a; i++){
        if(devidesBy_13(i)){
            sum++;
       }
    }
    std::cout<<sum;
    return 0;
}







