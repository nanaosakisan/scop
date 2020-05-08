/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libvec.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iporsenn <iporsenn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/07 15:07:01 by iporsenn          #+#    #+#             */
/*   Updated: 2020/04/16 17:12:51 by iporsenn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBVEC_H
# define LIBVEC_H

# include <math.h>
# include <stdio.h>

typedef struct	s_vec4
{
	float	x;
	float	y;
	float	z;
	float	w;
}				t_vec4;

typedef struct	s_vec3
{
	float	x;
	float	y;
	float	z;
}				t_vec3;

typedef struct	s_vec2
{
	float	u;
	float	v;
}				t_vec2;

t_vec4      vec4_new(float x, float y, float z, float w);
t_vec4      vec4_add(t_vec4 vec1, t_vec4 vec2);
t_vec4      vec4_sub(t_vec4 vec1, t_vec4 vec2);
float       vec4_dot_al(t_vec4 vec1, t_vec4 vec2);
float       vec4_dot_gem(t_vec4 vec1, t_vec4 vec2, float angle);
t_vec4      vec4_scale(t_vec4 vec, float scale);
float       vec4_norm(t_vec4);
t_vec4		vec4_normalize(t_vec4);

t_vec3      vec3_new(float x, float y, float z);
t_vec3      vec3_add(t_vec3 vec1, t_vec3 vec2);
t_vec3      vec3_sub(t_vec3 vec1, t_vec3 vec2);
float       vec3_dot_al(t_vec3 vec1, t_vec3 vec2);
float       vec3_dot_gem(t_vec3 vec1, t_vec3 vec2, float angle);
t_vec3      vec3_cross(t_vec3 vec1, t_vec3 vec2);
t_vec3      vec3_scale(t_vec3 vec, float scale);
float       vec3_norm(t_vec3);
t_vec3		vec3_normalize(t_vec3);

t_vec2      vec2_new(float u, float v);
t_vec2      vec2_add(t_vec2 vec1, t_vec2 vec2);
t_vec2      vec2_sub(t_vec2 vec1, t_vec2 vec2);
float       vec2_dot_al(t_vec2 vec1, t_vec2 vec2);
float       vec2_dot_gem(t_vec2 vec1, t_vec2 vec2, float angle);
t_vec2      vec2_scale(t_vec2 vec, float scale);
float	    vec2_norm(t_vec2);
t_vec2		vec2_normalize(t_vec2);

#endif
