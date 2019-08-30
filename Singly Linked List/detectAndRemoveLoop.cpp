//Implementation of detection and removal of Loop in a Linked List.
#include <bits/stdc++.h>
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

bool remove(node* sloop_node){
	node *temp = sloop_node;
	while(sloop_node->next != temp){
		sloop_node = sloop_node->next;
	}
	sloop_node->next = NULL;
	
	return true;
}

bool detect(node* head){
	node *fast, *slow;
	if(head != NULL){
		slow = head;
		fast = head->next;
	}
	
	while(slow && fast && fast->next){
		if(fast == slow) return remove(slow);
		else{
			slow = slow->next;
			fast = fast->next->next;
		}
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

	if(detect(head)) cout<<"Loop removed! "<<endl;
	
	else cout<<"Loop Not Removed! "<<endl;
	
	return 0;
}
