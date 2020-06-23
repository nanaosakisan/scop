/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrice_al.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iporsenn <iporsenn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/11 13:57:43 by iporsenn          #+#    #+#             */
/*   Updated: 2020/04/14 16:59:47 by iporsenn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_scop.h>

t_vec4		mat_vec(t_mat4 mat, t_vec4 vec)
{
	t_vec4	res;

	res = vec;
	res.x = mat.x1 * vec.x + mat.y1 * vec.y + mat.z1 * vec.z + mat.w1 * vec.w;
	res.y = mat.x2 * vec.x + mat.y2 * vec.y + mat.z2 * vec.z + mat.w2 * vec.w;
	res.z = mat.x3 * vec.x + mat.y3 * vec.y + mat.z3 * vec.z + mat.w3 * vec.w;
	res.w = mat.x4 * vec.x + mat.y4 * vec.y + mat.z4 * vec.z + mat.w4 * vec.w;
	return (res);
}

t_mat4		mat_mat(t_mat4 m1, t_mat4 m2)
{
	t_mat4	res;

	res.x1 = m1.x1 * m2.x1 + m1.y1 * m2.x2 + m1.z1 * m2.x3 + m1.w1 * m2.x4;
	res.y1 = m1.x1 * m2.y1 + m1.y1 * m2.y2 + m1.z1 * m2.y3 + m1.w1 * m2.y4;
	res.z1 = m1.x1 * m2.z1 + m1.y1 * m2.z2 + m1.z1 * m2.z3 + m1.w1 * m2.z4;
	res.w1 = m1.x1 * m2.w1 + m1.y1 * m2.w2 + m1.z1 * m2.w3 + m1.w1 * m2.w4;
	res.x2 = m1.x2 * m2.x1 + m1.y2 * m2.x2 + m1.z2 * m2.x3 + m1.w2 * m2.x4;
	res.y2 = m1.x2 * m2.y1 + m1.y2 * m2.y2 + m1.z2 * m2.y3 + m1.w2 * m2.y4;
	res.z2 = m1.x2 * m2.z1 + m1.y2 * m2.z2 + m1.z2 * m2.z3 + m1.w2 * m2.z4;
	res.w2 = m1.x2 * m2.w1 + m1.y2 * m2.w2 + m1.z2 * m2.w3 + m1.w2 * m2.w4;
	res.x3 = m1.x3 * m2.x1 + m1.y3 * m2.x2 + m1.z3 * m2.x3 + m1.w3 * m2.x4;
	res.y3 = m1.x3 * m2.y1 + m1.y3 * m2.y2 + m1.z3 * m2.y3 + m1.w3 * m2.y4;
	res.z3 = m1.x3 * m2.z1 + m1.y3 * m2.z2 + m1.z3 * m2.z3 + m1.w3 * m2.z4;
	res.w3 = m1.x3 * m2.w1 + m1.y3 * m2.w2 + m1.z3 * m2.w3 + m1.w3 * m2.w4;
	res.x4 = m1.x4 * m2.x1 + m1.y4 * m2.x2 + m1.z4 * m2.x3 + m1.w4 * m2.x4;
	res.y4 = m1.x4 * m2.y1 + m1.y4 * m2.y2 + m1.z4 * m2.y3 + m1.w4 * m2.y4;
	res.z4 = m1.x4 * m2.z1 + m1.y4 * m2.z2 + m1.z4 * m2.z3 + m1.w4 * m2.z4;
	res.w4 = m1.x4 * m2.w1 + m1.y4 * m2.w2 + m1.z4 * m2.w3 + m1.w4 * m2.w4;
	return (res);
}
