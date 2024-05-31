#include <iostream>
#include <vector>
#include <memory>
using std::string;
using std::cout;

template <class T>
class Node{
private:
    T data;
    Node* next;
public:

    Node()=delete;
    Node(const T& init_data){
        data = init_data;
    }
    Node(const Node& node);
    ~Node() = default;
    Node& operator=(const Node& node);

    T getData(){return data;}
    void setData(const T& new_data){data = new_data;}

    Node* getNext(){return next;} 
    void setNext(Node* new_next){}

};

template<class T>
class LinkedList{
private:
    Node<T>* head;
    Node<T>* tail;
public:
    LinkedList():head(NULL),tail(NULL){}
    explicit LinkedList(T& item):head(&item),tail(&item){}
     //לזכור שבגלל שפה אני לא רוצה המרה של 3 לרשימה מקושרת  (יכל לקרות כי יש קונסטרקטור שיכול לקבל 3)
   
    LinkedList(const LinkedList& other){
        tail = head = new Node<T>(*(other.head));

        Node<T>* current = other.head->getNext;
        while(current){
            insertToTail(current->getData());
            current = current->getNext();
        }
    }
  
    LinkedList& operator = (const LinkedList& other);
    void insertToHead(T& item);

    class bad_alloc: public std::exception{};
    void insertToTail(T& item){
        Node<T>* new_tail = new Node(item);
        if(!new_tail){throw bad_alloc();}
        tail->setNext(new_tail);
        tail = new_tail;

    }
    void print();
    void printBackwards(){
        LinkedList<T> temp = LinkedList<T>();
        Node<T>* current = head;
        while(current)
        {
            temp.insertToHead(current->getData());
            current= current->getNext();
        }
        temp.print();
    }
    const Node<T>* getHead()const {
        return head;
    }
    const Node<T>* getTail()const {
        return tail;
    }

    friend LinkedList<T> operator+(const LinkedList& a,const LinkedList& b){
        LinkedList<T> newList = LinkedList<T>();
        a_current = a.getHead();
        b_current = b.getHead();
        T carry = 0;
        while(a_current != NULL || b_current != NULL){

            T sum = carry;
            if(a_current !=NULL){
                sum+=a_current->getData();
                a_current= a_current->getNext();
            }
            if(b_current != NULL){
                sum+=b_current->getData();
                b_current= b_current->getNext();
            }
            newList.insertToTail(sum % 10);
            carry = sum /10;
            
        }
        return newList;
    }


};


int main()
{

    return 0;
}