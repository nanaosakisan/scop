/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_sub.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iporsenn <iporsenn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/07 15:49:20 by iporsenn          #+#    #+#             */
/*   Updated: 2020/03/07 15:49:37 by iporsenn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libvec.h>

t_vec4  vec4_add(t_vec4 vec1, t_vec4 vec2)
{
    t_vec4 res;

    res.x = vec1.x - vec2.x;
    res.y = vec1.y - vec2.y;
    res.z = vec1.z - vec2.z;
    res.w = vec1.w - vec2.w;
    return (res);
}

t_vec3  vec3_add(t_vec3 vec1, t_vec3 vec2)
{
    t_vec3 res;

    res.x = vec1.x - vec2.x;
    res.y = vec1.y - vec2.y;
    res.z = vec1.z - vec2.z;
    return (res);
}

t_vec2  vec2_add(t_vec2 vec1, t_vec2 vec2)
{
    t_vec2 res;

    res.u = vec1.u - vec2.u;
    res.v = vec1.v - vec2.v;
    return (res);
}