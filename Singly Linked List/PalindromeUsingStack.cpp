//Implementation to check palindrome using stack.
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

bool check(node* head){
	node *temp = head;
	node *ptr;
	stack<node*> stk;
	
	while(head != NULL){
		stk.push(head);
		head = head->next;
	}
	
	while(!stk.empty() && temp != NULL){
		ptr = stk.top();
		if(ptr->data != temp->data){
			return false;
		}
		else{
			temp = temp->next;
		}
		
		stk.pop();
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
