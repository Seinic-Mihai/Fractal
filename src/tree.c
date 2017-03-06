/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mseinic <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/15 19:35:30 by mseinic           #+#    #+#             */
/*   Updated: 2016/04/13 17:10:54 by mseinic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fractol.h>

static void				tree_iter(t_fract *fract, size_t maxiter)
{
	t_cmplx	tmp;

	ft_bzero(&tmp, sizeof(t_cmplx));
	fract->iter = 0;
	while (fract->iter < maxiter &&
			(fract->z.r * fract->z.r + fract->z.i * fract->z.i) < 10)
	{
		tmp.r = (fract->z.r * fract->z.r) -
			(fract->z.i * fract->z.i) - fract->c.r;
		tmp.i = 2 * fabsl(fract->z.r * fract->z.i) - fract->c.i;
		fract->z.r = tmp.r;
		fract->z.i = tmp.i;
		fract->iter++;
	}
}

static void				coordonates(t_fract *fract)
{
	fract->z.r = fract->c.r;
	fract->z.i = fract->c.i;
	fract->c.r = 0.0987;
	fract->c.i = -0.2412;
}

static void				create_tree(t_env *env)
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
			coordonates(&fract);
			tree_iter(&fract, env->maxiter);
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

void					draw_tree(t_env *env)
{
	create_tree(env);
}
