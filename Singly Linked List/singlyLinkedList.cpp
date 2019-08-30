#include<iostream>
using namespace std;

struct node{
	int data;
	node *next;
};

class singlyll{
	private:
		struct node *front;
		struct node *rear;
	public:
		void push(int ele);
		int pop();
		void print(singlyll &a);
		node *first() {
			return front;
		}
};

void singlyll::push(int ele){
	struct node *temp = new node;
	temp->data = ele;
	if(front == NULL){
		front = temp;
		rear = temp;
		return;
	}
	rear->next = temp;
	rear = temp;
}

int singlyll::pop(){
	if(front == NULL) return -1;
	
	int f = front->data;
	front = front->next;
	if(front==NULL) front = NULL;
	
	return f;
}

void singlyll::print(singlyll &a){
	struct node *temp = new node;
	temp->next = a.first();
	while(temp != NULL){
		cout<<temp->data<<endl;
	}
}

void mid_trav(struct node *head, int mid){
	
}


int count(struct node *head){
	struct node *temp = head;
	int c = 0;
	while(temp != NULL){
		temp = temp->next;
		c += 1;
	}
	
	return c;
}

int main(){
	
	singlyll *ll = new singlyll();
	ll->push(10);
	ll->push(20);
	ll->push(30);
	ll->push(11);
	ll->push(12);
	ll->push(15);
	
	cout<<"Count: "<<count(head)
	
	cout<<ll->pop()<<endl;
	cout<<ll->pop()<<endl;
	cout<<ll->pop()<<endl;
	
	//ll->print(*ll);
	
	
	return 0; 
}
