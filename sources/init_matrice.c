/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_matrice.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iporsenn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/11 16:42:19 by iporsenn          #+#    #+#             */
/*   Updated: 2020/03/11 16:42:21 by iporsenn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_scop.h>

static t_mat4	init_translation()
{
	t_mat4 translation;

	translation.x1 = 1;
	translation.y1 = 0;
	translation.z1 = 0;
	translation.w1 = 0;
	translation.x2 = 0;
	translation.y2 = 1;
	translation.z2 = 0;
	translation.w2 = 0;
	translation.x3 = 0;
	translation.y3 = 0;
	translation.z3 = 1;
	translation.w3 = 0;
	translation.x4 = 0;
	translation.y4 = 0;
	translation.z4 = 0;
	translation.w4 = 1;
	return (translation);
}

t_matrice		*init_matrice()
{
	t_matrice	*matrice;

	if (!(matrice = (t_matrice*)malloc(sizeof(t_matrice))))
		return (NULL);
	matrice->translation = init_translation();
	return (matrice);
}
