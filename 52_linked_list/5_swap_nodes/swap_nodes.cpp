#include <iostream>

class Node
{
public:
    int data;
    Node *next;
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};

using namespace std;

Node *takeinput()
{
    int data;
    cin >> data;
    Node *head = NULL, *tail = NULL;
    while (data != -1)
    {
        Node *newnode = new Node(data);
        if (head == NULL)
        {
            head = newnode;
            tail = newnode;
        }
        else
        {
            tail->next = newnode;
            tail = newnode;
        }
        cin >> data;
    }
    return head;
}

void print(Node *head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

Node *swapNodes(Node *head, int i, int j)
{
    Node *temp = head;
    Node *ith = nullptr;
    Node *jth = nullptr;
    int counter = 0;
    if (i > j) {
        int t = i;
        j = i;
        i = t;
    }
    while (temp != NULL) {
        if (counter == i-1)
            ith = temp;
        if (counter == j-1)
            jth = temp;
        counter++;
        temp = temp -> next;
    }
    if (!ith || !jth)
        return head;

    Node *ithnext = ith->next;
    Node *jthnext = jth->next;

    ith->next = jth->next;
    temp = jthnext->next;
    ith->next->next = ithnext->next;
    ithnext->next = temp;
    jth->next = ithnext;

    return head;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int i, j;
        Node *head = takeinput();
        cin >> i;
        cin >> j;
        head = swapNodes(head, i, j);
        print(head);
    }
    return 0;
}