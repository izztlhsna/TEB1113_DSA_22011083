/*
**********************
ID: 22011083
Name: Izzatul Husna binti Abdul Manab
Contact: 0167417231
Email: izzatul_22011083@utp.edu.my
Lab: 5
*/

#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

class Stack {
private:
    Node* top;

public:
    Stack() {
        top = NULL;
    }

    void push(int val) { //insert element from top
        Node* n = new Node{val, top};
        top = n;
        cout << val << " pushed to stack.\n";
    }

    void pop() { //remove element from top
        if (!top) {
          
            cout << "Stack Underflow\n";
            return;
        }
        cout << top->data << " popped from stack.\n";
        Node* temp = top;
        top = top->next;
        delete temp;
    }

    void peep() { //show the top element only
        if (!top) {
            cout << "Stack is empty.\n";
            return;
        }
        cout << "Top element: " << top->data << endl;
    }

    void show() { //just showing whts going on 
        Node* temp = top;
        cout << "Stack: ";
        while (temp) {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL\n";
    }
};

int main() {
    Stack stack;
    stack.push(1);
    stack.push(2);
    stack.push(3);
    stack.show();   // Stack: 3 -> 2 -> 1 -> NULL

    stack.peep();   // it has 3 elements

    stack.pop();    // remove the tail (the last one that come in)
    stack.show();   // Stack: 2 -> 1 -> NULL

    return 0;
}
