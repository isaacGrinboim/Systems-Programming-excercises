#include <iostream>
#include <vector>
#include <memory>
using std::string;
using std::cout;

template <class T>
class DynamicArray{
private:
    T* array;
    InsertMode mode;
public:
    enum InsertMode{INSERT_LAST,INSERT_FIRST};

    DynamicArray();
    DynamicArray(const DynamicArray& other);
    DynamicArray& operator=(const DynamicArray& other);
    ~DynamicArray();

    T& operator[](int index);
    const T& operator[](int index) const;
    DynamicArray& operator<<(const T& item);
    void setInsertPos(InsertMode mode);
    void remove(int index);
    int size() const;
};

template <class T, typename Condition>
bool isConditionallySorted(const DynamicArray& array, Condition condition){
    bool result = true;
    DynamicArray temp_array = array;
    for(int i=0; i<array.size(); i++){
        if(condition(array[i])){
            temp_array<<array[i];
        }
    }
    for(int i=0; i<temp_array.size()-1; i++){
        if(temp_array[i+1]<temp_array[i])
        result = false;
    }
    return result;
};
class DevidesBy{
    private:
        int x;
    public:
       DevidesBy(int x):x(x){}
       bool operator()(int nominator){
        return nominator%x==0;
       } 
};

bool isSortedX(const DynamicArray<int>& arr, int x){
    DevidesBy devidesBy_x(x);
    return isConditionallySorted(arr,devidesBy_x);
}








int main()
{

    const int a = 3;

    int b = a;

    return 0;
}