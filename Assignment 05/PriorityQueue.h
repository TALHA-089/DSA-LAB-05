#pragma Once
#include<iostream>
#include <string>
#include <sstream>
#include <vector>
using namespace std;

template<class Type>
class PriorityQueue {

private:
    int front;
    int rear;
    int size;
    Type* queue;

public:
    PriorityQueue(int size) {
        this->size = size;
        rear = front = -1;
        queue = new Type[this->size];
    }

    bool isEmpty() {
        return (rear == -1 && front == -1);
    }

    bool isFull() {
        return (rear == size - 1);
    }

    void insert(Type item) {
        if (isFull()) {
            cout << "Queue is full, Please remove some items." << endl;
        }
        else {
            if (isEmpty()) {
                rear = front = 0;
            }
            else {
                rear++;
            }
            queue[rear] = item;
        }
    }

    void remove(Type& item) { 
        if (isEmpty()) {
            cout << "Queue is Empty, please insert an item before removal" << endl;
        }
        else {
            item = queue[front];
            if (front == rear) {
                rear = front = -1; 
            }
            else {
                front++;
            }
        }
    }

    int getSize() {
        return this->size;
    }

    ~PriorityQueue() {
        delete[] queue; 
    }
};