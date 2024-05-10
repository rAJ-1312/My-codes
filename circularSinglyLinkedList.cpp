#include <iostream>

using namespace std;

// Node structure
struct Node {
    int data;
    Node* next;
};

// Global variables
Node* head = nullptr;

// Function to insert a node at the beginning of the circular linked list
void beginsert() {
    int value;
    cout << "Enter the value to insert: ";
    cin >> value;

    // Create a new node
    Node* newNode = new Node();
    newNode->data = value;
    newNode->next = nullptr;

    if (head == nullptr) {
        // If the list is empty, set the new node as the head and make it point to itself
        head = newNode;
        newNode->next = head;
    } else {
        // Find the last node and adjust the links
        Node* temp = head;
        while (temp->next != head) {
            temp = temp->next;
        }
        newNode->next = head;
        temp->next = newNode;
        head = newNode;
    }

    cout << "Node inserted at the beginning successfully!" << endl;
}

// Function to insert a node at the end of the circular linked list
void lastinsert() {
    int value;
    cout << "Enter the value to insert: ";
    cin >> value;

    // Create a new node
    Node* newNode = new Node();
    newNode->data = value;
    newNode->next = nullptr;

    if (head == nullptr) {
        // If the list is empty, set the new node as the head and make it point to itself
        head = newNode;
        newNode->next = head;
    } else {
        // Find the last node and adjust the links
        Node* temp = head;
        while (temp->next != head) {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->next = head;
    }

    cout << "Node inserted at the end successfully!" << endl;
}

// Function to insert a node at a random position in the circular linked list
void randominsert() {
    int value, pos;
    cout << "Enter the value to insert: ";
    cin >> value;
    cout << "Enter the position to insert: ";
    cin >> pos;

    // Create a new node
    Node* newNode = new Node();
    newNode->data = value;
    newNode->next = nullptr;

    if (pos == 1 || head == nullptr) {
        // If position is 1 or the list is empty, set the new node as the head and adjust the links
        newNode->next = head;
        if (head != nullptr) {
            // Find the last node and update its next pointer
            Node* temp = head;
            while (temp->next != head) {
                temp = temp->next;
            }
            temp->next = newNode;
        } else {
            // If the list is empty, make the new node point to itself
            newNode->next = newNode;
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
        newNode->next = temp->next;
        temp->next = newNode;
    }

    cout << "Node inserted at position " << pos << " successfully!" << endl;
}

// Function to delete the first node of the circular linked list
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
        // Find the last node and adjust the links
        Node* temp = head;
        while (temp->next != head) {
            temp = temp->next;
        }
        temp->next = head->next;
        Node* del = head;
        head = head->next;
        delete del;
    }

    cout << "First node deleted successfully!" << endl;
}

// Function to delete the last node of the circular linked list
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
        // Find the second last node and adjust the links
        Node* temp = head;
        while (temp->next->next != head) {
            temp = temp->next;
        }
        Node* del = temp->next;
        temp->next = head;
        delete del;
    }

    cout << "Last node deleted successfully!" << endl;
}

// Function to delete a node at a random position in the circular linked list
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
    temp->next = temp->next->next;
    delete del;

    cout << "Node at position " << pos << " deleted successfully!" << endl;
}

// Function to display the circular linked list
void display() {
    if (head == nullptr) {
        cout << "List is empty!" << endl;
        return;
    }

    Node* temp = head;
    do {
        cout << temp->data << " -> ";
        temp = temp->next;
    } while (temp != head);
    cout << "Head" << endl;
}

// Function to search for a value in the circular linked list
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
    while (true) {
        cout << "----------------------------------------"
        cout << "6. Delete node at a random position" << endl;
        cout << "7. Display the circular linked list" << endl;
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
