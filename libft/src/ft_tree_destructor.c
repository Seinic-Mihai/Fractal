/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tree_destructor.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mseinic <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/02 19:57:28 by mseinic           #+#    #+#             */
/*   Updated: 2015/12/02 20:14:25 by mseinic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_tree_destructor(t_node *node)
{
	if (node != NULL)
	{
		ft_destructor_tree(node->left);
		ft_destructor_tree(node->right);
		free(node);
	}
}
