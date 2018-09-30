/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   queue.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qpeng <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/29 02:26:59 by qpeng             #+#    #+#             */
/*   Updated: 2018/09/29 02:27:08 by qpeng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

struct s_node {
	void *content;
	struct s_node *next;
};
struct s_queue {
	struct s_node *first;
	struct s_node *last;
};

struct s_queue *init(void)
{
	struct s_queue *sq;

	sq = (struct s_queue *)malloc(sizeof(struct s_queue));
	sq->first = NULL;
	sq->last = NULL;
	return (sq);
}

void enqueue(struct s_queue *queue, void *content)
{
	if (queue == NULL)
		return ;
	struct s_node *node;

	if (!(node = (struct s_node *)malloc(sizeof(struct s_node))))
		return ;
	node->content = content;
	node->next = NULL;
	queue->last->next = node;
	queue->last = node;
}

void *dequeue(struct s_queue *queue)
{
	if (queue == NULL || queue->first == NULL)
		return (NULL);
	struct s_node *node;

	node = queue->first;
	if (node->next != NULL)
		queue->first = node->next;
	else
		queue->first = NULL;
	return (node->content);
}

void *peek(struct s_queue *queue)
{
	if (queue == NULL|| queue->first == NULL)
		return (NULL);
	struct s_node *node;

	node = queue->first;
	return (node->content);
}

int isEmpty(struct s_queue *queue)
{
	if (queue == NULL || queue->first == NULL)
		return (1);
	else
		return (0);
}