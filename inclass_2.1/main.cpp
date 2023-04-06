#include <iostream>
#include <chrono>
#include <cstdlib>
using namespace std;
class Node {
public:
    int data;
    Node* next;

    Node(int data) {
        this->data = data;
        next = NULL;
    }
};

class LinkedList {
private:
    Node* head;
    Node* tail;
    int size;

public:
    LinkedList() {
        head = NULL;
        tail = NULL;
        size = 0;
    }

    void add_to_tail(int value) {
        Node* new_node = new Node(value);
        if (head == NULL) {
            head = new_node;
            tail = new_node;
        }
        else {
            tail->next = new_node;
            tail = new_node;
        }
        size++;
    }

    void pop_from_tail() {
        if (head == NULL) {
            cout << "The list is empty!" <<endl;
            return;
        }
        else if (head == tail) {
            delete head;
            head = NULL;
            tail = NULL;
        }
        else {
            Node* current = head;
            while (current->next != tail) {
                current = current->next;
            }
            delete tail;
            tail = current;
            tail->next = NULL;
        }
        size--;
    }

    void display() {
        if (head == NULL) {
            std::cout << "The list is empty!" << std::endl;
            return;
        }
        else {
            Node* current = head;
            while (current != NULL) {
                cout << current->data << " ";
                current = current->next;
            }
            cout << endl;
        }
    }

    int get_size() {
        return size;
    }
    void printTail(){
        cout<<this->tail->data<<endl;
    }
};
class stack{
    int top;
    int size;
    LinkedList * ll = new LinkedList();
public:
    stack(int size){
        this->size = size;
        top = 0; //here we don't need to do it the way we did it in the array
    }
    bool isEmpty(){
        if (top==0) return true;
        else return false;
    }
    bool isFull(){
        if (top==size) return true;
        else return false;
    }
    bool Push(int data){
        if (!isFull()){
            top++;
            this->ll->add_to_tail(data);

            return true;
        }
        else{
            cout<<"Errror \"Stack Overflow\""<<endl;
            return false;
        }
    }

    void Display(){
        this->ll->display();
    }
    void Pop(){
        if (top>0){
            this->ll->pop_from_tail();
        }
        else{
            cout<<"Error \"Stack Underflow\"";
        }
    }
    void StackTop(){
        this->ll->printTail();
    }


};

int main(){
    int size;
    cout<<"enter the size of array: ";
    cin>> size;
    stack *nw = new stack(size);

    auto start = std::chrono::high_resolution_clock::now(); // get the starting time

    for (int i=0;i<10;i++){
        nw->Push(rand() % 10000);
    }
    nw->Display();
    for (int i=0;i<5;i++){
        nw->Pop();
    }
    nw->Display();
    for (int i=0;i<4;i++){
        nw->Push(rand() % 10000);
    }



    auto stop = std::chrono::high_resolution_clock::now(); // get the ending time
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(
            stop - start); // calculate the elapsed time
    cout<<"Total time elapsed :"<<duration.count()<<" micro seconds"<<endl;

    return 0;
}
