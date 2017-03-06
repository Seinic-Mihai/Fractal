/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mseinic <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/13 14:44:49 by mseinic           #+#    #+#             */
/*   Updated: 2016/04/13 15:07:47 by mseinic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fractol.h>

unsigned int		get_color(int iter, t_env *env)
{
	return (((125 - (int)(125 * cos((double)iter / env->color.r))) << 16)
			+ ((125 + (int)(125 * sin((double)iter / env->color.g))) << 8)
			+ (125 + (int)(125 * cos((double)iter / env->color.b))));
}
