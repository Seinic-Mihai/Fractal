/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mseinic <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/13 18:22:05 by mseinic           #+#    #+#             */
/*   Updated: 2017/01/19 18:15:34 by mseinic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fractol.h>

static int		env_init(t_env *env)
{
	env->key.zoom = 0.3;
	env->key.zoomx = 0.0;
	env->key.zoomy = 0.0;
	env->color.r = 1.0;
	env->color.g = 2.0;
	env->color.b = 3.0;
	env->maxiter = 50;
	return (0);
}

static int		func_init(t_env *env)
{
	EXPOSE = def_expose_hook;
	KEY_HOOK = def_key_hook;
	PAINT = def_paint;
	MOUSE = def_mouse_hook;
	MOUSE_MOVE = def_mouse_move_hook;
	return (0);
}

static int		create_env(t_env *env)
{
	if (!(MLX = mlx_init()))
		return (1);
	ft_putstr("\033[1;34mMLX init : \033[0;32mOK\n\033[0m");
	if (!(WIN = mlx_new_window(MLX, WIN_W, WIN_H, "Graphics")))
		return (2);
	ft_putstr("\033[1;34mWIN init : \033[0;32mOK\n\033[0m");
	if (!(IMG = mlx_new_image(MLX, WIN_W, WIN_H)))
		return (3);
	ft_putstr("\033[1;34mIMG init : \033[0;32mOK\n\033[0m");
	if (!(PIX = mlx_get_data_addr(IMG, &BITS_PER_PIX, &LINE_SIZE, &ENDIAN)))
		return (4);
	ft_putstr("\033[1;34mIMG_DATA init : \033[0;32mOK\n\033[0m");
	if (!(env->menu = mlx_new_window(MLX, 600, 400, "Menu")))
		return (5);
	func_init(env);
	mlx_expose_hook(WIN, EXPOSE, (void *)env);
	mlx_hook(WIN, 2, 0, KEY_HOOK, (void *)env);
	mlx_hook(WIN, 6, 4, MOUSE_MOVE, (void *)env);
	mlx_mouse_hook(WIN, MOUSE, (void *)env);
	mlx_do_key_autorepeaton(MLX);
	return (0);
}

static void		ft_error(int status)
{
	ft_putstr_fd("\033[0;91mFailed to init at ", 2);
	ft_putnbr_fd(status, 2);
	ft_putstr_fd("\033[0m\n", 2);
}

int				main(int ac, char **av)
{
	t_env	env;
	int		status;

	ft_bzero(&env, sizeof(t_env));
	env_init(&env);
	if (ac == 2 && (env.fractal_type = list_fract(ac, av)) > 0)
	{
		if ((status = create_env(&env)))
			ft_error(status);
		else
		{
			create_fract(&env, env.fractal_type);
			mlx_loop(env.mlx);
		}
	}
	else
		menu();
	return (0);
}
