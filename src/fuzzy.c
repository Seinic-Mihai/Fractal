/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mseinic <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/15 19:35:30 by mseinic           #+#    #+#             */
/*   Updated: 2016/04/13 15:06:22 by mseinic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fractol.h>

static size_t			fuzzy_iter(t_fract *fract, size_t maxiter)
{
	t_cmplx	tmp;

	ft_bzero(&tmp, sizeof(t_cmplx));
	fract->iter = 0;
	while (fract->iter < maxiter && hypot(tmp.r, tmp.i) < 1.1)
	{
		tmp.r = 0.5 - fabsl(fract->z.r - fract->z.i);
		fract->z.i = 1 - fabsl(fract->z.i - (1 - fract->z.r));
		fract->z.r = tmp.r;
		fract->iter++;
	}
	return (fract->iter);
}

static void				create_fuzzy(t_env *env)
{
	t_fract		fract;

	ft_bzero(&fract, sizeof(t_fract));
	while (fract.y < WIN_H)
	{
		fract.x = -1;
		while (++fract.x < WIN_W)
		{
			fract.z.r = (fract.x - WIN_W * 0.5) * RATIO /
				(env->key.zoom * WIN_W) + env->key.move_sides;
			fract.z.i = (fract.y - WIN_H * 0.5) /
				(env->key.zoom * WIN_H) + env->key.move_updown;
			fuzzy_iter(&fract, env->maxiter);
			if (fract.iter > 8 && fract.iter < env->maxiter)
				my_pixel_put_to_image(env, get_color(fract.iter, env),
						fract.x, fract.y);
			else if (fract.iter <= 8)
				my_pixel_put_to_image(env, 0xffffff, fract.x, fract.y);
			else
				my_pixel_put_to_image(env, 0x000000, fract.x, fract.y);
		}
		fract.y++;
	}
}

void					draw_fuzzy(t_env *env)
{
	create_fuzzy(env);
}
