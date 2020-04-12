/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_matrice.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iporsenn <iporsenn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/11 16:42:19 by iporsenn          #+#    #+#             */
/*   Updated: 2020/04/12 17:51:33 by iporsenn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_scop.h>

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

static	t_mat4	init_rot_x(t_env env)
{
	t_mat4 rot_x;

	rot_x.x1 = 1;
	rot_x.y1 = 0;
	rot_x.z1 = 0;
	rot_x.w1 = 0;
	rot_x.x2 = 0;
	rot_x.y2 = cos(env.angle_x);
	rot_x.z2 = -sin(env.angle_x);
	rot_x.w2 = 0;
	rot_x.x3 = 0;
	rot_x.y3 = sin(env.angle_x);
	rot_x.z3 = cos(env.angle_x);
	rot_x.w3 = 0;
	rot_x.x4 = 0;
	rot_x.y4 = 0;
	rot_x.z4 = 0;
	rot_x.w4 = 1;
	return (rot_x);
}

static	t_mat4	init_rot_y(t_env env)
{
	t_mat4 rot_y;

	rot_y.x1 = cos(env.angle_y);
	rot_y.y1 = 0;
	rot_y.z1 = sin(env.angle_y);
	rot_y.w1 = 0;
	rot_y.x2 = 0;
	rot_y.y2 = 1;
	rot_y.z2 = 0;
	rot_y.w2 = 0;
	rot_y.x3 = -sin(env.angle_y);
	rot_y.y3 = 0;
	rot_y.z3 = cos(env.angle_y);
	rot_y.w3 = 0;
	rot_y.x4 = 0;
	rot_y.y4 = 0;
	rot_y.z4 = 0;
	rot_y.w4 = 1;
	return (rot_y);
}

static	t_mat4	init_rot_z(t_env env)
{
	t_mat4 rot_z;

	rot_z.x1 = cos(env.angle_z);
	rot_z.y1 = -sin(env.angle_z);
	rot_z.z1 = 0;
	rot_z.w1 = 0;
	rot_z.x2 = sin(env.angle_z);
	rot_z.y2 = cos(env.angle_z);
	rot_z.z2 = 0;
	rot_z.w2 = 0;
	rot_z.x3 = 0;
	rot_z.y3 = 0;
	rot_z.z3 = 1;
	rot_z.w3 = 0;
	rot_z.x4 = 0;
	rot_z.y4 = 0;
	rot_z.z4 = 0;
	rot_z.w4 = 1;
	return (rot_z);
}

static t_mat4	init_view()
{
	t_mat4	view;

	view.x1 = 4;
	view.y1 = 3;
	view.z1 = 3;
	view.w1 = 0;
	view.x2 = 0;
	view.y2 = 0;
	view.z2 = 0;
	view.w2 = 0;
	view.x3 = 0;
	view.y3 = 1;
	view.z3 = 0;
	view.w3 = 0;
	view.x4 = 0;
	view.y4 = 0;
	view.z4 = 0;
	view.w4 = 1;
	return (view);
}

static t_mat4	init_projection()
{
	t_mat4	projection;
	float	ar;
	float	angle;
	float	z_near;
	float	z_far;
	float	denom;

	ar = HEIGHT / WIDTH;
	angle = 45;
	z_near = -1;
	z_far = 1000;
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
	projection.z3 = (- z_near - z_far) / denom;
	projection.w3 = (2 * z_far * z_near) / denom;
	projection.x4 = 0;
	projection.y4 = 0;
	projection.z4 = 1;
	projection.w4 = 0;
	return (projection);
}

t_matrice		*init_matrice(t_env env)
{
	t_matrice	*matrice;

	if (!(matrice = (t_matrice*)malloc(sizeof(t_matrice))))
		return (NULL);
	matrice->identity = init_identity();
	matrice->scale = init_scale();
	matrice->translation = init_translation();
	matrice->rot_x = init_rot_x(env);
	matrice->rot_y = init_rot_y(env);
	matrice->rot_z = init_rot_z(env);
	matrice->model = init_identity();
	matrice->view = init_view();
	matrice->projection = init_projection();
	return (matrice);
}

void			init_mvp(t_env env, t_matrice matrice)
{
	glUniformMatrix4fv(env.model_id, 1, GL_FALSE, (const GLfloat*)&matrice.model);
	glUniformMatrix4fv(env.view_id, 1, GL_FALSE, (const GLfloat*)&matrice.view);
	glUniformMatrix4fv(env.projection_id, 1, GL_FALSE, (const GLfloat*)&matrice.projection);
	get_error();
}