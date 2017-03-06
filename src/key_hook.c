/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mseinic <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/16 13:09:46 by mseinic           #+#    #+#             */
/*   Updated: 2016/04/15 16:35:41 by mseinic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fractol.h>

static void		colors2(int keycode, t_env *env)
{
	if (keycode == 29)
	{
		env->color.r = 1.0;
		env->color.g = 2.0;
		env->color.b = 3.0;
	}
	else if (keycode == 26)
	{
		env->color.r = -60.0;
		env->color.g = -50.0;
		env->color.b = -70.0;
	}
	else if (keycode == 28)
	{
		env->color.r = -10.0;
		env->color.g = -20.0;
		env->color.b = -30.0;
	}
	else if (keycode == 25)
	{
		env->color.r = 80.0;
		env->color.g = 30.0;
		env->color.b = 120.0;
	}
}

static void		colors1(int keycode, t_env *env)
{
	if (keycode == 21)
	{
		env->color.r = 10.0;
		env->color.g = 150.0;
		env->color.b = 10.0;
	}
	else if (keycode == 22)
	{
		env->color.r = 100.0;
		env->color.g = 20.0;
		env->color.b = 30.0;
	}
	else if (keycode == 23)
	{
		env->color.r = 30.0;
		env->color.g = 30.0;
		env->color.b = 30.0;
	}
	else
		colors2(keycode, env);
}

static void		colors(int keycode, t_env *env)
{
	if (keycode == 18)
	{
		env->color.r = 10.0;
		env->color.g = 20.0;
		env->color.b = 30.0;
	}
	else if (keycode == 19)
	{
		env->color.r = 70.0;
		env->color.g = 80.0;
		env->color.b = 100.0;
	}
	else if (keycode == 20)
	{
		env->color.r = 50.0;
		env->color.g = 30.0;
		env->color.b = 10.0;
	}
	else
		colors1(keycode, env);
}

static void		holding(t_env *env, int keycode)
{
	if (keycode == 36)
	{
		if (env->key.holding == 1)
			env->key.holding = 0;
		else
			env->key.holding = 1;
	}
}

int				def_key_hook(int keycode, void *param)
{
	t_env *const env = param;

	if (keycode == 53)
		exit(0);
	else if (keycode == 123)
		env->key.move_sides -= 0.2 / env->key.zoom;
	else if (keycode == 124)
		env->key.move_sides += 0.2 / env->key.zoom;
	else if (keycode == 126)
		env->key.move_updown -= 0.2 / env->key.zoom;
	else if (keycode == 125)
		env->key.move_updown += 0.2 / env->key.zoom;
	else if (keycode == 69 && env->maxiter <= 600)
		env->maxiter += 5;
	else if (keycode == 78 && env->maxiter > 9)
		env->maxiter -= 5;
	else if (keycode == 67)
		env->maxiter = 600;
	else if (keycode == 75)
		env->maxiter = 9;
	else
		colors(keycode, env);
	holding(env, keycode);
	env->fnct.expose_hook(env);
	return (0);
}
