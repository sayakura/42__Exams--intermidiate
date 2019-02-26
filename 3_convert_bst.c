typedef struct s_node {
		int           value;
		struct s_node *right;
		struct s_node *left;
	} Node;


Node *re(Node *r)
{
	if (!r)
		return (0);
	if (r->left)
	{
		Node *t = re(r->left);
		while (t->right)
			t = t->right;
		t->right = r;
		r->left = t;
	}
	if (r->right)
	{
		Node *t = re(r->right);
		while(t->left)
			t = t->left;
		t->left = r;
		r->right = t;
	}
	return r;
}

	struct s_node *convert_bst(struct s_node *bst)
{
	if (!bst)
		return (0);
	re(bst);
	Node *left = bst;
	Node *right = bst;
	while (left->left)
		left = left->left;
	while (right->right)
		right = right->right;
	left->left = right;
	right->right = left;
	return left;
}
/*
#include <stdlib.h>
Node *new(int val)
{	
	Node *t = malloc(sizeof(Node));
	t->value = val;
	t->left = NULL;
	t->right = NULL;
	return t;
}
#include <stdio.h>
int main(void)
{
	Node *a = new(8);
	a->left = new(3);
	a->right = new(9);
	a->left->left = new(1);
	a->left->right = new(4);
	a->right->right = new(10);
	Node *t =convert_bst(a);
	for (int  i = 0; i < 6;i++)
	{
		printf("%d ", t->value);
		t = t->right;
	}
	printf("\n");
	return (0);
}*/
