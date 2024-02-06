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

Node *evenAfterOdd(Node *head)
{
    if(!head || !(head -> next)) {
        return head;
    }
	Node *lastEven = NULL;
    Node *lastOdd = NULL;
    Node *current = head;
    bool evenFound = (head->data % 2 == 0);
	while (true) {
        print(head);
        cout << "START: ";
        if (lastEven)
            cout << "lastEven: " << lastEven->data << " ";
        if (lastOdd)
            cout << "lastOdd: " << lastOdd->data << " ";
        cout << "current: " << current->data << " evenFound: " << evenFound << endl;

		if (current->data % 2 == 0) {
            lastEven = current;
            evenFound = true;
        }
        
        if (current->data % 2 == 1 && lastOdd == NULL && lastEven != NULL) {
            // cout << "found an odd. lastOdd: " << current->data << " lastEven: " << lastEven->data << endl;
            // means we haven't gotten a odd till yet
            // but have seen an even
            // this means list started from even
            lastOdd = current;
            lastEven -> next = current -> next;
            current -> next = head;
            head = current;
            current = lastEven;
            continue;
        }
        
        current = current->next;
        if (current == NULL) break;

        if (current->data % 2 == 0) {
            lastEven = current;
            cout << "Continue.." << endl;
            continue;
        }
        
        if (evenFound && lastOdd != NULL) {
            // current is odd now
            // we need to move it before even
            cout << "[Replacing] : " << current->data << endl;
            Node *nextOdd = lastOdd -> next;
            lastOdd -> next = current;
            lastEven -> next = current -> next;
            current -> next = nextOdd;
            lastOdd = current;
            current = lastEven;
        }

        cout << "  END: ";
        if (lastEven)
            cout << "lastEven: " << lastEven->data << " ";
        if (lastOdd)
            cout << "lastOdd: " << lastOdd->data << " ";
        cout << "current: " << current->data << " evenFound: " << evenFound << endl;
	}

    return head;
}

int main()
{
	int t = 1;
	// cin >> t;
	while (t--)
	{
		Node *head = takeinput();
		head = evenAfterOdd(head);
		print(head);
	}
	return 0;
}