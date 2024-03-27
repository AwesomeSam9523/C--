class Node {
public :
    int data;
    Node *next;

    Node(int data) {
        this->data = data;
        next = nullptr;
    }
};

class Stack {
    Node *head;
    int size;

public:
    Stack() {
        head = nullptr;
        size = 0;
    }

    /*----------------- Public Functions of Stack -----------------*/

    int getSize() {
        return size;
    }

    bool isEmpty() {
        return size == 0;
    }

    void push(int element) {
        Node *newNode = new Node(element);
        newNode -> next = head;
        head = newNode;
        size++;
    }

    int pop() {
        if (isEmpty()) {
            return -1;
        }
        int data = head->data;
        head = head->next;
        size--;
        return data;
    }

    int top() {
        if (isEmpty()) {
            return -1;
        }
        return head->data;
    }
};