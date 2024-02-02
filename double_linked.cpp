#include <string>
#include <iostream>
#include <stdio.h>

using namespace std;

class DLL{
    struct Element {
        int data;
        Element* prev;
        Element* next;
    };

    Element *head;
    Element *tail;

    public:
        DLL() { head = tail = nullptr;}
        ~DLL() {}
        bool empty() {return (head == nullptr && tail == nullptr);}
        void addLast(int data);
        void printer();

};

void DLL::addLast(int data){
    if (tail == nullptr) {
        // Create a new element dynamically
        Element* newElement = new Element;
        newElement->data = data;
        newElement->next = nullptr;
        newElement->prev = nullptr;

        head = tail = newElement;
    } else {
        Element* newElement = new Element;
        newElement->data = data;
        newElement->next = nullptr;
        newElement->prev = tail;
        tail->next = newElement;
        tail = newElement;
    }
}

void DLL::printer(){
    if(head != nullptr){

        Element * current = head;

        while(current != nullptr){
            int data;
            int ndata;
            data = current->data;
            cout << data;
            
            current = current->next;

        }
    }
}



int main()
{
   DLL Liste;
   Liste.addLast(5);
   Liste.addLast(3);
   Liste.addLast(9);
  
   Liste.printer();
   std::string str = Liste.empty() ? "true" : "false";
   std::cout << str;
   return 0;
}
