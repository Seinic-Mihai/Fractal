/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mseinic <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/13 18:23:05 by mseinic           #+#    #+#             */
/*   Updated: 2016/04/15 16:42:44 by mseinic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WINDOW_H
# define WINDOW_H

# include <libft.h>
# include <math.h>
# include <mlx.h>
# define WIN_H 800
# define WIN_W 1600
# define RATIO ((double)(WIN_W / WIN_H))
# define MLX (env->mlx)
# define WIN (env->win)
# define IMG (env->img)
# define PIX (env->pixels)
# define BITS_PER_PIX (env->bits_pixel)
# define LINE_SIZE (env->line_size)
# define ENDIAN (env->endian)
# define COLOR (env->color)
# define EXPOSE (env->fnct.expose_hook)
# define KEY_HOOK (env->fnct.key_hook)
# define PAINT (env->fnct.paint)
# define MOUSE (env->fnct.mouse_hook)
# define MOUSE_MOVE (env->fnct.mouse_move)

typedef int			(*t_fnptr)();

typedef struct		s_keys
{
	double			zoom;
	double			zoomx;
	double			zoomy;
	double			move_sides;
	double			move_updown;
	double			x;
	double			y;
	int				holding;
}					t_keys;

typedef struct		s_color
{
	double			r;
	double			g;
	double			b;
}					t_color;

typedef struct		s_env
{
	void			*mlx;
	void			*win;
	void			*menu;

	void			*img;
	char			*pixels;

	int				bits_pixel;
	int				line_size;
	int				endian;
	t_color			color;

	int				fractal_type;

	size_t			maxiter;

	t_keys			key;
	struct
	{
		t_fnptr		paint;
		t_fnptr		key_hook;
		t_fnptr		mouse_hook;
		t_fnptr		mouse_move;
		t_fnptr		expose_hook;
	}				fnct;
}					t_env;

int					def_expose_hook(void *env);
int					def_key_hook(int keycode, void *env);
int					def_mouse_move_hook(int x, int y, void *param);
int					def_mouse_hook(int button, int x, int y, void *param);
int					def_paint(t_env *env);
void				my_pixel_put_to_image(t_env *env, int img_color,
											int x, int y);
void				menu(void);
unsigned int		get_color(int iter, t_env *env);
#endif
