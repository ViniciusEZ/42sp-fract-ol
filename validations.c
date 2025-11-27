/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validations.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfirmino <vfirmino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 13:37:25 by vfirmino          #+#    #+#             */
/*   Updated: 2025/11/26 13:39:46 by vfirmino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

int	is_valid_float(const char *s)
{
	int	has_digit;
	int	has_dot;

	has_digit = 0;
	has_dot = 0;
	while (*s == ' ')
		s++;
	if (*s == '+' || *s == '-')
		s++;
	if (*s == '\0')
		return (0);
	while (*s)
	{
		if (*s >= '0' && *s <= '9')
			has_digit = 1;
		else if (*s == '.' && !has_dot)
			has_dot = 1;
		else
			return (0);
		s++;
	}
	return (has_digit);
}

int	is_valid_julia_value(double x)
{
	return (x >= -2.0 && x <= 2.0);
}
