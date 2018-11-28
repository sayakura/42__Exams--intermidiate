typedef struct s_node {
		void *content;
		struct s_node *next;
} Node;

typedef struct s_queue {
	struct s_node *first;
	struct s_node *last;
} Queue;

#include <stdlib.h>
Node *newNode(void *item)
{
	Node *this = malloc(sizeof(Node));
	this->content = item;
	this->next = 0;
	return this;
}

Queue *init(void)
{
	Queue *new = malloc(sizeof(Queue));
	new->first = 0;
	new->last = 0;
	return new;
}

void	enqueue(Queue *q, void *item){
	if (q->last)
	{
		(q->last)->next = newNode(item);
		if (q->first == q->last)
			q->first->next = q->last->next;
		(q->last) = (q->last)->next;
	}
	else{
		q->last = newNode(item);
		q->first = q->last;
	}
}

void	*dequeue(Queue *queue)
{
	if (queue->first == 0)
		return  NULL;
	else
	{
		void * temp;
		temp = queue->first->content;
		if (queue->last == queue->first)
			queue->last = queue->first->next;
		queue->first = queue->first->next;

		return temp;
	}
}

void	*peek(Queue *queue)
{
 if (queue->first == 0)
        return  NULL;
    else
    {
        void * temp;
        temp = queue->first->content;
        return temp;
    }
}


int isEmpty(struct s_queue *queue)
{
	return (queue->first == 0);

}


