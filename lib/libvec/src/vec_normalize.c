/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_normalize.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iporsenn <iporsenn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/07 16:14:43 by iporsenn          #+#    #+#             */
/*   Updated: 2020/04/16 15:23:14 by iporsenn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libvec.h>

inline float   vec4_norm(t_vec4 vec)
{
	return (sqrt(vec.x * vec.x + vec.y * vec.y + vec.z * vec.z));
}

inline float   vec3_norm(t_vec3 vec)
{
	return (sqrt(vec.x * vec.x + vec.y * vec.y + vec.z * vec.z));
}

inline float   vec2_norm(t_vec2 vec)
{
    return (sqrt(vec.u * vec.u + vec.v * vec.v));
}

t_vec4  vec4_normalize(t_vec4 vec)
{
    const float   norm = 1.0 / vec4_norm(vec);

    return (vec4_scale(vec,  norm));
}

t_vec3  vec3_normalize(t_vec3 vec)
{
    const float   norm = 1.0 / vec3_norm(vec);

    return (vec3_scale(vec,  norm));
}

t_vec2  vec2_normalize(t_vec2 vec)
{
    const float   norm = 1.0 / vec2_norm(vec);

    return (vec2_scale(vec,  norm));
}
