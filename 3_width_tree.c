/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   width_tree.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/27 10:14:11 by exam              #+#    #+#             */
/*   Updated: 2018/11/27 10:19:14 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

struct s_node
{
	int value;
	struct s_node *left;
	struct s_node *right;
};

#define max(a, b) (a > b ? a : b)

int	longest(struct s_node *n){
	if (!n)
		return (0);
	return max(longest(n->left), longest(n->right)) + 1;
}

int	width_tree(struct s_node *n)
{
	if (!n)
		return (0);
	int width = longest(n->left) + longest(n->right) + 1;
	return max(max(width_tree(n->left), width_tree(n->right)), width);
}
