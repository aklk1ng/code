#include <bits/stdc++.h>

using namespace std;

class MyCircularQueue {
private:
  int front;
  int rear;
  int capacity;
  vector<int> elements;

public:
  MyCircularQueue(int k) {
    this->front = 0;
    this->rear = 0;
    this->capacity = k + 1;
    this->elements = vector<int>(capacity);
  }

  bool enQueue(int value) {
    if (isFull())
      return false;

    elements[rear] = value;
    rear = (rear + 1) % capacity;
    return true;
  }

  bool deQueue() {
    if (isEmpty())
      return false;

    front = (front + 1) % capacity;
    return true;
  }

  int Front() {
    if (isEmpty())
      return -1;
    return elements[front];
  }

  int Rear() {
    if (isEmpty())
      return -1;
    return elements[(rear - 1 + capacity) % capacity];
  }

  bool isEmpty() { return front == rear; }

  bool isFull() { return ((rear + 1) % capacity) == front; }
};
