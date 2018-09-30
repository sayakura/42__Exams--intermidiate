typedef struct s_node {
	int value;
	struct s_node *next;
} Node;

#define SIZE 1000000

char hash_table[SIZE] = {0};

int is_looping(Node *node)
{
	Node *temp = node;
	unsigned long key;
	while (temp)
	{
		key = ((unsigned long)&temp->next) % SIZE;
		if (hash_table[key] != 0)
			return (1);
		else
			hash_table[key] = 1;
		temp = temp->next;
	}
	return (0);
}
