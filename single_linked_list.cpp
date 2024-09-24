#include <iostream>
using namespace std;

// Structure for a node in the linked list
struct Node {
    int data;
    Node* next;
};

// Define the linked list class
class LinkedList {
    // Pointer to the first node in the list
    Node* head;

public:
    // Constructor initializes head to NULL
    LinkedList() : head(NULL) {}

    // Function to Insert a new node at the beginning of the list
    void insertAtBeginning(int value) {
        Node* newNode = new Node();
        newNode->data = value;
        newNode->next = head;
        head = newNode; // Fixed indentation
    }

    // Function to Insert a new node at the end of the list
    void insertAtEnd(int value) {
        Node* newNode = new Node();
        newNode->data = value;
        newNode->next = NULL;

        // If the list is empty, update the head to the new node
        if (!head) {
            head = newNode;
            return;
        }

        // Traverse to the last node
        Node* temp = head;
        while (temp->next) {
            temp = temp->next;
        }

        // Update the last node's next to the new node
        temp->next = newNode; // Fixed indentation
    }

    // Function to Insert a new node at a specific position in the list
    void insertAtPosition(int value, int position) {
        if (position < 1) {
            cout << "Position should be >= 1." << endl;
            return;
        }
        if (position == 1) {
            insertAtBeginning(value);
            return;
        }
        
        Node* newNode = new Node();
        newNode->data = value;

        // Traverse to the node before the desired position
        Node* temp = head;
        for (int i = 1; i < position - 1 && temp; i++) {
            temp = temp->next;
        }

        // If the position is out of range, print an error message
        if (!temp) {
            cout << "Position out of range." << endl;
            delete newNode;
            return;
        }

        // Insert the new node at the desired position
        newNode->next = temp->next;
        temp->next = newNode; // Fixed indentation
    }

    // Function to Delete the first node of the list
    void deleteFromBeginning() {
        if (!head) {
            cout << "List is empty." << endl;
            return;
        }
        Node* temp = head;
        head = head->next;
        delete temp; // Fixed indentation
    }

    // Function to Delete the last node of the list
    void deleteFromEnd() {
        if (!head) {
            cout << "List is empty." << endl;
            return;
        }
        if (!head->next) {
            delete head;
            head = NULL;
            return;
        }

        // Traverse to the second-to-last node
        Node* temp = head;
        while (temp->next->next) {
            temp = temp->next;
        }

        // Delete the last node
        delete temp->next; // Fixed indentation
        temp->next = NULL; // Fixed indentation
    }

    // Function to Delete a node at a specific position in the list
    void deleteFromPosition(int position) {
        if (position < 1) {
            cout << "Position should be >= 1." << endl;
            return;
        }
        if (position == 1) {
            deleteFromBeginning();
            return;
        }

        Node* temp = head;
        for (int i = 1; i < position - 1 && temp; i++) {
            temp = temp->next;
        }

        if (!temp || !temp->next) {
            cout << "Position out of range." << endl; // Fixed message
            return;
        }

        // Save the node to be deleted
        Node* nodeToDelete = temp->next;
        // Update the next pointer
        temp->next = temp->next->next;
        // Delete the node
        delete nodeToDelete; // Fixed indentation
    }

    // Function to print nodes of the linked list
    void display() {
        if (!head) {
            cout << "List is empty." << endl;
            return;
        }

        Node* temp = head;
        while (temp) {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL" << endl; // Fixed message and indentation
    }
};

int main() {
    // Initialize a new linked list
    LinkedList list1;
    int ch, element, pos;

    while (true) {
        cout << "\n** MENU **";
        cout << "\n1: insertAtBeginning\n2: insertAtEnd\n3: insertAtPosition\n4: deleteFromBeginning\n5: deleteFromEnd\n6: deleteFromPosition\n7: DISPLAY\n8: EXIT\n";
        cout << "\nEnter Your Choice: ";
        cin >> ch;

        switch (ch) {
            case 1:
                cout << "Enter the element: ";
                cin >> element;
                list1.insertAtBeginning(element);
                break;
            case 2:
                cout << "Enter the element: ";
                cin >> element;
                list1.insertAtEnd(element);
                break;
            case 3:
                cout << "Enter the element: ";
                cin >> element;
                cout << "Enter the position: ";
                cin >> pos;
                list1.insertAtPosition(element, pos);
                break;
            case 4:
                list1.deleteFromBeginning();
                break;
            case 5:
                list1.deleteFromEnd();
                break;
            case 6:
                cout << "Enter the position: ";
                cin >> pos;
                list1.deleteFromPosition(pos);
                break;
            case 7:
                list1.display();
                break;
            case 8:
                return 0;
            default:
                cout << "Invalid choice. Please try again." << endl; // Added error handling
                break;
        }
    }

    return 0;
}
