
template <class T>
class Matrix {
 T* elems; // the elements of the matrix, row-by-row
 int n, m; // the height (n) and width (m) of the matrix
public:
     class InvalidArg: public std::exception {}
     class SizeMismatch: public std::exception {}
     Matrix(int n, int m):n(n),m(m),elem(new T[n*m]){
          if(n<=0 || m<=0){
               throw InvalidArg();
          if(!elems){throw bad_alloc();}     
     }
     Matrix(const Matrix& other){
          n=other.n;
          m=other.m;
          elems = new T[other.n,other.m];
          for(int i = 0; i<n*m; ++i){
               elems[i] = other.elems[i];
          }
     }
     T& operator()(int i, int j){
          return Matrix.elems(i*m+j);
     }
     const T& operator()(int i, int j)const{
          return Matrix.elems(i*m+j);
     }
     static Matrix diag(int size, const T& value){
          result = Matrix(size,size);
          for(int i=0; i<size; i++){
               result(i,i) = value;
               //result.elems[i*(size+1)] = value;
          }
          return result; 
     }
     Matrix<T>& operator+=(const Matrix<T>& b){
          for(int i=0; i<n*m; ++i){
               elems[i]+=b.elems[i];// היה צריך לעשות שתי לולאות
          }                        // () ואז היינו משתמשים באופרטור
          return *this;
     }
     template <class T>
     friend Matrix<T> operator+(const Matrix& a, const Matrix& b){
          if(a.n!=b.n || a.m!=b.m){
               throw SizeMismatch();
          }
          Matrix<T> result = a;
          result+=b;
          return result;
     }


 }
};
