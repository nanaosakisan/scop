/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_dot_gem.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iporsenn <iporsenn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/07 16:13:32 by iporsenn          #+#    #+#             */
/*   Updated: 2020/04/16 15:22:59 by iporsenn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libvec.h>

inline float	vec4_dot_gem(t_vec4 vec1, t_vec4 vec2, float angle)
{
    return (vec4_norm(vec1) * vec4_norm(vec2) * cos(angle));
}

inline float	vec3_dot_gem(t_vec3 vec1, t_vec3 vec2, float angle)
{
    return (vec3_norm(vec1) * vec3_norm(vec2) * cos(angle));
}

inline float	vec2_dot_gem(t_vec2 vec1, t_vec2 vec2, float angle)
{
    return (vec2_norm(vec1) * vec2_norm(vec2) * cos(angle));
}
