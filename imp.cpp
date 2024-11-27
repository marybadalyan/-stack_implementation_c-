#include <iostream>
#include "Node.cpp"
#include <cassert>

template <typename T>
class List
{
public:
    List():head(nullptr),l_size(0)
    {}
    ~List(){
        clear();
    }

    void push(const T& value){
        ++l_size;
        head = new Node<T>(value,head);
    }
    void pop(){
        assert(!isEmpty());
        --l_size;
        Node<T>* tmp = head;
        head = head->next;
        delete tmp;
    }

    T top() const{
        assert(!isEmpty());
        return head->value;
    }

    bool isEmpty() const{
        return l_size == 0; 
    }
    void clear(){
        while(!isEmpty()){
            pop();
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

private:
    Node<T>* head;
    int l_size;
};

int main() {
    List<int> myList;

    myList.push(10);
    myList.push(20);
    myList.push(30);

    myList.print(); 

    std::cout << "List contains 20? " << (myList.find(20) ? "Yes" : "No") << "\n";

    myList.pop();
    myList.print(); 

    myList.clear();
    std::cout << "Is list empty? " << (myList.isEmpty() ? "Yes" : "No") << "\n"; 

    return 0;
}
