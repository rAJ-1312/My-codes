#include <iostream>

using namespace std;

// Node structure
struct Node {
    int data;
    Node* prev;
    Node* next;
};

// Global variables
Node* head = nullptr;

// Function to insert a node at the beginning of the circular doubly linked list
void beginsert() {
    int value;
    cout << "Enter the value to insert: ";
    cin >> value;

    // Create a new node
    Node* newNode = new Node();
    newNode->data = value;
    newNode->prev = nullptr;
    newNode->next = nullptr;

    if (head == nullptr) {
        // If the list is empty, set the new node as the head and make it point to itself
        head = newNode;
        newNode->prev = newNode;
        newNode->next = newNode;
    } else {
        // Adjust the links to insert the new node at the beginning
        newNode->next = head;
        newNode->prev = head->prev;
        head->prev->next = newNode;
        head->prev = newNode;
        head = newNode;
    }

    cout << "Node inserted at the beginning successfully!" << endl;
}

// Function to insert a node at the end of the circular doubly linked list
void lastinsert() {
    int value;
    cout << "Enter the value to insert: ";
    cin >> value;

    // Create a new node
    Node* newNode = new Node();
    newNode->data = value;
    newNode->prev = nullptr;
    newNode->next = nullptr;

    if (head == nullptr) {
        // If the list is empty, set the new node as the head and make it point to itself
        head = newNode;
        newNode->prev = newNode;
        newNode->next = newNode;
    } else {
        // Adjust the links to insert the new node at the end
        newNode->prev = head->prev;
        newNode->next = head;
        head->prev->next = newNode;
        head->prev = newNode;
    }

    cout << "Node inserted at the end successfully!" << endl;
}

// Function to insert a node at a random position in the circular doubly linked list
void randominsert() {
    int value, pos;
    cout << "Enter the value to insert: ";
    cin >> value;
    cout << "Enter the position to insert: ";
    cin >> pos;

    // Create a new node
    Node* newNode = new Node();
    newNode->data = value;
    newNode->prev = nullptr;
    newNode->next = nullptr;

    if (pos == 1 || head == nullptr) {
        // If position is 1 or the list is empty, set the new node as the head and adjust the links
        if (head == nullptr) {
            newNode->prev = newNode;
            newNode->next = newNode;
        } else {
            newNode->prev = head->prev;
            newNode->next = head;
            head->prev->next = newNode;
            head->prev = newNode;
        }
        head = newNode;
    } else {
        // Traverse to the position and insert the new node
        Node* temp = head;
        for (int i = 1; i < pos - 1; i++) {
            if (temp->next == head) {
                cout << "Position out of range!" << endl;
                return;
            }
            temp = temp->next;
        }
        newNode->prev = temp;
        newNode->next = temp->next;
        temp->next->prev = newNode;
        temp->next = newNode;
    }

    cout << "Node inserted at position " << pos << " successfully!" << endl;
}

// Function to delete the first node of the circular doubly linked list
void begin_delete() {
    if (head == nullptr) {
        cout << "List is empty. Nothing to delete!" << endl;
        return;
    }

    if (head->next == head) {
        // If there's only one node in the list, delete it and set head to nullptr
        delete head;
        head = nullptr;
    } else {
        // Adjust the links to delete the first node
        Node* del = head;
        head->next->prev = head->prev;
        head->prev->next = head->next;
        head = head->next;
        delete del;
    }

    cout << "First node deleted successfully!" << endl;
}

// Function to delete the last node of the circular doubly linked list
void last_delete() {
    if (head == nullptr) {
        cout << "List is empty. Nothing to delete!" << endl;
        return;
    }

    if (head->next == head) {
        // If there's only one node in the list, delete it and set head to nullptr
        delete head;
        head = nullptr;
    } else {
        // Adjust the links to delete the last node
        Node* del = head->prev;
        head->prev = del->prev;
        del->prev->next = head;
        delete del;
    }

    cout << "Last node deleted successfully!" << endl;
}

// Function to delete a node at a random position in the circular doubly linked list
void random_delete() {
    if (head == nullptr) {
        cout << "List is empty. Nothing to delete!" << endl;
        return;
    }

    int pos;
    cout << "Enter the position to delete: ";
    cin >> pos;

    if (pos == 1) {
        begin_delete();
        return;
    }

    Node* temp = head;
    for (int i = 1; i < pos - 1; i++) {
        if (temp->next == head) {
            cout << "Position out of range!" << endl;
            return;
        }
        temp = temp->next;
    }

    Node* del = temp->next;
    temp->next = del->next;
    del->next->prev = temp;
    delete del;

    cout << "Node at position " << pos << " deleted successfully!" << endl;
}

// Function to display the circular doubly linked list
void display() {
    if (head == nullptr) {
        cout << "List is empty!" << endl;
        return;
    }

    Node* temp = head;
    cout << "Head <-> ";
    do {
        cout << temp->data << " <-> ";
        temp = temp->next;
    } while (temp != head);
    cout << "Head" << endl;
}

// Function to search for a value in the circular doubly linked list
void search() {
    if (head == nullptr) {
        cout << "List is empty!" << endl;
        return;
    }

    int value;
    cout << "Enter the value to search: ";
    cin >> value;

    Node* temp = head;
    int pos = 1;
    do {
        if (temp->data == value) {
            cout << "Value found at position " << pos << endl;
            return;
        }
        temp = temp->next;
        pos++;
    } while (temp != head);

    cout << "Value not found in the list!" << endl;
}

// Main function
int main() {
    int choice;
    while (true)```cpp
        cout << "6. Delete node at a random position" << endl;
        cout << "7. Display the circular doubly linked list" << endl;
        cout << "8. Search for a value" << endl;
        cout << "9. Exit" << endl;
        cout << "----------------------------------------" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                beginsert();
                break;
            case 2:
                lastinsert();
                break;
            case 3:
                randominsert();
                break;
            case 4:
                begin_delete();
                break;
            case 5:
                last_delete();
                break;
            case 6:
                random_delete();
                break;
            case 7:
                display();
                break;
            case 8:
                search();
                break;
            case 9:
                cout << "Exiting program..." << endl;
                return 0;
            default:
                cout << "Invalid choice! Please try again." << endl;
        }
    }

    return 0;
}
