//Implementation of floyd-cycle finding algorithm.
#include<iostream>
using namespace std;

struct node{
	int data;
	node* next;
};

struct node* newnode(int val){
	node* temp = new node;
	temp->data = val;
	temp->next = NULL;
	
	return temp;
}

bool detectLoop(struct node* head){
	node* fast;
	node* slow;
	
	if(head == NULL) return false; //if there is no node.
	
	if(head->next == NULL) return false; //if there is single node but no loop.
	
	else if(head->next != NULL){ 
		fast = head->next;
		slow = head;	
	}
	
	while(slow != NULL and fast->next != NULL){
		if(slow == fast) return true;
		else{
			slow = slow->next;
			fast = fast->next->next;
		}
		//cout<<"f"<<fast->data<<endl;
		//cout<<slow->data<<endl;
	}
	
	return false;
}

int main(){
	node* head = newnode(1);
	head->next = newnode(2);
	head->next->next = newnode(3);
	head->next->next->next = newnode(4);
	head->next->next->next->next = newnode(5);
	head->next->next->next->next->next = newnode(6);
	head->next->next->next->next->next = head->next; //Last node is pointing to the second last node.
	
	if(detectLoop(head)) cout<<"Yes!"<<endl;
	
	else cout<<"No!"<<endl;
	
	return 0;
}
