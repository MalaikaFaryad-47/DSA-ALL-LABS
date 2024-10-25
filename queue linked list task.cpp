#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    
    Node(int value) {
        data = value;
        next = NULL;
    }
};

class Queue {
public:
    Queue() {
        front = NULL;
        rear = NULL;
    }
    
    bool isEmpty() {
        return front == NULL;
    }
    
    void enqueue(int value) {
        Node* newNode = new Node(value);
        if (isEmpty()) {
            front = rear = newNode;
        } else {
            rear->next = newNode;
            rear = newNode;
        }
    }
    
    int dequeue() {
        if (isEmpty()) {
            cout << "queue is empty" << endl;
            return -1;
        } else {
            Node* temp = front;
            int removedValue = temp->data;
            front = front->next;
            if (front == NULL) {
                rear = NULL;
            }
            delete temp;
            return removedValue;
        }
    }
    
    void display() {
        if (isEmpty()) {
            cout << "queue is empty" << endl;
        } else {
            Node* temp = front;
            cout << "queue elements: ";
            while (temp != NULL) {
                cout << temp->data << " ";
                temp = temp->next;
            }
            cout << endl;
        }
    }

private:
    Node* front;
    Node* rear;
};

int main() {
    Queue q;
    q.enqueue(6);
    q.enqueue(15);
    q.enqueue(20);
    q.enqueue(47);
    q.enqueue(69);
    
    
    cout << "after enqueueing 6, 15, and 20:" << endl;
    q.display();

    q.dequeue();
    cout << "after one dequeue operation:" << endl;
    q.display();

    return 0;
}
