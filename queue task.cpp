#include <iostream>
using namespace std;

const int queue_capacity = 5;

class Queue {
public:
    Queue() {
        front = rear = -1;
    }
    
    bool isEmpty() {
        return front == rear;
    }
    
    bool isFull() {
        return rear == queue_capacity - 1;
    }
    
    void enqueue(int value) {
        if (isFull()) {
            cout << "queue is Full" << endl;
        } else {
            myArray[++rear] = value;
        }
    }
    
    int dequeue() {
        if (isEmpty()) {
            cout << "queue is empty" << endl;
            return -1;
        } else {
            return myArray[++front];
        }
    }
    
    void display() {
        if (isEmpty()) {
            cout << "queue is empty" << endl;
        } else {
            cout << "queue elements: ";
            for (int i = front + 1; i <= rear; i++) {
                cout << myArray[i] << " ";
            }
            cout << endl;
        }
    }

private:
    int myArray[queue_capacity];
    int front, rear;
};

int main() {
    Queue q;
    q.enqueue(6);
    q.enqueue(12);
    q.enqueue(20);
    q.enqueue(47);
    q.enqueue(69);
    
    cout << "	queue  :  " << endl;
    q.display();  

    q.dequeue();
    cout << "after one dequeue    : " << endl;
    q.display(); 

    return 0;
}


