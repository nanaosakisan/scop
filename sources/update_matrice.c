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

t_mat4		rot_x(float angle)
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

t_mat4		rot_y(float angle)
{
	t_mat4	rot;

	rot.x1 = cos(angle);
	rot.y1 = 0;
	rot.z1 = -sin(angle);
	rot.w1 = 0;
	rot.x2 = 0;
	rot.y2 = 1;
	rot.z2 = 0;
	rot.w2 = 0;
	rot.x3 = sin(angle);
	rot.y3 = 0;
	rot.z3 = cos(angle);
	rot.w3 = 0;
	rot.x4 = 0;
	rot.y4 = 0;
	rot.z4 = 0;
	rot.w4 = 1;
	return (rot);
}

t_mat4		rot_z(float angle)
{
	t_mat4	rot;

	rot.x1 = cos(angle);
	rot.y1 = sin(angle);
	rot.z1 = 0;
	rot.w1 = 0;
	rot.x2 = -sin(angle);
	rot.y2 = cos(angle);
	rot.z2 = 0;
	rot.w2 = 0;
	rot.x3 = 0;
	rot.y3 = 0;
	rot.z3 = 1;
	rot.w3 = 0;
	rot.x4 = 0;
	rot.y4 = 0;
	rot.z4 = 0;
	rot.w4 = 1;
	return (rot);
}