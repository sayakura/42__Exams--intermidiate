/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   2_is_looping.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qpeng <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/04 02:09:14 by qpeng             #+#    #+#             */
/*   Updated: 2018/10/04 02:09:17 by qpeng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

typedef struct s_node {
	int value;
	struct s_node *next;
} Node;
/* works but seems too naive*/
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
