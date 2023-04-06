#include <iostream>
#include <stdexcept>
#include <cstdlib>
#include <chrono>

using namespace std;

class stack_arr {
    //this class of stack is implemented using arrays
    int *arr;
    int size, top;
public:
    stack_arr(int size) {
        this->top = -1;
        this->size = size;
        this->arr = new int[size];
    }

    bool Push(int number) {
        this->top = this->top + 1;

        if ((this->top + 1) > size) {
            cout << "Error \"Stack Overflow\"" << endl;
            return false;

        } else {
            this->arr[this->top] = number;
            return true;
        }
    }

    int Pop() {


        if (this->isEmpty()) {
            //throw std::out_of_range("Array index out of bounds!");
            cout << "Error \"Stack Underflow\"" << endl;
        } else {
            if (isFull()){
                top = this->size-1;
                return this->arr[(this->top--)];
            }
            else{
                return this->arr[(this->top--)];
            }

        }
    }

    bool isEmpty() {
        //returns true for empty stack ,return false otherwise
        if (this->top <= -1) return true;
        else return false;
    }

    bool isFull() {
        if ((this->top + 1) >= this->size) return true;
        else return false;
    }

    void Display() {
        if (!this->isEmpty() && !this->isFull()) {
            for (int i = 0; i <= top; i++) {
                cout << arr[i] << " ";
            }
            cout << endl;
        }
        else if((!this->isEmpty() && this->isFull())){
            for (int i = 0; i <this->size; i++) {
                cout << this->arr[i] << " ";
            }
        }

        else cout << "Empty stack" << endl;

    }

    void StackTop() {
        if (!this->isEmpty() && !this->isFull()) {
            cout << this->arr[this->top] << endl;
        } else if (!this->isEmpty() && this->isFull()) {
            cout << this->arr[this->size - 1] << endl;
        } else cout << "Empty Stack" << endl;
    }
};

int main() {
    int size;
    cout<<"enter the size of array: ";
    cin>> size;
    stack_arr *nw = new stack_arr(size);

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
