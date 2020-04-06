/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_matrice.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iporsenn <iporsenn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/11 16:42:19 by iporsenn          #+#    #+#             */
/*   Updated: 2020/03/18 12:28:45 by iporsenn         ###   ########.fr       */
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

static t_mat4	init_identity()
{
	t_mat4 identity;

	identity.x1 = 1;
	identity.y1 = 0;
	identity.z1 = 0;
	identity.w1 = 0;
	identity.x2 = 0;
	identity.y2 = 1;
	identity.z2 = 0;
	identity.w2 = 0;
	identity.x3 = 0;
	identity.y3 = 0;
	identity.z3 = 1;
	identity.w3 = 0;
	identity.x4 = 0;
	identity.y4 = 0;
	identity.z4 = 0;
	identity.w4 = 1;
	return (identity);
}

static t_mat4	init_scale()
{
	t_mat4	scale;

	scale.x1 = 1;
	scale.y1 = 0;
	scale.z1 = 0;
	scale.w1 = 0;
	scale.x2 = 0;
	scale.y2 = 1;
	scale.z2 = 0;
	scale.w2 = 0;
	scale.x3 = 0;
	scale.y3 = 0;
	scale.z3 = 1;
	scale.w3 = 0;
	scale.x4 = 0;
	scale.y4 = 0;
	scale.z4 = 0;
	scale.w4 = 1;
	return (scale);
}

t_matrice		*init_matrice()
{
	t_matrice	*matrice;

	if (!(matrice = (t_matrice*)malloc(sizeof(t_matrice))))
		return (NULL);
	matrice->translation = init_translation();
	matrice->identity = init_identity();
	matrice->scale = init_scale();
	return (matrice);
}
