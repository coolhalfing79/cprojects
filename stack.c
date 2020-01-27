#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
	int data;
	struct node *next;
}node;

void push(node **top, int num){
	node *new_node = malloc(sizeof(node));
	new_node->data = num;
	new_node->next = *top;
	*top = new_node;
}

int pop(node **top){
	node *tmp = *top;
	*top = (*top)->next;
	return tmp->data;
	free(tmp);
}

int main(int argc, int argv[]){
	node *stack = NULL;
	push(&stack, 5);
	push(&stack, 12);

	FILE
	printf("%d\n", pop(&stack));
}