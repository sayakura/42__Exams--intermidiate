/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_tree.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qpeng <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/30 00:45:10 by qpeng             #+#    #+#             */
/*   Updated: 2018/10/04 02:10:20 by qpeng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <stdlib.h>

struct           s_node
{
	int            value;
	struct s_node  *right;
	struct s_node  *left;
};

void             reverse_tree(struct s_node *root)
{
  if (root != NULL)
  {
    struct s_node *tmp;

    tmp = root->right;
    root->right = root->left;
    root->left = tmp;
    reverse_tree(root->left);
    reverse_tree(root->right);
  }
  return ;
}
