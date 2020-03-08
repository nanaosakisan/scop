/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_conv.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iporsenn <iporsenn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/08 15:34:56 by iporsenn          #+#    #+#             */
/*   Updated: 2020/03/08 15:38:26 by iporsenn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libvec.h>

t_vec3  vec4_to_vec3(t_vec4 vec)
{
    t_vec3 res;

    res.x = vec.x;
    res.y = vec.y;
    res.z = vec.z;
    return (res);
}

t_vec2  vec4_to_vec2(t_vec4 vec)
{
    t_vec2 res;

    res.u = vec.x;
    res.v = vec.y;
    return (res);
}

t_vec2  vec3_to_vec2(t_vec3 vec)
{
    t_vec2 res;

    res.u = vec.x;
    res.v = vec.y;
    return (res);
}