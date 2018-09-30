/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   height_tree.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qpeng <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/29 00:09:14 by qpeng             #+#    #+#             */
/*   Updated: 2018/09/29 02:22:17 by qpeng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>

struct s_node
{
   int           value;
   struct s_node **nodes;
};

 int height_tree(struct s_node *root)
{
	int cur_h = 0;
	int max_h = 0;
	unsigned i = 0;

	if (root == NULL)
		return (0);
	max_h = 0;
	while (root->nodes[i])
	{
		cur_h = height_tree(root->nodes[i]) + 1;
		if (cur_h > max_h)
			max_h = cur_h;
		i++;
	}
	return (max_h);
}
