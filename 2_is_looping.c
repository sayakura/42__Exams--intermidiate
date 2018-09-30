typedef struct s_node {
	int value;
	struct s_node *next;
} Node;

int is_looping(Node* node) {
	
	Node* i = node;
	Node* j = node;

	while (i && j)
	{
		i = i->next;
		j = j->next;
		if (j)
			j = j->next;
		if (i && j && i == j)
			return (1);
	}
	return (0);
}
