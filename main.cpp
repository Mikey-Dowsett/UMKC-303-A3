#include <iostream>
#include "LQueue.h"

using namespace std;

int main() {
    //Question 1 Part A
    auto intQueue = LQueue<int>();
    intQueue.push(1);
    intQueue.push(2);
    intQueue.push(3);
    intQueue.push(4);
    intQueue.push(5);
    intQueue.push(6);
    intQueue.push(7);
    intQueue.push(8);
    intQueue.push(9);
    intQueue.push(3);
    intQueue.push(10);

    //Question 2
    cout << "Q2." << endl;
    cout << "Last Index of 3: " << intQueue.linear_search(3) << endl;
    cout << "Last Index of 7: " << intQueue.linear_search(7) << endl;
    cout << "Last Index of 11: " << intQueue.linear_search(11) << endl;

    //Question 1 Part B
    cout << "\nQ1." << endl;
    int size = intQueue.size();
    for (int i = 0; i < size/2; i++) {
        cout << intQueue.pop() << ", ";
    }

    //Question 1 Part C
    intQueue.move_to_rear();

    //Question 1 Part B
    size = intQueue.size();
    for (int i = 0; i < size + 1; i++) {
        cout << intQueue.pop() << ", ";
    }
    cout << endl;

    //Question 3
    cout << "\nQ3." << endl;
    intQueue.push(6);
    intQueue.push(8);
    intQueue.push(3);
    intQueue.push(1);
    intQueue.push(9);
    intQueue.push(5);
    intQueue.push(2);
    intQueue.push(4);
    intQueue.push(7);
    intQueue.push(10);
    cout << "Unsorted: ";
    intQueue.print();
    intQueue.insertion_sort();
    cout << "Sorted: ";
    intQueue.print();

    return 0;
}