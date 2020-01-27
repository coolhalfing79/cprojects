#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node
{
	char *name;
	struct node *next;
}node;

void inittialize(node *hash_array[])
{
	for (size_t i = 0; i < 26; i++)
	{
		hash_array[i] = NULL;
	}
	return;
}

void append(node **head, char *name)
{
	node *new_node = malloc(sizeof(node));
	new_node->name = name;
	new_node->next = NULL;

	if (*head == NULL)
	{
		*head = new_node;
	}
	else
	{
		node *tmp = *head;
		while (tmp->next != NULL)
		{
			tmp = tmp->next;
		}
		tmp->next = new_node;
	}
	return;
}

void add_name(node *hash_array[], char *name)
{
	if ((int) *name > 90)
	{
		printf("please enter capitalized name\n");
		return;
	}
	int alpha = ((int) *name)-65;
	append(&hash_array[alpha], name);
}

void printList(node **head)
{
	node *tmp = *head;
	while (tmp != NULL)
	{
		printf("%s->", tmp->name);
		tmp = tmp->next;
	}
	
}

void printTable(node *hash_array[])
{
	for (size_t i = 0; i < 26; i++)
	{
		printList(&hash_array[i]);
		printf("\n");
	}
	
}

void searchTable(node *hash_array[], char *name)
{
	int alpha = (int) *name-65;
	node *tmp = hash_array[alpha];
	if (tmp == NULL)
	{
		printf("%s not found\n", name);
		return;
	}
	while(tmp != NULL)
	{
		if (strcmp(name, tmp->name) == 0)
		{
			printf("%s found\n", tmp->name);
			return;
		}
		tmp = tmp->next;
	}
	printf("%s not found\n", tmp->name);
	return;
}

int main (int argc, char *argv[])
{
	node *hash_array[26];
	inittialize(hash_array);
	if (argc > 1)
	{
		for (size_t i = 1; i < argc; i++)
		{
			add_name(hash_array, argv[i]);
		}
		
	}
	
	printTable(hash_array);
	searchTable(hash_array, "Anup");
}