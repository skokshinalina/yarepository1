#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

typedef struct node
{
	int data;
	struct node * left;
	struct node * right;
	struct node * roditel;
}
node;

typedef struct tree {
	struct node * root;

	int c;
}
tree;

void init(tree* t)
{
	struct tree * new_tree = malloc(sizeof new_tree);
	new_tree->root = NULL;
	new_tree->c = 0;
	t = new_tree;
}

int find(tree* t, int zna4, node* n)
{
	struct node * str2;
	str2 = t->root;
	if (t->root == NULL)
	{
		return 1;
	}

	while (1)
	{
		if (str2 == NULL)
		{
			return 1;
		}
		else if (str2->data == zna4)
		{
			n->data = str2->data;
			n->left = str2->left;
			n->right = str2->right;
			n->roditel = str2->roditel;
			return 0;
		}
		else if (zna4 > str2->data)
		{
			str2 = str2->right;
		}
		else
		{
			str2 = str2->left;
		}
	}
	return 1;
}

int insert(tree* t, int zna4)
{
	struct node * n, ** strrrr, *pr_str = NULL;
	struct node * e_n;
	e_n = malloc(sizeof * e_n);
	int error_tree = find(t, zna4, e_n);
	if (error_tree == 0)
	{
		return 1;
	}
	strrrr = &t->root;
	n = t->root;
	while (1)
	{
		if (n == NULL)
		{
			n = *strrrr = malloc(sizeof * n);
			if (n != NULL)
			{
				n->data = zna4;
				n->left = NULL;
				n->right = NULL;
				n->roditel = pr_str;
				t->c++;
				return 0;
			}
			else
			{
				return 2;
			}
		}

		pr_str = n;
		if (zna4 > n->data)
		{
			strrrr = &n->right;
			n = n->right;
		}
		else
		{
			strrrr = &n->left;
			n = n->left;
		}
	}
	return 0;
}

int depth(struct node * n, int deep)
{
	if (n == NULL)
	{
		return deep;
	}
	int depth1 = depth(n->left, deep + 1);
	int depth2 = depth(n->right, deep + 1);
	return (depth1 > depth2) ? depth1 : depth2;
}

void printNode(struct node * n, int current, int deep, int first)
{
	if (current == deep)
	{
		if (first > 0)
		{
			printf(" ");
		}
		if (n == NULL)
		{
			printf(" ");
		}
		else
		{
			printf("%d", n->data);
		}
	}
	else if (n != NULL)
	{
		printNode(n->left, current + 1, deep, first);
		printNode(n->right, current + 1, deep, first + 1);
	}
	else
	{
		printNode(n, current + 1, deep, first);
		printNode(n, current + 1, deep, first + 1);
	}
}

void print(struct node * n)
{

	int m = depth(n, 0);
	for (int i = 1; i <= m; i++)
	{
		printNode(n, 1, i, 0);
		printf("\n");
	}
}

void printTree(struct tree * t)
{
	print(t->root);
}

void print_obh1(struct node * n)
{
	int m = depth(n, 0);
	int flag_tree = 0;
	for (int i = 1; i <= m; i++)
	{
		if (flag_tree > 0)
		{
			printf(" ");
		}
		else
		{
			flag_tree++;
		}
		printNode(n, 1, i, 0);
	}
}

int main()
{
	struct tree * t = malloc(sizeof t);
	init(t);
	for (int i = 0; i< 7; i++)
	{
		int a;
		scanf("%d", &a);
		insert(t, a);
	}
	print_obh1(t->root);
	printf("\n");
	return 0;
}
