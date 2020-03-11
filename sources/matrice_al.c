/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrice_al.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iporsenn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/11 13:57:43 by iporsenn          #+#    #+#             */
/*   Updated: 2020/03/11 13:57:45 by iporsenn         ###   ########.fr       */
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

// t_mat4		mat_mat()
// {

// }
