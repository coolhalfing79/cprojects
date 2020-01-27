#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
	int data;
	struct node *next;
	//struct node *prev;
}node;

int printl(node *head)
{
	node *tmp = head;
	while(tmp != NULL)
	{
		printf("%i->", tmp->data);
		tmp = tmp->next;
	}
	printf("\n");
}

int append(node **head, int num){
	node *tmp = (node *)malloc(sizeof(node));
	if (tmp == NULL)
	{
		return 1;
	}
	tmp->data = num;
	tmp->next = NULL;

	if (*head == NULL)
	{
		*head = tmp;
		return 0;
	}

	node *trav = *head;
	while(trav->next != NULL)
	{
		trav = trav->next;
	}
	trav->next = tmp;
	return 0;
}

void freel(node **head)
{
	node *tmp;
	while (*head != NULL)
	{
		tmp = *head;
		*head = (*head)->next;
		free(tmp);
	}
}

int main(int argc, const char *argv[])
{
	node *l1 = NULL;
	append(&l1, 5);
	append(&l1, 20);
	append(&l1, 10);
	append(&l1, 30);
	append(&l1, 30);
	append(&l1, 30);
	append(&l1, 30);
	printl(l1);
	freel(&l1);
	printl(l1);
	return 0;
}