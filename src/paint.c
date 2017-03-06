/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   paint.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mseinic <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/16 13:16:07 by mseinic           #+#    #+#             */
/*   Updated: 2016/03/25 14:38:49 by mseinic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <window.h>
#include <fractol.h>

int		def_paint(t_env *env)
{
	create_fract(env, env->fractal_type);
	mlx_string_put(MLX, WIN, 10, 10, 0x00FFFFFF, "blablabla");
	return (0);
}
