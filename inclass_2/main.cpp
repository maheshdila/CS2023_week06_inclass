#include <iostream>

using namespace std;

class node {
public:
    node(int data) {
        this->data = data;
        this->next = NULL;
        //this->previous = NULL;
        //this->previous =NULL;
    }

    //node *previous;
    node *next;
    int data;
};

class linkedList {
public:
    node *head = NULL;
    node *tail = NULL;

public:
    void printdata(){
        node * temp = this->head;
        while(temp->next!=NULL){
            cout<<temp->data<<" ";
            temp = temp->next;
        }
    }

    bool add_data_to_tail(int data) {
        node *newNode = new node(data);
        if (head == NULL) {

            head = newNode;
            tail = newNode;
            return true;
        } else {
            newNode->previous = tail;
            tail->next = newNode;
            tail = newNode;
            return true;
        }

    }

    int pop_data_from_tail() {
        node *temp = tail;
        if (temp != head) {
            (temp->previous)->next = NULL;
            tail = temp->previous;
            return temp->data;
        } else {
            return head->data;
        }
    }
};

class stack{
    int top;
    int size;
    linkedList * ll = new linkedList();
public:
    stack(int size){
        this->size = size;
        top = 0; //
    }
    bool isEmpty(){
        if (top==0) return true;
        else return false;
    }
    bool isFull(){
        if (top==size) return true;
        else return false;
    }
    bool push(int data){
        if (!isFull()){

            top++;
            this->ll->add_data_to_tail(data);

            return true;

        }
        else{
            cout<<"Errror \"Stack Overflow\""<<endl;
            return false;
        }
    }
    int pop(){
        if (0<this->top){
            this->top--;
            //cout<<this->ll->pop_data_from_tail();
            return this->ll->pop_data_from_tail();

        }
        else{
            cout<<"Error \"Stack UnderFlow";
            return NULL;
        }
    }
    int StackTop(){
        if(!this->isEmpty()){
            return this->ll->tail->data;
        }
        else {
            cout<<"Stack is empty";
            return NULL;
        }
    }
    void Display(){

        node * temp = this->ll->head;
        for (int i=0;i<top;i++){
            cout<<temp->data<<" ";
            temp = temp->next;
        }
        cout<<endl;
    }



};


int main() {
    linkedList* lol = new linkedList;
    lol->add_data_to_tail(90);
    lol->add_data_to_tail(100);
    lol->printdata();
    /*stack * lol = new stack(5);
    //ll->pop();
    cout<<lol->isEmpty()<<endl;
    lol->push(45);
    cout<<lol->pop()<<endl;
    cout<<lol->isEmpty()<<endl;
    cout<<lol->pop()<<endl;
    lol->push(48);
    lol->push(49);
    lol->push(50);
    lol->Display();
*/

    return 0;
}
