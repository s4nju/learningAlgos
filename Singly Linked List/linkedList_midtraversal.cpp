#include "linked_list.h" //newnode and print

using namespace std;


struct node *head;
int main(){
	head = newnode(1);
//	head->next = newnode(2);
//	head->next->next = newnode(3);
//	head->next->next->next = newnode(4);
//	head->next->next->next->next = newnode(5);
//	head->next->next->next->next->next = newnode(6);
	push(head, 2);
	push(head, 3);
	print(head);
}
