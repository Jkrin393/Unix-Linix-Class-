//Ex8, pg 454
//modify stack.c from secation 15.2 to use a linked list instaed of an array, remove is_full, and have push return true or false
//
//
//
#include <stdlib.h>
#include <stdio.h>

//functions to write
//make_empty()
//is_empty()
//push()
//pop()


//dont need to use a head/tail node if we treat the "top" node as the important one. If top-> next is null, our stack is empty, when we add a new node. it willi become the new topop. So pushing top->node1->null = top->node2->node1->nnull 

//if there is already a stack, it will be deleted
void make_empty(Node* top){

	Node* temp;
	current = top ; //iteratdor variable
	while(current!= NULL){
		temp = current;
		current = current->next;
		free(temp);

	}

	top == NULL;
	
}


int is_empty(){

	if(top->next==NULL)
		return true;
	
	return false;
}	

void push(int data){

	//create a new node
	
	Node* new_node = malloc(sizeof(Node));
	
	if(new_node == NULL){
		printf("failed");
		exit(1);
	}
	new_node->data = data;//set data to the new node
	new_node->next = top;//set new-node pointer to the old top
	top->next = new_node; //set the new node as the new top so
}

int pop(){
	if(isempty()){
		return -1;
	}
	int value = top->data;
	struct Node* temp = top;
	top = top->next;
	free(temp);
	return value;
}


int main(){
	//define a node in the LL	
	struct Node{
		int data;
		struct Node* next;
	};
	


}//end main
