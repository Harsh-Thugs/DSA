#include <iostream>
using namespace std;
int queue[5], n = 5, front = -1, rear = -1;
void EnQueue() {
    int value;
    if (rear == n-1) {
        cout << "\nQueue Overflow. Cannot enter any more elements in the Queue.";
    }
    else {
        if (front == -1) {
            front = 0;
        }
        cout << "Enter new element to Enqueue in Queue: ";
        cin >> value;
        rear ++;
        queue[rear] = value;
    }
}
void DeQueue() {
    if (front > rear) {
        cout << "\nQueue Underflow. No elements present in the Queue.";
    }
    else {
        cout << "\nElement "<< queue[front] <<" Dequeued from Queue";
        front ++;
    }
}
void Display() {
    if (front == -1 || front > rear) {
        cout << "\nQueue is Empty. Please insert elements into the Queue.";
    }
    else {
        cout << "\nQueue Elements: ";
        for (int i = front; i <= rear; i++) 
            cout<<queue[i]<< " ";
    }
}
int main() {
    int choice;
    cout << "Use the respective numeric choices to use Queue Functions =>";
    cout << "\n1: ENQUEUE new element into Queue.";
    cout << "\n2: DEQUEUE an element from existing Queue.";
    cout << "\n3: DISPLAY Queue elements.";
    cout << "\n4: EXIT the program.";
    do {
        cout << "\n\nEnter Choice: ";
        cin >> choice;
        switch (choice) {
            case 1:
            {
                EnQueue();
                break;
            }
            case 2:
            {
                DeQueue();
                break;
            }
            case 3:
            {
                Display();
                break;
            }
            case 4:
            {
                cout << "\nPROGRAM EXIT.";
                break;
            }
            default:
            {
                cout << "\nInvalid choice. Please choose a valid numeric choice from the given list =>\n1: ENQUEUE new element into Queue.\n2: DEQUEUE an element from existing Queue.\n3: DISPLAY Queue elements.\n4: EXIT the program.";
            }
        }
    }
    while (choice != 4);
    return 0;
}