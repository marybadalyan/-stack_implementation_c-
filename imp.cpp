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
        head = new Node<T>(value,head);
        if(l_size == 1) tail = head;
        ++l_size;
    }
    void pop_front(){
        assert(!isEmpty());
        //if(l_size == 1) tail = nullptr;
        Node<T>* tmp = head;
        if(head->next)
            head = head->next;
        else head = nullptr;

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
        return head == nullptr;
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
    void push_back(const T& value){
        Node<T>* newnode = new Node<T>(value,nullptr);
        if(isEmpty()){
            head = tail = newnode;
        }
        else{
            tail->next = newnode;
            tail = newnode;
        }
        ++l_size;
    }

    void pop_back(){
        assert(!isEmpty());
        Node<T>* tmp_tail = tail;
        if(l_size == 1)
        {
            tail = nullptr;
        }
        else{
            Node<T>* tmp = head;
            while(tmp->next != tail)
            {
                tmp = tmp->next;
            }
        
            tail = tmp;
            tail->next = nullptr;
        }
        --l_size;
        delete tmp_tail;
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
    myList.clear();
    myList.push_back(10);
    myList.push_back(20);
    myList.push_back(30);
    myList.pop_back();
    myList.pop_back();
    myList.print(); 
    std::cout<<myList.size();
    return 0;
}
