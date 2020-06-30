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

static t_mat4	init_proj(float ar, float angle, float z_near, float z_far)
{
	t_mat4	proj;
	float	denom;

	denom = z_near - z_far;
	proj.x1 = 1 / (ar * tan(angle / 2));
	proj.y1 = 0;
	proj.z1 = 0;
	proj.w1 = 0;
	proj.x2 = 0;
	proj.y2 = 1 / tan(angle / 2);
	proj.z2 = 0;
	proj.w2 = 0;
	proj.x3 = 0;
	proj.y3 = 0;
	proj.z3 = (-z_near - z_far) / denom;
	proj.w3 = (2 * z_far * z_near) / denom;
	proj.x4 = 0;
	proj.y4 = 0;
	proj.z4 = 1;
	proj.w4 = 0;
	return (proj);
}

static	t_mat4	init_trans_view(t_vec3 vec)
{
	t_mat4 trans;

	trans.x1 = 1;
	trans.y1 = 0;
	trans.z1 = 0;
	trans.w1 = -vec.x;
	trans.x2 = 0;
	trans.y2 = 1;
	trans.z2 = 0;
	trans.w2 = -vec.y;
	trans.x3 = 0;
	trans.y3 = 0;
	trans.z3 = 1;
	trans.w3 = -vec.z;
	trans.x4 = 0;
	trans.y4 = 0;
	trans.z4 = 0;
	trans.w4 = 1;
	return (trans);
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

t_mat4	init_view(t_vec3 pos, t_vec3 target, t_vec3 up)
{
	t_vec3	dir;
	t_vec3	right;
	t_vec3	new_up;
	t_mat4	view;

	dir = vec3_normalize(vec3_sub(pos, target));
	right = vec3_normalize(vec3_cross(up, dir));
	new_up = vec3_cross(dir, right);
	view = mat_mat(init_rot(right, new_up, dir), init_trans_view(pos));
	return (view);
}

t_mat4	init_identity(t_vec4 vec)
{
	t_mat4	mat;

	mat.x1 = vec.x;
	mat.y1 = 0;
	mat.z1 = 0;
	mat.w1 = 0;
	mat.x2 = 0;
	mat.y2 = vec.y;
	mat.z2 = 0;
	mat.w2 = 0;
	mat.x3 = 0;
	mat.y3 = 0;
	mat.z3 = vec.z;
	mat.w3 = 0;
	mat.x4 = 0;
	mat.y4 = 0;
	mat.z4 = 0;
	mat.w4 = vec.w;
	return (mat);
}

t_mvp		*init_matrice(t_env env)
{
	t_mvp	*mvp;
	int		width;
	int		height;

	mvp = (t_mvp *)malloc(sizeof(t_mvp));
	mvp->model = init_identity(vec4_new(1, 1, 1, 1));
	// mvp->model = mat_mat_rev(mvp->model, rot_x(-55.0 * M_PI / 180));
	// mvp->view = init_identity(vec4_new(1, 1, 1, 1));
	// mvp->view = mat_mat_rev(mvp->view, init_trans_view(vec3_new(0, 0, -3)));
	mvp->view = init_view(vec3_new(0, 0, 3), vec3_add(vec3_new(0, 0, 3),\
		vec3_new(0, 0, -1)), vec3_new(0, 1, 0));
	glfwGetWindowSize(env.window, &width, &height);
	mvp->projection = init_proj(width / height, M_PI / 2, -1, 1000);
	return (mvp);
}