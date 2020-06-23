/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iporsenn <iporsenn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/16 16:40:59 by iporsenn          #+#    #+#             */
/*   Updated: 2020/04/16 16:44:24 by iporsenn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_scop.h>

void	print_mat(t_mat4 mat)
{
	printf("mat.x1: %f, mat.y1: %f, mat.z1: %f, mat.w1: %f\n", mat.x1, mat.y1,\
		mat.z1, mat.w1);
	printf("mat.x2: %f, mat.y2: %f, mat.z2: %f, mat.w2: %f\n", mat.x2, mat.y2,\
		mat.z2, mat.w2);
	printf("mat.x3: %f, mat.y3: %f, mat.z3: %f, mat.w3: %f\n", mat.x3, mat.y3,\
		mat.z3, mat.w3);
	printf("mat.x4: %f, mat.y4: %f, mat.z4: %f, mat.w4: %f\n", mat.x4, mat.y4,\
		mat.z4, mat.w4);
}

void	print_vec3(t_vec3 vec)
{
	printf("vec.x: %f, vec.y: %f, vec.z: %f\n", vec.x, vec.y, vec.z);
}
