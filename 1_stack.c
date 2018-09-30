/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qpeng <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/29 02:45:58 by qpeng             #+#    #+#             */
/*   Updated: 2018/09/30 01:01:47 by qpeng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

struct s_node {
    void          *content;
    struct s_node *next;
};

struct s_stack {
    struct s_node *top;
};

struct s_stack *init(void)
{
	struct s_stack *s;

	if (!(s = (struct s_stack *)malloc(sizeof(struct s_stack))))
		return (NULL);
	s->top = NULL;
	return (s);
}

void *pop(struct s_stack *stack)
{
	if (!stack || stack->top == NULL)
		return (NULL);
	struct s_node *node;
	void *p;

	node = stack->top;
	if (!(p = node->content))
		return (NULL);
	stack->top = node->next;
	free(node);
	return (p);
}

void push(struct s_stack *stack, void *content)
{
	struct s_node *node;

	if (!(node = (struct s_node *)malloc(sizeof(struct s_node ))))
		return ;
	node->content = content;
	node->next = stack->top;
	stack->top = node;
}

void *peek(struct s_stack *stack)
{
	if (!stack || stack->top == NULL)
		return (NULL);
	if (!stack->top->content)
		return (NULL);
	return (stack->top->content);
}

int isEmpty(struct s_stack *stack)
{
	if (stack && stack->top == NULL)
		return (1);
	else
		return (0);
}
