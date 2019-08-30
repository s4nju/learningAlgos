//Detect a loop in a Linked List using Hashing.
#include<bits/stdc++.h>
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

bool detectLoop(node *head){ //returns true if loop exist otherwise false.
	vector<node*> v;
	if(head != NULL){	
		v.push_back(head);
		head = head->next;
	}
	while(head != NULL){
		if(find(v.begin(), v.end(), head) != v.end()){
			return true;
		}
		else{
			v.push_back(head);
			head = head->next;
		}
	}
	
	return false;
}

int main(){
	node *head = newnode(1);
	head->next = newnode(2);
	head->next->next = newnode(3);
	head->next->next->next = newnode(4);
	head->next->next->next = head; //here is the loop that is pointing to the head node.
	
	bool response = detectLoop(head);
	if(response) cout<<"Yes!"<<endl;
	else cout<<"No!"<<endl;
	
	return 0;
}
