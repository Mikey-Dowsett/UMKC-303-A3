#pragma once
#include <vector>

template<class T>
class LQueue {
private:
    //Struct to represent the node and its data
    struct Node {
        T data;
        Node* next;

        Node(const int data, Node* next) : data(data), next(next) {}
    };

    Node* head;
    Node* tail;
    int queueSize;

public:
    LQueue() : head(nullptr), tail(nullptr), queueSize(0) {}
    ~LQueue(){
        while (!empty()) {
            pop();
        }
    }

    //Adds a new element to the front of the queue
    void push(T data){
        Node* newNode = new Node(data, nullptr);
        if (tail == nullptr) {
            head = tail = newNode;
            return;
        }
        tail->next = newNode;
        tail = newNode;
        queueSize++;
    }

    //Removes the element at the front of the queue and returns its data
    T pop() {
        if (head == nullptr) {
            return T();
        }
        Node* temp = head;
        T data = temp->data;
        head = head->next;
        if (head == nullptr) {
            tail = nullptr;
        }
        delete temp;
        queueSize--;
        return data;
    }

    //Returns the element at the front of the queue
    T front() {
        if (head == nullptr) {
            return T();
        }
        return head->data;
    }

    //Returns the size of the queue
    int size() const {
        return queueSize;
    }

    //Returns if the queue is empty or not
    bool empty() const {
        return queueSize == 0;
    }

    //Moves the front element to the end of the queue
    void move_to_rear() {
        T data = front();
        pop();
        push(data);
    }

    //Question 2, Starter method for the recursive call
    int linear_search(T data) {
        Node* curr = head;
        Node* target = new Node(data, nullptr);
        size_t lastPos = -1;
        linear_search(curr, target, 0, lastPos);
        return lastPos;
    }

    //Question 2, Searches through the queue
    int linear_search(Node* currNode, Node* target, size_t index, size_t& lastPos) {
        if (currNode == nullptr) {
            return -1;
        }
        if (currNode->data == target->data) {
            lastPos = index;
        }
        return linear_search(currNode->next, target, index + 1, lastPos);
    }

    //Question 3, Sorts the queue from low to high
    void insertion_sort() {
        if (head == nullptr || head->next == nullptr) {
            return;
        }

        Node* sorted = nullptr;
        Node* curr = head;

        while (curr != nullptr) {
            Node* next = curr->next;

            if (sorted == nullptr || sorted->data >= curr->data) {
                curr->next = sorted;
                sorted = curr;
            } else {
                Node* temp = sorted;
                while (temp->next != nullptr && temp->next->data < curr->data) {
                    temp = temp->next;
                }
                curr->next = temp->next;
                temp->next = curr;
            }
            curr = next;
        }
        head = sorted;
    }

    //Prints out the queue
    void print() {
        Node* curr = head;
        while (curr != nullptr) {
            std::cout << curr->data << ", ";
            curr = curr->next;
        }
        std::cout << std::endl;
    }
};
