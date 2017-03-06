/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_frac.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mseinic <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/15 10:21:34 by mseinic           #+#    #+#             */
/*   Updated: 2016/04/15 13:47:23 by mseinic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fractol.h>

int		list_fract(int ac, char **av)
{
	int		fract;

	ac = 1;
	fract = 0;
	if (ft_strequ(ft_str_lower(av[1]), "julia") || ft_strequ(av[1], "2"))
		fract = 2;
	else if (ft_strequ(ft_str_lower(av[1]), "mandelbrot")
			|| ft_strequ(av[1], "1"))
		fract = 3;
	else if (ft_strequ(ft_str_lower(av[1]), "tree") || ft_strequ(av[1], "3"))
		fract = 4;
	else if (ft_strequ(ft_str_lower(av[1]), "juliabis")
			|| ft_strequ(av[1], "4"))
		fract = 5;
	else if (ft_strequ(ft_str_lower(av[1]), "bacteria")
			|| ft_strequ(av[1], "5"))
		fract = 6;
	else if (ft_strequ(ft_str_lower(av[1]), "fuzzy") || ft_strequ(av[1], "6"))
		fract = 7;
	else if (ft_strequ(ft_str_lower(av[1]), "burningship")
			|| ft_strequ(av[1], "7"))
		fract = 8;
	else if (ft_strequ(ft_str_lower(av[1]), "lapin") || ft_strequ(av[1], "8"))
		fract = 9;
	return (fract);
}
