//Detect the loop in linked list if exist
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

int evaluateLength(node* head){
	node *ptr = head;
	int count = 1;
	while(head->next != ptr){
		++count;
		head = head->next;
	}
	
	return count;
}

int detectLoop(node* head){
	node *fast, *slow;
	if(head != NULL){
		slow = head;
		fast = head->next;
	}
	
	while(fast->next != NULL and slow != NULL){
		if(fast == slow) return evaluateLength(slow);
		else{
			slow = slow->next;
			fast = fast->next->next;
		}
	}
	
	return 0;
}

int main(){
	node* head = newnode(1);
	head->next = newnode(2);
	head->next->next = newnode(3);
	head->next->next->next = newnode(4);
	head->next->next->next->next = newnode(5);
	head->next->next->next->next->next = newnode(6);
	head->next->next->next->next->next = head->next; //Last node is pointing to the second last node.
	
	cout<<"Length of the Loop is: "<<detectLoop(head)<<endl;
	
}
