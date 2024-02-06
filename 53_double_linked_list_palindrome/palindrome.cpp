#include <iostream>
using namespace std;
class Node
{
public:
	int data;
	Node *next;
	Node* prev;
	Node(int data)
	{
		
		this->data = data;
		this->next = NULL;
		this->prev = NULL;
	}
};

Node *takeinput()
{
	int data;
	cin >> data;
	Node *head = NULL, *tail = NULL;
	while (data != -1)
	{
		Node *newNode = new Node(data);
		if (head == NULL)
		{
			head = newNode;
			tail = newNode;
		}
		else
		{
			tail->next = newNode;
			newNode->prev = tail;
			tail = newNode;
		}
		cin >> data;
	}
	return head;
}

bool palindromeDLL(Node* head){
	if (head == NULL || head -> next == NULL) return true;

    Node* next = head;
	Node* tail = head;
	while (tail->next != NULL)
		tail = tail -> next;

	while (true) {
		if (next -> data != tail -> data) return false;
		if (next == tail || head == tail) break;

		next = next -> next;
		tail = tail -> prev;
	}
	return true;
}


int main()
{
	int t;
    t = 1;
	// cin >> t;
	while (t--)
	{
		Node *head = takeinput();
		bool ans = palindromeDLL(head);
		
		if (ans) cout << "true";
		else cout << "false";

		cout << endl;
	}
	return 0;
}