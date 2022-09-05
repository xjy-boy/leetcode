#include<iostream>
#include<vector>

using namespace std;


class MyCircularDeque {
private:
    int front = 0;
    int rear = 0;
    int size = 0;
    vector<int> data;
public:
    MyCircularDeque(int k) {
        data = vector<int>(k + 1, 0);
        size = k + 1;
    }

    bool insertFront(int value) {
        if (isFull())
        {
            return false;
        }
        front -= 1;
        if (front < 0)
        {
            front = size - 1;
        }
        data[front] = value;

        return true;
    }

    bool insertLast(int value) {
        if (isFull())
        {
            return false;
        }
        data[rear] = value;
        rear = (rear + 1) % size;
        return true;
    }

    bool deleteFront() {
        if (isEmpty())
        {
            return false;
        }
        front = (front + 1) % size;
        return true;
    }

    bool deleteLast() {
        if (isEmpty())
        {
            return false;
        }

        rear -= 1;
        if (rear < 0)
        {
            rear = size - 1;
        }

        return true;
    }

    int getFront() {
        if (isEmpty())
        {
            return -1;
        }
        else
        {
            return data[front];
        }
    }

    int getRear() {
        if (isEmpty())
        {
            return -1;
        }
        else if (rear == 0)
        {
            return data.back();
        }
        else
        {
            return data[rear - 1];
        }
    }

    bool isEmpty() {
        return front == rear;
    }

    bool isFull() {
        return (rear + 1) % size == front;
    }
};