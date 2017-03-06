/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_put_pixel.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mseinic <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/16 15:38:35 by mseinic           #+#    #+#             */
/*   Updated: 2016/04/12 18:42:55 by mseinic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <window.h>

void	my_pixel_put_to_image(t_env *env, int color, int x, int y)
{
	unsigned char r;
	unsigned char g;
	unsigned char b;

	r = (color & 0xFF0000) >> 16;
	g = (color & 0xFF00) >> 8;
	b = (color & 0xFF);
	PIX[y * LINE_SIZE + x * BITS_PER_PIX / 8] = b;
	PIX[y * LINE_SIZE + x * BITS_PER_PIX / 8 + 1] = g;
	PIX[y * LINE_SIZE + x * BITS_PER_PIX / 8 + 2] = r;
}
