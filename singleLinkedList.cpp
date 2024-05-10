#include <iostream>

using namespace std;

// Node structure
struct Node {
    int data;
    Node* next;
};

// Global variables
Node* head = nullptr;

// Function to insert a node at the beginning of the linked list
void beginsert() {
    int value;
    cout << "Enter the value to insert: ";
    cin >> value;

    // Create a new node
    Node* newNode = new Node();
    newNode->data = value;
    newNode->next = nullptr;

    // If the list is empty, set the new node as the head
    if (head == nullptr) {
        head = newNode;
    } else {
        // Set the new node as the head and adjust the links
        newNode->next = head;
        head = newNode;
    }

    cout << "Node inserted at the beginning successfully!" << endl;
}

// Function to insert a node at the end of the linked list
void lastinsert() {
    int value;
    cout << "Enter the value to insert: ";
    cin >> value;

    // Create a new node
    Node* newNode = new Node();
    newNode->data = value;
    newNode->next = nullptr;

    // If the list is empty, set the new node as the head
    if (head == nullptr) {
        head = newNode;
    } else {
        // Traverse to the last node and insert the new node at the end
        Node* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = newNode;
    }

    cout << "Node inserted at the end successfully!" << endl;
}

// Function to insert a node at a random position in the linked list
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

    // If the list is empty or position is 1, set the new node as the head
    if (head == nullptr || pos == 1) {
        newNode->next = head;
        head = newNode;
        cout << "Node inserted at position " << pos << " successfully!" << endl;
        return;
    }

    // Traverse to the position and insert the new node
    Node* temp = head;
    for (int i = 1; i < pos - 1; i++) {
        if (temp->next == nullptr) {
            cout << "Position out of range!" << endl;
            return;
        }
        temp = temp->next;
    }

    newNode->next = temp->next;
    temp->next = newNode;

    cout << "Node inserted at position " << pos << " successfully!" << endl;
}

// Function to delete the first node of the linked list
void begin_delete() {
    if (head == nullptr) {
        cout << "List is empty. Nothing to delete!" << endl;
        return;
    }

    Node* temp = head;
    head = head->next;
    delete temp;

    cout << "First node deleted successfully!" << endl;
}

// Function to delete the last node of the linked list
void last_delete() {
    if (head == nullptr) {
        cout << "List is empty. Nothing to delete!" << endl;
        return;
    }

    if (head->next == nullptr) {
        delete head;
        head = nullptr;
        cout << "Last node deleted successfully!" << endl;
        return;
    }

    Node* temp = head;
    Node* prev = nullptr;
    while (temp->next != nullptr) {
        prev = temp;
        temp = temp->next;
    }

    prev->next = nullptr;
    delete temp;

    cout << "Last node deleted successfully!" << endl;
}

// Function to delete a node at a random position in the linked list
void random_delete() {
    if (head == nullptr) {
        cout << "List is empty. Nothing to delete!" << endl;
        return;
    }

    int pos;
    cout << "Enter the position to delete: ";
    cin >> pos;

    if (pos == 1) {
        Node* temp = head;
        head = head->next;
        delete temp;
        cout << "Node at position " << pos << " deleted successfully!" << endl;
        return;
    }

    Node* temp = head;
    Node* prev = nullptr;
    for (int i = 1; i < pos; i++) {
        if (temp == nullptr) {
            cout << "Position out of range!" << endl;
            return;
        }
        prev = temp;
        temp = temp->next;
    }

    prev->next = temp->next;
    delete temp;

    cout << "Node at position " << pos << " deleted successfully!" << endl;
}

// Function to display the linked list
void display() {
    if (head == nullptr) {
        cout << "List is empty!" << endl;
        return;
    }

    Node* temp = head;
    while (temp != nullptr) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

// Function to search for a value in the linked list
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
    while (temp != nullptr) {
        if (temp->data == value) {
            cout << "Value found at position " << pos << endl;
            return;
        }
        temp = temp->next;
        pos++;
    }

    cout << "Value not found in the list!" << endl;
}

// Main function
int main() {
    int choice;
    while (true) {
        cout << "----------------------------------------" << endl;
        cout << "1. Insert node at the beginning" << endl;
        cout << "2. Insert node at the end" << endl;
        cout << "3. Insert node at a random position" << endl;
        cout << "4. Delete first node" << endl;
        cout << "5. Delete last node" << endl;
        cout << "6. Delete node at a random position" << endl;
        cout << "7. Display the linked list" << endl;
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
