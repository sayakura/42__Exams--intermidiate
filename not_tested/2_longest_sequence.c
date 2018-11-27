/* ***************************************************************************
 * File    : 2_longest_sequence.c
 * Author  : Kura Peng (kpeng) <https://github.com/sayakura>
 * Created : 2018/10/18
 * Updated : 2018/10/18
 * ***************************************************************************/

#include <stdlib.h>
#include <stdio.h>

struct s_node 
{
	int value;
	struct s_node *left;
	struct s_node *right;
};

typedef struct s_node t_node;

#define max(a, b) (a < b) ? b : a

int	lcp2(t_node *root, int value, int max)
{
	if (root == NULL)
		return (0);
	int current = 1;
	if (value + 1 == root->value)
		current = max + 1;
	return	max(
				max(lcp2(root->left, root->value, current),
				lcp2(root->right, root->value, current)),
			current);
}

void	lcp(t_node *root, int curr, int expected, int *res)
{
	if (root == NULL)
		return ;
	if (root->value == expected)
		curr++;
	else
		curr = 1;

	*res = max(*res, curr);
	lcp(root->left, curr, root->value + 1, res);
	lcp(root->right, curr, root->value + 1, res);
}

int	longest_sequence(struct s_node *node)
{
	if (node == NULL)
		return (0);
	int res = 0;
	lcp(node, 0, node->value, &res);
	return res;
}

t_node *create_nod(int value)
{
	t_node *node = (t_node *)malloc(sizeof(t_node));
	node->value = value;
	node->left = NULL;
	node->right = NULL;
	return (node);
}

int	main(void)
{
	t_node *n1 = create_nod(10);
	n1->right = create_nod(9);
	n1->right->right = create_nod(11);
	n1->left = create_nod(5);
	n1->left->left = create_nod(6);
	n1->left->left->left = create_nod(7);
	printf("%d\n", longest_sequence(n1));
	return (0);
}
