//Implementation of Pairwise Swapping the Linked List.
#include <iostream>
using namespace std;

struct node {
	int data;
	node* next;
};

struct node* newnode(int val) {
	node* temp = new node;
	temp->data = val;
	temp->next = NULL;

	return temp;
}

void print(node *head) {
	while (head != NULL) {
		cout << head->data;
		head = head->next;
	}
}

void pairwiseSwap(node* head) {
	node *temp = head;
	while (temp && temp->next) {
		int tem = temp->data;
		temp->data = temp->next->data;
		temp->next->data = tem;
		temp = temp->next->next;
	}

	cout << endl;
}

int main() {
	node* head = newnode(1);
	head->next = newnode(2);
	head->next->next = newnode(3);
	head->next->next->next = newnode(4);
	head->next->next->next->next = newnode(5);
	head->next->next->next->next->next = newnode(6);

	pairwiseSwap(head);

	cout << "Swapped Linked List is: " << print(head);
}
