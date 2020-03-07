/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_dot_al.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iporsenn <iporsenn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/07 16:07:51 by iporsenn          #+#    #+#             */
/*   Updated: 2020/03/07 16:13:09 by iporsenn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libvec.h>

inline float   vec4_dot_al(t_vec4 vec1, t_vec4 vec2)
{
    return (vec1.x * vec2.x + vec1.y * vec2.y + vec1.z * vec2.z);
}

inline float   vec3_dot_al(t_vec3 vec1, t_vec3 vec2)
{
    return (vec1.x * vec2.x + vec1.y * vec2.y + vec1.z * vec2.z);
}

inline float   vec2_dot_al(t_vec2 vec1, t_vec2 vec2)
{
    return (vec1.u * vec2.u + vec1.v * vec2.v);
}
