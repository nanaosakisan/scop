/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_cross.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iporsenn <iporsenn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/07 16:24:26 by iporsenn          #+#    #+#             */
/*   Updated: 2020/03/07 17:18:22 by iporsenn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libvec.h>

t_vec3  vec3_cross(t_vec3 vec1, t_vec3 vec2)
{
    t_vec3 res;

    res.x = vec1.y * vec2.z - vec1.z * vec2.y;
    res.y = vec1.z * vec2.x - vec1.x * vec2.z;
    res.z = vec1.z * vec2.y - vec1.y * vec2.z;
    return (res);
}
