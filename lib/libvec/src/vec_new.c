/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_new.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iporsenn <iporsenn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/07 15:18:40 by iporsenn          #+#    #+#             */
/*   Updated: 2020/03/07 15:41:08 by iporsenn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libvec.h>

t_vec4  vec4_new(float x, float y, float z, float w)
{
    t_vec4 vec;

    vec.x = x;
    vec.y = y;
    vec.z = z;
    vec.w = w;
    return(vec);
}

t_vec3  vec3_new(float x, float y, float z)
{
    t_vec3 vec;

    vec.x = x;
    vec.y = y;
    vec.z = z;
    return(vec);
}

t_vec2  vec2_new(float u, float v)
{
    t_vec2 vec;

    vec.u = u;
    vec.v = v;
    return(vec);
}
