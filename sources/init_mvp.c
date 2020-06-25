/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mvp.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iporsenn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/22 16:22:39 by iporsenn          #+#    #+#             */
/*   Updated: 2020/06/22 16:22:42 by iporsenn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_scop.h>

static t_mat4	init_identity(t_vec4 vec)
{
	t_mat4	mat;

	mat.x1 = 1;
	mat.y1 = 0;
	mat.z1 = 0;
	mat.w1 = 0;
	mat.x2 = 0;
	mat.y2 = 1;
	mat.z2 = 0;
	mat.w2 = 0;
	mat.x3 = 0;
	mat.y3 = 0;
	mat.z3 = 1;
	mat.w3 = 0;
	mat.x4 = 0;
	mat.y4 = 0;
	mat.z4 = 0;
	mat.w4 = 0;
	return (mat);
}

t_mvp		*init_mvp(t_env env)
{
	t_mvp	*mvp;

	mvp = (t_mvp *)malloc(sizof(t_mvp));
	mvp->model = ;
	return (mvp);
}