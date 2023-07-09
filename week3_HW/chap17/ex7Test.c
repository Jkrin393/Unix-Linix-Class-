#include <stdlib.h>
#include <stdio.h>

void main(){
	
	//define a node in the LL	
	typedef struct Node{
		int data;
		struct Node* next;
	} Node;

	//create a new node
	Node* add_node(int data){
		Node* new_node = malloc(sizeof(Node));
		
		if(new_node == NULL){
			printf("failed");
			exit(1);
		}
		new_node->data = data;
		new_node->next = NULL;
		
		return new_node;

	}//end add node
	
	//create nodes
	Node* head = add_node(220);
	Node* one = add_node(441);
	Node* two = add_node(662);

	//link nodes
	head->next = one;
	one->next = two;

	Node* current = head; //iterator variable
	while(current!= NULL){
		printf("value: %d\n", current->data);
		current = current->next;
	}

	//free nodes
	//temp node to assign to before deleteing from the list
	Node* temp;
	current = head; //iterator variable
	while(current!= NULL){
		temp = current;
		current = current->next;
		free(temp);

	}
	
	printf("value: %d\n", head->data);
	printf("value: %d\n", one->data);
	printf("value: %d\n", two->data);
	
	
	

	

}//end main
