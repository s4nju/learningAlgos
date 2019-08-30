//Find length of LL in interative and recursive fashion
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

int itercount(node *head){
	int count = 0;
	while(head->next != NULL){
		count++;
		head = head->next;
	}
	
	return count;
}

int recurCount(node *head){
	if(head->next == NULL) return 0;
	
	return 1 + recurCount(head->next);
}

int main(){
	struct node *head = newnode(1);
	head->next = newnode(2);
	head->next->next = newnode(3);
	head->next->next->next = newnode(4);
	
	cout<<"Iter Count: "<<itercount(head)<<endl;
	cout<<"Recur Count: "<<recurCount(head)<<endl;
	
	return 0;
}
