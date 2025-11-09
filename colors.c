/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfirmino <vfirmino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/08 07:37:35 by vfirmino          #+#    #+#             */
/*   Updated: 2025/11/08 23:31:04 by vfirmino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

static int	get_palette_0(int index)
{
	if (index == 0)
		return (0x000000);
	if (index == 1)
		return (0x000000);
	if (index == 2)
		return (0x000000);
	if (index == 3)
		return (0x002040);
	if (index == 4)
		return (0xFFFCFC);
	if (index == 5)
		return (0x000000);
	return (0x000000);
}

static int	get_palette_1(int index)
{
	if (index == 0)
		return (0x000000);
	if (index == 1)
		return (0xFF0000);
	if (index == 2)
		return (0xFFA500);
	if (index == 3)
		return (0xFFFF00);
	if (index == 4)
		return (0x00FF00);
	if (index == 5)
		return (0x0000FF);
	return (0x000000);
}

static int	get_palette_2(int index)
{
	if (index == 0)
		return (0x000000);
	if (index == 1)
		return (0x001F3F);
	if (index == 2)
		return (0x0074D9);
	if (index == 3)
		return (0x7FDBFF);
	if (index == 4)
		return (0x39CCCC);
	if (index == 5)
		return (0x3D9970);
	return (0x000000);
}

static int	get_palette_3(int index)
{
	int	color;

	if (index == 0)
		return (0x000000);
	if (index == 1)
		return (0xFF4136);
	if (index == 2)
		return (0xFFDC00);
	if (index == 3)
		return (0x2ECC40);
	if (index == 4)
		return (0x0074D9);
	if (index == 5)
	{
		color = 0x00B10DC9;
		return (color);
	}
	return (0x000000);
}

int	get_palette_color(int palette_id, int index)
{
	if (palette_id == 0)
		return (get_palette_0(index));
	if (palette_id == 1)
		return (get_palette_1(index));
	if (palette_id == 2)
		return (get_palette_2(index));
	if (palette_id == 3)
		return (get_palette_3(index));
	return (get_palette_0(index));
}
