#include<iostream>

struct node {
	int data;
	node* next;
	node(int n){
		data = n;
		next = nullptr;
	}
};
node* get_new_node(int n){
	return new node(n);
}
node* insert_at_begin(node* head, int n){
	node* new_node = get_new_node(n);
	new_node->next = head;
	return new_node;
}

void display(node* head){
	while(head){
		std::cout<<head->data<<" ";
		head = head->next;
	}
	std::cout<<std::endl;
}

int main(){
	node* head = nullptr;
	head = insert_at_begin(head,1);
	head = insert_at_begin(head,2);
	head = insert_at_begin(head,3);
	head = insert_at_begin(head,4);

	display(head);
	return 0;
}
