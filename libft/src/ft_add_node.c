/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add_node.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mseinic <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/02 19:47:12 by mseinic           #+#    #+#             */
/*   Updated: 2015/12/02 20:13:53 by mseinic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_add_node(int new_value, t_node **node)
{
	if (*node == NULL)
	{
		*node = (t_node *)malloc(sizeof(t_node));
		(*node)->val = new_value;
		(*node)->left = NULL;
		(*node)->right = NULL;
	}
	else if (new_value < (*node)->val)
		ft_create_node(new_value, &(*node)->left);
	else if (new_value > (*node)->val)
		ft_create_node(new_value, &(*node)->right);
}
