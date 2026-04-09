#include <iostream>
using namespace std;

// Abstract Class
template <class T>
class QueueADT {
public:
    virtual void enqueue(T) = 0;
    virtual T dequeue() = 0;
    virtual bool isFull() = 0;
    virtual bool isEmpty() = 0;
    virtual void display() = 0;
};

struct Car {
    string carNumber;
    int hours;
    float rate;
    float bill;
};

template <class T>
class CircularQueue : public QueueADT<T>
{
private:
    int front, rear, size;
    T* arr;

public:
    CircularQueue(int s)
{
        size = s;
        arr = new T[size];
        front = rear = -1;
    }

    bool isFull() {
        return (rear + 1) % size == front;
    }

    bool isEmpty() {
        return front == -1;
    }

    void enqueue(T value) {
        if (isFull()) {
            cout << "Parking is full"<<endl;
            return;
        }
        if (isEmpty())
            front = 0;

        rear = (rear + 1) % size;
        arr[rear] = value;
        cout << "Car Parked Successfully"<<endl;
    }

    T dequeue() {
        if (isEmpty()) {
            cout << "No Car Found"<<endl;
            return T();
        }

        T temp = arr[front];

        if (front == rear)
            front = rear = -1;
        else
            front = (front + 1) % size;

        return temp;
    }

    void display() {
        if (isEmpty()) {
            cout << "No Cars Parked"<<endl;
            return;
        }

        int i = front;
        while (true) {
            cout << "Car: " << arr[i].carNumber
                 << " Hours: " << arr[i].hours
                 << " Bill: " << arr[i].bill << endl;

            if (i == rear)
                break;
            i = (i + 1) % size;
        }
    }
};

#endif
