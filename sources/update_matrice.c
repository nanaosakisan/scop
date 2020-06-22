/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_matrice.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iporsenn <iporsenn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/11 16:42:19 by iporsenn          #+#    #+#             */
/*   Updated: 2020/05/09 15:45:06 by iporsenn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_scop.h>

t_mat4	init_identity(t_vec4 vec)
{
	t_mat4 identity;

	identity.x1 = vec.x;
	identity.y1 = 0;
	identity.z1 = 0;
	identity.w1 = 0;
	identity.x2 = 0;
	identity.y2 = vec.y;
	identity.z2 = 0;
	identity.w2 = 0;
	identity.x3 = 0;
	identity.y3 = 0;
	identity.z3 = vec.z;
	identity.w3 = 0;
	identity.x4 = 0;
	identity.y4 = 0;
	identity.z4 = 0;
	identity.w4 = vec.w;
	return (identity);
}

t_mat4	init_translation_inv(t_vec3 trans)
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

t_mat4	init_rot_x(float angle_x)
{
	t_mat4 rot_x;

	rot_x.x1 = 1;
	rot_x.y1 = 0;
	rot_x.z1 = 0;
	rot_x.w1 = 0;
	rot_x.x2 = 0;
	rot_x.y2 = cos(angle_x);
	rot_x.z2 = -sin(angle_x);
	rot_x.w2 = 0;
	rot_x.x3 = 0;
	rot_x.y3 = sin(angle_x);
	rot_x.z3 = cos(angle_x);
	rot_x.w3 = 0;
	rot_x.x4 = 0;
	rot_x.y4 = 0;
	rot_x.z4 = 0;
	rot_x.w4 = 1;
	return (rot_x);
}

t_mat4	init_rot_y(float angle_y)
{
	t_mat4 rot_y;

	rot_y.x1 = cos(angle_y);
	rot_y.y1 = 0;
	rot_y.z1 = sin(angle_y);
	rot_y.w1 = 0;
	rot_y.x2 = 0;
	rot_y.y2 = 1;
	rot_y.z2 = 0;
	rot_y.w2 = 0;
	rot_y.x3 = -sin(angle_y);
	rot_y.y3 = 0;
	rot_y.z3 = cos(angle_y);
	rot_y.w3 = 0;
	rot_y.x4 = 0;
	rot_y.y4 = 0;
	rot_y.z4 = 0;
	rot_y.w4 = 1;
	return (rot_y);
}
