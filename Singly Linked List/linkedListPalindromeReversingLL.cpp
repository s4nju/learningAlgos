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

node* reverse(node* ptr){
	node *temp = ptr, *nex = ptr, *prev = NULL;
	while(nex != NULL){
		temp = nex->next;
		nex->next = prev;
		prev = nex;
		nex = temp;
	}
	
	return prev;
}

bool check(node* head){
	int size = 0;
	node* temp = head;
	
	while(temp != NULL){
		++size;
		temp = temp->next;
	}
	
	temp = head;
	int count = size/2;
	while(count--){
		temp = temp->next;
	}
	//temp - > data = 3
	
	node* reversed = reverse(temp);
	node* a = head;
	node* treversed = reversed;
	while(reversed && a){
		if(reversed->data != a->data) return false;
		else{
			reversed = reversed->next;
			a = a->next;
		}
	}

	return true;
}

int main(){
	node* head = newnode(1);
	head->next = newnode(2);
	head->next->next = newnode(3);
	head->next->next->next = newnode(3);
	head->next->next->next->next = newnode(2);
	head->next->next->next->next->next = newnode(1);
	
	if(check(head)) cout<<"Yes!"<<endl;
	else cout<<"No!"<<endl;
}
