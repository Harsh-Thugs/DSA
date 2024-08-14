#include <iostream>
using namespace std;

class Stack {
public:
    static const int MAX = 100;
    int stack[MAX];
    int top;

public:
    Stack() : top(-1) {}

    void push(int val) {
        if (top >= MAX - 1) {
            cout << "Stack Overflow" << endl;
        } else {
            stack[++top] = val;
            cout << "Pushed " << val << " to stack" << endl;
        }
    }

    void pop() {
        if (top < 0) {
            cout << "Stack Underflow" << endl;
        } else {
            cout << "The popped element is " << stack[top--] << endl;
        }
    }

    void display() const {
        if (top >= 0) {
            cout << "Stack elements are: ";
            for (int i = top; i >= 0; i--) {
                cout << stack[i] << " ";
            }
            cout << endl;
        } else {
            cout << "Stack is empty" << endl;
        }
    }
};

int main() {
    Stack s;
    int choice, value;

    do {
        cout << "1) Push in stack" << endl;
        cout << "2) Pop from stack" << endl;
        cout << "3) Display stack" << endl;
        cout << "4) Exit" << endl;
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value to be pushed: ";
                cin >> value;
                s.push(value);
                break;
            case 2:
                s.pop();
                break;
            case 3:
                s.display();
                break;
            case 4:
                cout << "Exiting..." << endl;
                break;
            default:
                cout << "Invalid choice. Please enter a number between 1 and 4." << endl;
                break;
        }
    } while (choice != 4);

}
