/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iporsenn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/03 15:43:29 by iporsenn          #+#    #+#             */
/*   Updated: 2020/03/03 15:43:31 by iporsenn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

//

double	ft_atof(const char *str)
{
	double	res;
	float	dec;
	char	**split;

	res = 0;
	dec = 0;
	split = ft_strsplit(str, '.');
	if (split[0])
		res = ft_atoi(split[0]);
	if (split[1])
	{
		dec = (float)ft_atoi(split[1]);
		while ((int)dec > 0)
			dec = dec / 10;
	}
	res = res + dec;
	return (res);
}
