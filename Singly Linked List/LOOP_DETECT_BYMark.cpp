#include<iostream>
using namespace std;

struct node{
	int data;
	node* next;
	bool mark;
};

struct node* newnode(int val){
	node* temp = new node;
	temp->data = val;
	temp->next = NULL;
	temp->mark = false;
	
	return temp;
}

bool detectLoop(node* head){
	while(head != NULL){
		if(head->mark == true) return true;
		else{
			head->mark = true;
			head = head->next;
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
	head->next->next->next->next->next = head->next; // Here it pointing to the node after the head node. CYCLE!...
	
	if(detectLoop(head)) cout<<"Yes!"<<endl;
	
	else cout<<"No!"<<endl;
	
	
}
