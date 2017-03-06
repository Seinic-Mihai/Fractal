/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_fract.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mseinic <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/15 19:29:29 by mseinic           #+#    #+#             */
/*   Updated: 2016/04/13 17:09:06 by mseinic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fractol.h>

void	create_fract(t_env *env, int fract)
{
	if (fract == 2)
		draw_julia(env);
	else if (fract == 3)
		draw_mandel(env);
	else if (fract == 4)
		draw_tree(env);
	else if (fract == 5)
		draw_juliabis(env);
	else if (fract == 6)
		draw_bacteria(env);
	else if (fract == 7)
		draw_fuzzy(env);
	else if (fract == 8)
		draw_burn(env);
	else if (fract == 9)
		draw_lapin(env);
}
