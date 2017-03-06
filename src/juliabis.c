/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mseinic <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/15 19:35:30 by mseinic           #+#    #+#             */
/*   Updated: 2016/04/13 17:12:37 by mseinic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fractol.h>

static size_t			juliabis_iter(t_fract *fract, size_t maxiter)
{
	double	tmp;
	int		i;

	tmp = 0.0;
	fract->iter = 0;
	while (fract->iter < maxiter &&
			(fract->z.r * fract->z.r + fract->z.i * fract->z.i) <= 4)
	{
		i = 0;
		while (i < 2)
		{
			tmp = fract->z.r;
			fract->z.r = fract->z.r * fract->z.r -
				fract->z.i * fract->z.i + fract->c.r;
			fract->z.i = 2 * fract->z.i * tmp + fract->c.i;
			i++;
		}
		fract->iter++;
	}
	return (fract->iter + fract->z.r - fract->z.i);
}

static void				coordonates(t_fract *fract, t_env *env)
{
	fract->z.r = fract->c.r;
	fract->z.i = fract->c.i;
	fract->c.r = 0.2 + env->key.x;
	fract->c.i = 0.002 + env->key.y;
}

static void				create_juliabis(t_env *env)
{
	t_fract		fract;

	ft_bzero(&fract, sizeof(t_fract));
	while (fract.y < WIN_H)
	{
		fract.x = 0;
		while (fract.x < WIN_W)
		{
			fract.c.r = (fract.x - WIN_W * 0.5) * RATIO /
				(env->key.zoom * WIN_W) + env->key.move_sides;
			fract.c.i = (fract.y - WIN_H * 0.5) /
				(env->key.zoom * WIN_H) + env->key.move_updown;
			coordonates(&fract, env);
			fract.iter = juliabis_iter(&fract, env->maxiter);
			if (fract.iter < env->maxiter)
				my_pixel_put_to_image(env, get_color(fract.iter, env),
						fract.x, fract.y);
			else
				my_pixel_put_to_image(env, 0x000000, fract.x, fract.y);
			fract.x++;
		}
		fract.y++;
	}
}

void					draw_juliabis(t_env *env)
{
	create_juliabis(env);
}
