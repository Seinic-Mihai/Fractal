/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_hook.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mseinic <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/22 16:40:19 by mseinic           #+#    #+#             */
/*   Updated: 2016/04/15 16:18:39 by mseinic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <window.h>
#include <fractol.h>

static void		zoom_in_1(t_env *env, int x, int y)
{
	env->key.move_sides += (((double)x) - ((double)WIN_W) * 0.5) *
		RATIO / (env->key.zoom * (double)WIN_W);
	env->key.move_updown += (((double)y) - ((double)WIN_H) * 0.5) /
		(env->key.zoom * (double)WIN_H);
}

static void		zoom_in_2(t_env *env, int x, int y)
{
	env->key.move_sides -= (((double)x) - ((double)WIN_W) * 0.5) *
		RATIO / (env->key.zoom * (double)WIN_W);
	env->key.move_updown -= (((double)y) - ((double)WIN_H) * 0.5) /
		(env->key.zoom * (double)WIN_H);
}

int				def_mouse_hook(int button, int x, int y, void *param)
{
	t_env *const env = param;

	if (x > 0 && y > 0 && x < WIN_W && y < WIN_H)
	{
		if (button == 1 || button == 5)
		{
			zoom_in_1(env, x, y);
			env->key.zoom *= 1.2;
			zoom_in_2(env, x, y);
		}
		if ((button == 2 || button == 4) && env->key.zoom > 0.1)
		{
			zoom_in_1(env, x, y);
			env->key.zoom /= 1.2;
			zoom_in_2(env, x, y);
		}
		env->fnct.expose_hook(env);
	}
	return (0);
}

int				def_mouse_move_hook(int x, int y, void *param)
{
	t_env *const env = param;

	while (x > 0 && y > 0 && x < WIN_W && y < WIN_H && env->key.holding == 0)
	{
		env->key.x = (x - WIN_W * 0.5) * RATIO /
			(env->key.zoom * WIN_W) + env->key.move_sides;
		env->key.y = (y - WIN_H * 0.5) /
			(env->key.zoom * WIN_H) + env->key.move_updown;
		env->fnct.expose_hook(env);
		return (0);
	}
	return (0);
}
