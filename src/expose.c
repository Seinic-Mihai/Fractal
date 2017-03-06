/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expose.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mseinic <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/16 13:02:19 by mseinic           #+#    #+#             */
/*   Updated: 2016/04/15 16:52:13 by mseinic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <window.h>
#include <fractol.h>

static int		print_menu(t_env *env)
{
	mlx_string_put(MLX, env->menu, 10, 10, 0x00ffffff,
			"'0' - '9' Change the collors of fractol");
	mlx_string_put(MLX, env->menu, 10, 40, 0x00ffffff,
			"The arrows are for moving the camera");
	mlx_string_put(MLX, env->menu, 10, 60, 0x00ffffff,
			"'+' for increasing the iterations");
	mlx_string_put(MLX, env->menu, 10, 80, 0x00ffffff,
			"'-' for decreasing the iterations");
	mlx_string_put(MLX, env->menu, 10, 100, 0x00ffffff,
			"'*' to put the iterations directly at 600");
	mlx_string_put(MLX, env->menu, 10, 120, 0x00ffffff,
			"'/' to put the iterations directly at 9");
	mlx_string_put(MLX, env->menu, 10, 140, 0x00ffffff,
			"'Enter' for Julia to trigger hold \\ unhold");
	mlx_string_put(MLX, env->menu, 10, 160, 0x00ffffff,
			"And use mouse to zoom or unzoom the fractal");
	mlx_string_put(MLX, env->menu, 10, 180, 0x00ffffff,
			"'Esc' to quit the programm");
	return (0);
}

int				def_expose_hook(void *param)
{
	t_env *const env = param;

	mlx_clear_window(MLX, WIN);
	env->fnct.paint(env);
	mlx_put_image_to_window(MLX, WIN, IMG, 0, 0);
	print_menu(env);
	return (0);
}
