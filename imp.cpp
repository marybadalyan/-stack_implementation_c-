#include <iostream>
#include "Node.cpp"
#include <cassert>

template <typename T>
class List
{
public:
    List():head(nullptr),l_size(0),tail(nullptr)
    {}
    ~List(){
        clear();
    }

    void push_front(const T& value){
        ++l_size;
        head = new Node<T>(value,head);
        if(l_size == 1) tail = head;
    }
    void pop_front(){
        assert(!isEmpty());
        if(l_size == 1) tail = nullptr;
        Node<T>* tmp = head;
        head = head->next;
        --l_size;
        delete tmp;
    }

    T front() const{
        assert(!isEmpty());
        return head->value;
    }

    T back() const{
        assert(!isEmpty());
        return tail->value;
    }

    bool isEmpty() const{
        return l_size == 0; 
    }
    void clear(){
        while(!isEmpty()){
            pop_front();
        }
    }

    int size() const{
        return l_size;
    }

    void print() const{
        Node<T>* tmp = head;
        while(tmp != nullptr){
            std::cout<< tmp->value<< " ";
            
            tmp = tmp->next;
        }
    }

    bool find(const T& value) const{
        Node<T>* tmp = head;
        while(tmp != nullptr){
            if(tmp->value == value) return true;

            tmp = tmp->next;
        }
        return false;
    }
    Node<T>* begin() const{
        assert(!isEmpty());
        return head;
    }
    Node<T>* end() const{
        assert(!isEmpty());
        return tail;
    }
    void push_back(){

    }

    void pop_back(){

    }
    void insert(){

    }
    void erase(){
        
    }
    void remove(){

    }
private:
    Node<T>* head;
    int l_size;
    Node<T>* tail;
};

int main() {
    List<int> myList;

    myList.push_front(10);
    myList.push_front(20);
    myList.push_front(30);

    myList.print(); 

    std::cout << "List contains 20? " << (myList.find(20) ? "Yes" : "No") << "\n";

    myList.pop_front();
    myList.print(); 

    myList.clear();
    std::cout << "Is list empty? " << (myList.isEmpty() ? "Yes" : "No") << "\n"; 
    myList.push_front(10);
    myList.push_front(20);
    myList.push_front(15);
    myList.push_front(30);
    myList.pop_front();
    std::cout << myList.begin()->value << " " << myList.end()->value << " ";
    std::cout<<myList.back();
    return 0;
}
