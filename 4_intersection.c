struct s_node {
	void *content;
	struct s_node *next;
};

#include <stdlib.h>
void *intersection(struct s_node *lst1, struct s_node *lst2)
{
	while (lst1)
	{
		struct s_node *temp = lst2;
		while (temp)
		{
			if (lst1 == temp)
				return lst1;
			temp = temp->next;
		}
		lst1 = lst1->next;
	}
	return NULL;
}
