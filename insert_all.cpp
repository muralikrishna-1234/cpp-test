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

node* insert_at_pos(node* head, int n, int pos){
	node dummy(0);
	dummy.next = head;
	node* temp = &dummy;

	node* new_node = get_new_node(n);
	for(int i =1; i < pos ; i++){
		temp = temp->next;
	}
	new_node->next = temp->next;
	temp->next = new_node;

	return dummy.next;
}

node* insert_at_end(node* head, int n){
	node dummy(0);
	dummy.next = head;
	node* temp = &dummy;
	node* new_node = get_new_node(n);
	while(temp && temp->next){
		temp = temp->next;
	}
	temp->next = new_node;
	return dummy.next;
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
	head = insert_at_pos(head, 5, 5);
	display(head);

	head = insert_at_end(head, 6);
	display(head);
	return 0;
}
