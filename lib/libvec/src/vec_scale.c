/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_scale.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iporsenn <iporsenn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/07 17:19:41 by iporsenn          #+#    #+#             */
/*   Updated: 2020/04/16 17:14:09 by iporsenn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libvec.h>

t_vec4	vec4_scale(t_vec4 vec, float scale)
{
	t_vec4	res;

	res.x = vec.x * scale;
	res.y = vec.y * scale;
	res.z = vec.z * scale;
	res.w = vec.w;
	return (res);
}

t_vec3	vec3_scale(t_vec3 vec, float scale)
{
	t_vec3	res;

	res.x = vec.x * scale;
	res.y = vec.y * scale;
	res.z = vec.z * scale;
	return (res);
}

t_vec2	vec2_scale(t_vec2 vec, float scale)
{
	t_vec2	res;

	res.u = vec.u * scale;
	res.v = vec.v * scale;
	return (res);
}
