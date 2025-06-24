/*
**********************
ID: 22011083
Name: Izzatul Husna binti Abdul Manab
Contact: 0167417231
Email: izzatul_22011083@utp.edu.my
Lab: 4
*/

#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* prev;
    Node* next;
};

class CircularDoublyLinkedList {
private:
    Node* head;

public:
    CircularDoublyLinkedList() {
        head = nullptr;
    }

    void insertAtEnd(int value) {
        Node* newNode = new Node{value, nullptr, nullptr};
        if (!head) {
            newNode->next = newNode;
            newNode->prev = newNode;
            head = newNode;
        } else {
            Node* tail = head->prev;
            tail->next = newNode;
            newNode->prev = tail;
            newNode->next = head;
            head->prev = newNode;
        }
    }

    void deleteValue(int value) {
        if (!head) return;

        Node* current = head;
        do {
            if (current->data == value) {
                if (current->next == current) {
                    delete current;
                    head = nullptr;
                } else {
                    current->prev->next = current->next;
                    current->next->prev = current->prev;
                    if (current == head)
                        head = current->next;
                    delete current;
                }
                return;
            }
            current = current->next;
        } while (current != head);
    }

    void displayForward() {
        if (!head) {
            cout << "List is empty." << endl;
            return;
        }

        Node* temp = head;
        do {
            cout << temp->data << " ";
            temp = temp->next;
        } while (temp != head);
        cout << endl;
    }

    void displayBackward() {
        if (!head) {
            cout << "List is empty." << endl;
            return;
        }

        Node* tail = head->prev;
        Node* temp = tail;
        do {
            cout << temp->data << " ";
            temp = temp->prev;
        } while (temp != tail);
        cout << endl;
    }

    ~CircularDoublyLinkedList() {
        while (head) {
            deleteValue(head->data);
        }
    }
};

int main() {
    CircularDoublyLinkedList list;
    list.insertAtEnd(10);
    list.insertAtEnd(20);
    list.insertAtEnd(30);

    cout << "Forward: ";
    list.displayForward();

    cout << "Backward: ";
    list.displayBackward();

    list.deleteValue(20);
    cout << "After deleting 20:" << endl;
    list.displayForward();

    return 0;
}