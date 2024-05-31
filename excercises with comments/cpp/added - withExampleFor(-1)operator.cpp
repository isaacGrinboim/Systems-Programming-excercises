#include <iostream>
#include <vector>
#include <cmath>
class BadDimension: public std::exception{
    
};

template <typename T>
class Point{
    private:
        std::vector<T> coordinates;
    public:
        Point(int dimension):coordinates(dimension){}
        Point(T* array, int size){
            for(int i=0;i<size;i++)
            {
                coordinates.push_back(array[i]);
            }
        }
        int getDimension() const{
            return coordinates.size();
        }
        Point& operator=(const Point& p){
            if(coordinates.size()!=p.getDimension()){throw BadDimension();}
            coordinates=p.coordinates;
            return *this;
        }
        std::ostream& print(std::ostream& os) const{
            os<<"{";
            for(int i=0;i<coordinates.size()-1;i++){
                os<<" "<<coordinates[i]<<",";
            }
            os<<" "<<coordinates[coordinates.size()-1]<<" }";
            return os;
        }
        
        friend std::ostream& operator<<(std::ostream& os, const Point<T>& p){
             p.print(os);
            return os;
        }
        T norm2sqr() const{
            T abs=T(0);
            for(int i=0; i<coordinates.size(); i++){
                abs+=std::pow(coordinates[i],2);
            }
            return abs;
        }
        Point& operator+=(const Point& p){
            if(coordinates.size()!=p.getDimension()){throw BadDimension();}
            for(int i=0; i<coordinates.size(); i++){
                coordinates[i]+=p.coordinates[i];
            }
            return *this;

        //    דר קיילה, מודיעין שמואל הנביא 6
        }
        Point& operator*=(const T scalar){
            for(int i=0; i<coordinates.size(); i++){
                coordinates[i]*=scalar;
            }
            return *this;
        }

        
        Point& operator-(const Point& p){
            Point temp = p;
            for(int i=0; i<coordinates.size(); i++){
                coordinates[i]=-coordinates[i];
            }
            return *temp;
        }


        };  
        template<class T>
        Point<T>& operator+(const Point<T>& a, const Point<T>& b){
            return a+=b;
        } 
        template<class T>
        Point<T>& operator*(const int a, const Point<T>& b){
            return b*=a;
        }
        template<class T>
        Point<T>& operator*(const Point<T>& b, const int a){
            return b*=a;
        }
        

        int main()
        {
            double arr[2]={1,0};
            Point<double> a(arr,2);
            double arr2[2]={0,1};
            Point<double> b(arr2,2);
            
            

            // Point<double> b(2);
            // try{
            // b=a;} catch(const BadDimension& e){std::cout<<"dimensions aren't the same!"<<std::endl;}
            // a*=2.5;
            //Point c =            
            std::cout<<a*2<<std::endl;
            // std::cout<<"a sqare abs is: "<<b.norm2sqr()<<std::endl;
            // std::cout<<"a dimension is: "<<a.getDimension();


            return 0;
        }  
