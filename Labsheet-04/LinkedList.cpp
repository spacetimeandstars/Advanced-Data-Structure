#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int val) {
        data = val;
        next = NULL;
    }
};

class SinglyLinkedList {
private:
    Node* head;

public:
    SinglyLinkedList() {
        head = NULL;
    }

    // Insert Last (used in create)
    void insertLast(int val) {
        Node* newNode = new Node(val);

        if (!head) {
            head = newNode;
            return;
        }

        Node* temp = head;
        while (temp->next)
            temp = temp->next;

        temp->next = newNode;
    }

    // Create
    void create(int n) {
        int val;
        for (int i = 0; i < n; i++) {
            cout << "Enter value: ";
            cin >> val;
            insertLast(val);
        }
    }

    // Insert Start
    void insertStart(int val) {
        Node* newNode = new Node(val);
        newNode->next = head;
        head = newNode;
    }

    // Insert Middle
    void insertMiddle(int val, int pos) {
        if (pos <= 1) {
            insertStart(val);
            return;
        }

        Node* temp = head;
        for (int i = 1; i < pos - 1 && temp; i++)
            temp = temp->next;

        if (!temp) {
            cout << "Invalid position\n";
            return;
        }

        Node* newNode = new Node(val);
        newNode->next = temp->next;
        temp->next = newNode;
    }

    // Delete Start
    void deleteStart() {
        if (!head) {
            cout << "List empty\n";
            return;
        }

        Node* temp = head;
        head = head->next;
        delete temp;
    }

    // Delete Middle
    void deleteMiddle(int pos) {
        if (!head) return;

        if (pos == 1) {
            deleteStart();
            return;
        }

        Node* temp = head;
        for (int i = 1; i < pos - 1 && temp; i++)
            temp = temp->next;

        if (!temp || !temp->next) {
            cout << "Invalid position\n";
            return;
        }

        Node* del = temp->next;
        temp->next = del->next;
        delete del;
    }

    // Delete Last
    void deleteLast() {
        if (!head) return;

        if (!head->next) {
            delete head;
            head = NULL;
            return;
        }

        Node* temp = head;
        while (temp->next->next)
            temp = temp->next;

        delete temp->next;
        temp->next = NULL;
    }

    // Display
    void display() {
        if (!head) {
            cout << "List is empty\n";
            return;
        }

        Node* temp = head;
        while (temp) {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL\n";
    }

    // Split (safe version)
    void split() {
        if (!head || !head->next) {
            cout << "Cannot split (too small)\n";
            return;
        }

        Node* slow = head;
        Node* fast = head->next;

        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }

        Node* second = slow->next;
        slow->next = NULL;

        cout << "First List: ";
        Node* temp = head;
        while (temp) {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL\n";

        cout << "Second List: ";
        temp = second;
        while (temp) {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL\n";
    }

    // Merge (FIXED using reference)
    void merge(SinglyLinkedList &list2) {
        if (!head) {
            head = list2.head;
            return;
        }

        Node* temp = head;
        while (temp->next)
            temp = temp->next;

        temp->next = list2.head;
    }
};
int main() {
    int choice, type;
    SinglyLinkedList list, list2;

    // MAIN MENU
    cout << "=====================================\n";
    cout << "        LINKED LIST PROJECT\n";
    cout << "=====================================\n";

    cout << "Choose your operation:\n";
    cout << "1. Singly Linked List\n";
    cout << "2. Doubly Linked List\n";
    cout << "3. Circular Linked List\n";
    cout << "Enter your choice: ";
    cin >> type;

    if (type != 1) {
        cout << "Only Singly Linked List implemented.\n";
        return 0;
    }

    // OPERATIONS MENU
    do {
        cout << "\n-------------------------------------\n";
        cout << "Select operation to perform:\n";
        cout << "1. Create\n";
        cout << "2. Insert Start\n";
        cout << "3. Insert Middle\n";
        cout << "4. Insert Last\n";
        cout << "5. Delete Start\n";
        cout << "6. Delete Middle\n";
        cout << "7. Delete Last\n";
        cout << "8. Split\n";
        cout << "9. Merge\n";
        cout << "10. Display\n";
        cout << "11. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        int val, pos, n;

        switch (choice) {
            case 1:
                cout << "Enter number of elements: ";
                cin >> n;
                list.create(n);
                break;

            case 2:
                cout << "Enter value to insert at start: ";
                cin >> val;
                list.insertStart(val);
                break;

            case 3:
                cout << "Enter value and position: ";
                cin >> val >> pos;
                list.insertMiddle(val, pos);
                break;

            case 4:
                cout << "Enter value to insert at end: ";
                cin >> val;
                list.insertLast(val);
                break;

            case 5:
                cout << "Deleting first node...\n";
                list.deleteStart();
                break;

            case 6:
                cout << "Enter position to delete: ";
                cin >> pos;
                list.deleteMiddle(pos);
                break;

            case 7:
                cout << "Deleting last node...\n";
                list.deleteLast();
                break;

            case 8:
                cout << "Splitting list...\n";
                list.split();
                break;

            case 9:
                cout << "Enter number of elements for second list: ";
                cin >> n;
                list2.create(n);
                cout << "Merging lists...\n";
                list.merge(list2);
                break;

            case 10:
                cout << "Current List: ";
                list.display();
                break;

            case 11:
                cout << "Exiting program...\n";
                break;

            default:
                cout << "Invalid choice! Try again.\n";
        }

    } while (choice != 11);

    return 0;
}