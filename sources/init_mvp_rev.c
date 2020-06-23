/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mvp_rev.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iporsenn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/23 14:55:34 by iporsenn          #+#    #+#             */
/*   Updated: 2020/06/23 14:55:50 by iporsenn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_scop.h>

static t_mat4	init_trans_view(t_vec3 trans)
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
	translation.x4 = trans.x;
	translation.y4 = trans.y;
	translation.z4 = trans.z;
	translation.w4 = 1;
	return (translation);
}

static t_mat4	init_rot(t_vec3 right, t_vec3 up, t_vec3 dir)
{
	t_mat4	rot;

	rot.x1 = right.x;
	rot.y1 = up.x;
	rot.z1 = dir.x;
	rot.w1 = 0;
	rot.x2 = right.y;
	rot.y2 = up.y;
	rot.z2 = dir.y;
	rot.w2 = 0;
	rot.x3 = right.z;
	rot.y3 = up.z;
	rot.z3 = dir.z;
	rot.w3 = 0;
	rot.x4 = 0;
	rot.y4 = 0;
	rot.z4 = 0;
	rot.w4 = 1.0;
	return (rot);
}

static t_mat4	rot_x(float angle)
{
	t_mat4	rot;

	rot.x1 = 1;
	rot.y1 = 0;
	rot.z1 = 0;
	rot.w1 = 0;
	rot.x2 = 0;
	rot.y2 = cos(angle);
	rot.z2 = sin(angle);
	rot.w2 = 0;
	rot.x3 = 0;
	rot.y3 = -sin(angle);
	rot.z3 = cos(angle);
	rot.w3 = 0;
	rot.x4 = 0;
	rot.y4 = 0;
	rot.z4 = 0;
	rot.w4 = 1;
	return (rot);
}

t_mat4			init_view_rev(t_vec3 pos, t_vec3 target, t_vec3 up)
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
	rot = rot_x(M_PI / 9);
	view = mat_mat_rev(rot, trans);
	return (view);
}

static t_mat4	init_projection(float ar, float angle, float z_near, float z_far)
{
	t_mat4	projection;
	float	denom;
	const	GLfloat	yscale = 1 / (angle / 2);
	const	GLfloat xscale = yscale / ar;
	
	printf("ar: %f\n", ar);
	denom = z_far - z_near;
	projection.x1 = xscale;
	projection.y1 = 0;
	projection.z1 = 0;
	projection.w1 = 0;
	projection.x2 = 0;
	projection.y2 = yscale;
	projection.z2 = 0;
	projection.w2 = 0;
	projection.x3 = 0;
	projection.y3 = 0;
	projection.z3 = -((z_far + z_near) / denom);
	projection.w3 = -1;
	projection.x4 = 0;
	projection.y4 = 0;
	projection.z4 = -((2 * z_far * z_near) / denom) - 2;
	projection.w4 = 0;
	return (projection);
}

t_mvp			*init_matrice_rev(t_env env)
{
	t_mvp	*matrice;
	float	width;
	float	height;

	if (!(matrice = (t_mvp*)malloc(sizeof(t_mvp))))
		return (NULL);
	matrice->model = init_identity(vec4_new(1, 1, 1, 1));
	matrice->view = init_view(vec3_new(0, 0, 3), vec3_add(vec3_new(0, 0, 3),\
		vec3_new(0, 0, -1)), vec3_new(0, 1, 0));
	glfwGetWindowSize(env.window, &width, &height);
	matrice->projection = init_projection(width / height, M_PI / 2, -1, 1000);
	printf("projection:\n");
	print_mat(matrice->projection);
	return (matrice);
}

