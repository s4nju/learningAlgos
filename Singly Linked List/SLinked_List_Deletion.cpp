//Implementation of deletion of Linked List

#include<bits/stdc++.h>
using namespace std;

struct node{
	int data;
	node* next;
};

struct node* newnode(int val){
	struct node* temp = new node;
	temp->data = val;
	temp->next = NULL;
}

void print(struct node* root){
	while(root != NULL){
		cout<<root->data<<" ";
		root = root->next;
	}
	cout<<endl;
}

void deletion(node* root){
	node* prev = root;
	while(root->next != NULL){
		root = root->next;
		cout<<"Deleting: "<<prev->data<<endl;
		delete(prev);
		prev = root;
	}
	cout<<"Deleting: "<<prev->data<<endl;
	delete(prev);
}

int main(){
	node *head = newnode(1);
	head->next = newnode(2);
	head->next->next = newnode(3);
	head->next->next->next = newnode(4);
	head->next->next->next->next = newnode(5);
	
	print(head);
	
	deletion(head);
	return 0;
}
