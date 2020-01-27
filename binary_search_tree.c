#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
	int num;
	struct node *left;
	struct node *right;
}node;

node * appendTree(node **root, int num)
{
	node *new_node = malloc(sizeof(node));
	new_node->num = num;
	new_node->left = NULL;
	new_node->right = NULL;

	if (*root == NULL)
	{
		*root = new_node;
		return *root;
	}

	if (new_node->num > (*root)->num)
	{
		return appendTree(&(*root)->right, num);
	}
	else
	{
		return appendTree(&(*root)->left, num);
	}


}

void searchTree(node *root, int num)
{

	if (root == NULL)
	{
		printf("%i not found\n\n", num);
	}
	else if (root->num == num)
	{
		printf("%i found\n\n", num);
	}
	else if (root->num < num)
	{
		searchTree(root->right, num);
	}
	else if (root->num > num)
	{
		searchTree(root->left, num);
	}
	return;
}

void printTree(node *root)
{
	if (root != NULL)
	{
		printTree(root->left);
		printf("%i\n", root->num);
		printTree(root->right);
	}
	return;

}
void freeTree(node *root)
{
	
	if (root != NULL)
	{
		freeTree(root->left);
		freeTree(root->right);
		free(root);
	}
	return;

}

int main(int argc, char *argv[])
{
	node *tree = NULL;
	appendTree(&tree,5);
	appendTree(&tree,4);
	appendTree(&tree,6);
	appendTree(&tree,2);
	if (argc > 1)
	{
		appendTree(&tree, atoi(argv[1]));
	}
	if (argc > 2)
	{
		searchTree(tree, atoi(argv[2]));
	}
	printTree(tree);
	searchTree(tree, 6);
	freeTree(tree);
	return 0;
}