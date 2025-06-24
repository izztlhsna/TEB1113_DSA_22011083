/*
**********************
ID: 22011083
Name: Izzatul Husna binti Abdul Manab
Contact: 0167417231
Email: izzatul_22011083@utp.edu.my
Lab: 3
*/

#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

Node* head = NULL;

void add(int val) {
    Node* n = new Node{val, NULL};
    if (head == NULL)
        head = n;
    else {
        Node* temp = head;
        while (temp->next) temp = temp->next;
        temp->next = n;
    }
}

void show() {
    Node* temp = head;
    while (temp) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL\n";
}

void del(int val) {
    if (!head) return;
    if (head->data == val) {
        Node* temp = head;
        head = head->next;
        delete temp;
        return;
    }
    Node* temp = head;
    while (temp->next && temp->next->data != val)
        temp = temp->next;
    if (temp->next) {
        Node* d = temp->next;
        temp->next = d->next;
        delete d;
    }
}

int main() {
    add(1); add(2); add(3);
    show(); // 1 -> 2 -> 3 -> NULL
    del(2);
    show(); // 1 -> 3 -> NULL
}