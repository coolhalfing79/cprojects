#include<stdio.h>
#include<stdlib.h>

struct node{
	int num;
	struct node * next;
};

void append(struct node ** head, int num){
	struct node * new_node = (struct node *)malloc(sizeof(struct node));
	new_node->num = num;
	new_node->next = NULL;

	if (*head == NULL){
		*head = new_node;
		return;
	}

	struct node * temp = *head;
	
	while (temp->next != NULL){
		temp = temp->next;
	}
	temp->next = new_node;
	return;

}

int printl(struct node *head)
{
	struct node *tmp = head;
	while(tmp != NULL)
	{
		printf("%i->", tmp->num);
		tmp = tmp->next;
	}
	printf("\n");
}

int main(){
	struct node * l1 = NULL;
	append(&l1, 5);
	append(&l1, 10);
	printl(l1);
}