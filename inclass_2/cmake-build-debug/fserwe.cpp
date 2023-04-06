#include <iostream>
using namespace std;
class node{
    int data;
    node *next;
    node *previous;
    node(int data){
        this->data=data;
        this->next = NULL;
        this->previous = NULL;
        //this->previous =NULL;
    };
    class linkedList{
        node * head = NULL;
        node * tail  = NULL;
        bool add_data_to_tail(int data){
            node * newNode = new node(data);
            if (head==NULL){

                head = newNode;
                tail = newNode;
                return true;
            }
            else{
                node * temp = head;
                while(temp->next!=NULL){
                    temp = temp->next;
                }
                newNode->previous =temp;
                temp->next = newNode;

                tail = temp->next;
                return true;
            }

        }
        int pop_data_from_tail(int ){
            node * temp = tail;
            if (temp!=head){
                (temp->previous)->next=NULL;
                tail=temp->previous ;
                return temp->data;
            }
            else{
                return head->data;
            }
        }

    };
    int main() {
        linkedList * ll = new linkedList();
        return 0;
    }
