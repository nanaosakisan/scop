/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mat.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iporsenn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/23 11:14:07 by iporsenn          #+#    #+#             */
/*   Updated: 2020/06/23 11:14:11 by iporsenn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAT_H
# define MAT_H

# ifdef __APPLE__
#  define GL_SILENCE_DEPRECATION
#  include <OpenGL/gl3.h>
#  define GLFW_INCLUDE_NONE
# else
#  include <glad/glad.h>
# endif
# include <GLFW/glfw3.h> 

# include <libvec.h>

typedef	struct	s_mat4
{
	GLfloat	x1;
	GLfloat	y1;
	GLfloat	z1;
	GLfloat	w1;
	GLfloat	x2;
	GLfloat	y2;
	GLfloat	z2;
	GLfloat	w2;
	GLfloat	x3;
	GLfloat	y3;
	GLfloat	z3;
	GLfloat	w3;
	GLfloat	x4;
	GLfloat	y4;
	GLfloat	z4;
	GLfloat	w4;
}				t_mat4;

t_vec4			mat_vec(t_mat4 mat, t_vec4 vec);
t_mat4			mat_mat(t_mat4 m1, t_mat4 m2);

t_mat4			init_identity(t_vec4 vec);
t_mat4			init_view(t_vec3 pos, t_vec3 target, t_vec3 up);
t_mat4			init_rot_x(float angle_x);
t_mat4			init_rot_y(float angle_y);
t_mat4			init_translation_inv(t_vec3 trans);

#endif

