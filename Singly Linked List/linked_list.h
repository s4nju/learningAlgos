#include<iostream>
struct node{
	int data;
	node *next;
};

struct node* newnode(int val){
	node *temp = new node;
	temp->data = val;
	temp->next = NULL;
	
	return temp;
}

void push(struct node *head, int val){
	node *temp = head;
	while(temp->next != NULL){
		temp = temp->next;
	}
	temp->next = newnode(val);
}

void print(struct node *head){
	struct node *temp = head;
	
	while(temp->next != NULL){
		std::cout<<temp->data<<std::endl;
		temp = temp->next;
	}
	
}
