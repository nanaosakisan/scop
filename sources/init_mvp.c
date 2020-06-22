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

static t_mat4	init_trans_view(t_vec3 trans)
{
	t_mat4 translation;

	translation.x1 = 1;
	translation.y1 = 0;
	translation.z1 = 0;
	translation.w1 = -trans.x;
	translation.x2 = 0;
	translation.y2 = 1;
	translation.z2 = 0;
	translation.w2 = -trans.y;
	translation.x3 = 0;
	translation.y3 = 0;
	translation.z3 = 1;
	translation.w3 = -trans.z;
	translation.x4 = 0;
	translation.y4 = 0;
	translation.z4 = 0;
	translation.w4 = 1;
	return (translation);
}

static t_mat4	init_rot(t_vec3 right, t_vec3 up, t_vec3 dir)
{
	t_mat4	rot;

	rot.x1 = right.x;
	rot.y1 = right.y;
	rot.z1 = right.z;
	rot.w1 = 0;
	rot.x2 = up.x;
	rot.y2 = up.y;
	rot.z2 = up.z;
	rot.w2 = 0;
	rot.x3 = dir.x;
	rot.y3 = dir.y;
	rot.z3 = dir.z;
	rot.w3 = 0;
	rot.x4 = 0;
	rot.y4 = 0;
	rot.z4 = 0;
	rot.w4 = 1;
	return (rot);
}

t_mat4			init_view(t_vec3 pos, t_vec3 target, t_vec3 up)
{
	t_vec3	dir;
	t_vec3	right;
	t_mat4	trans;
	t_mat4	rot;
	t_mat4	view;

	dir = vec3_normalize(vec3_sub(pos, target));
	right = vec3_normalize(vec3_cross(up, dir));
	up = vec3_cross(dir, right);
	trans = init_trans_view(pos);
	rot = init_rot(right, up, dir);
	view = mat_mat(rot, trans);
	return (view);
}

static t_mat4	init_projection(float angle, float z_near, float z_far)
{
	t_mat4	projection;
	float	ar;
	float	denom;

	ar = HEIGHT / WIDTH;
	denom = z_near - z_far;
	projection.x1 = 1 / (ar * tan(angle / 2));
	projection.y1 = 0;
	projection.z1 = 0;
	projection.w1 = 0;
	projection.x2 = 0;
	projection.y2 = 1 / tan(angle / 2);
	projection.z2 = 0;
	projection.w2 = 0;
	projection.x3 = 0;
	projection.y3 = 0;
	projection.z3 = (-z_near - z_far) / denom;
	projection.w3 = (2 * z_far * z_near) / denom;
	projection.x4 = 0;
	projection.y4 = 0;
	projection.z4 = 1;
	projection.w4 = 0;
	return (projection);
}

t_mvp			*init_matrice(void)
{
	t_mvp	*matrice;

	if (!(matrice = (t_mvp*)malloc(sizeof(t_mvp))))
		return (NULL);
	matrice->model = init_identity(vec4_new(1, 1, 1, 1));
	matrice->view = init_view(vec3_new(0, 0, 3), vec3_add(vec3_new(0, 0, 3),\
		vec3_new(0, 0, -1)), vec3_new(0, 1, 0));
	matrice->projection = init_projection(M_PI / 2, -1, 1000);
	return (matrice);
}
