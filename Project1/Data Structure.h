#pragma once

#include <iostream>
#include <string>
#include <stdexcept>
#include <vector>

using namespace std;

template <typename T>
class Node {
public:
    T data;
    Node* next;

    // Constructor
    Node(T value) {
        data = value;
        next = nullptr;
    }
};

template <typename T>
class LinkedList {
private:
    Node<T>* head;
    int size;
public:
    // Constructor
    LinkedList() : head(nullptr) { size = 0; }

    // Add a new element to the end of the list
    void append(T value) {
        Node<T>* newNode = new Node<T>(value);
        if (!head) {
            head = newNode;
            size = 1;
            return;
        }
        Node<T>* temp = head;
        while (temp->next) {
            temp = temp->next;
        }
        temp->next = newNode;
        size++;
    }

    // Remove an element by value
    void remove(T value) {
        if (!head) {
            cout << "List is empty!" << endl;
            return;
        }
        if (head->data == value) {
            Node<T>* temp = head;
            head = head->next;
            delete temp;
            size--;
            return;
        }
        Node<T>* temp = head;
        while (temp->next && temp->next->data != value) {
            temp = temp->next;
        }
        if (temp->next) {
            Node<T>* toDelete = temp->next;
            temp->next = temp->next->next;
            delete toDelete;
            size--;
        }
        else {
            cout << "Value not found in the list!" << endl;
        }
    }

    // Display the list
    void display() {
        if (!head) {
            cout << "List is empty!" << endl;
            return;
        }
        Node<T>* temp = head;
        while (temp) {
            cout << temp->data << endl;
            temp = temp->next;
        }
    }

    // peak head
    Node<T>* peak() {
        return head;
    }
    // get size
    int getSize() {
        return size;
    }
};


template <typename T>
class Stack {
private:
    T* arr;
    int top;
    int capacity;

public:
    Stack(int cap) : capacity(cap), top(-1) {
        arr = new T[capacity];
    }

    ~Stack() {
        delete[] arr;
    }

    bool isEmpty() const {
        return top == -1;
    }

    bool isFull() const {
        return top == capacity - 1;
    }

    void push(const T& value) {
        if (isFull()) {
            throw overflow_error("Stack overflow");
        }
        arr[++top] = value;
    }

    void pop() {
        if (isEmpty()) {
            throw underflow_error("Stack underflow");
        }
        top--;
    }

    T peek() const {
        if (isEmpty()) {
            throw underflow_error("Stack is empty");
        }
        return arr[top];
    }

    void display() const {
        if (isEmpty()) {
            cout << "Stack is empty" << endl;
            return;
        }
        cout << "Stack elements: ";
        for (int i = top; i >= 0; --i) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};


template <typename T>
class CircularQueue {
private:
    int front, rear, size, capacity;
    T* arr;

public:
    CircularQueue(int cap) : capacity(cap), front(-1), rear(-1), size(0) {
        arr = new T[capacity];
    }

    ~CircularQueue() {
        delete[] arr;
    }

    bool isEmpty() const {
        return size == 0;
    }

    bool isFull() const {
        return size == capacity;
    }

    void enqueue(const T& value) {
        if (isFull()) {
            throw overflow_error("Queue is full");
        }
        rear = (rear + 1) % capacity;
        arr[rear] = value;
        if (front == -1) front = 0;
        size++;
    }

    void dequeue() {
        if (isEmpty()) {
            throw underflow_error("Queue is empty");
        }
        front = (front + 1) % capacity;
        size--;
        if (size == 0) {
            front = -1;
            rear = -1;
        }
    }

    T peek() const {
        if (isEmpty()) {
            throw underflow_error("Queue is empty");
        }
        return arr[front];
    }

    void display() const {
        if (isEmpty()) {
            cout << "Queue is empty" << endl;
            return;
        }
        int temp = front;
        cout << "Circular Queue: ";
        for (int i = 0; i < size; i++) {
            cout << arr[temp] << " ";
            temp = (temp + 1) % capacity;
        }
        cout << endl;
    }
};



