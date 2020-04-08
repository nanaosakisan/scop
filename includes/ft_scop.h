/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_scop.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iporsenn <iporsenn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/11 14:48:34 by iporsenn          #+#    #+#             */
/*   Updated: 2020/04/07 15:28:20 by iporsenn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SCOP_H
# define FT_SCOP_H

# ifdef __APPLE__
#  define GL_SILENCE_DEPRECATION
#  include <OpenGL/gl3.h>
#  define GLFW_INCLUDE_NONE
# else
#  include <glad/glad.h>
# endif
# include <GLFW/glfw3.h>

# ifdef __APPLE__
#  define GLADloadproc void*
#  define gladLoadGLLoader(addr) (void)addr
# endif

# include <stdlib.h>
# include <math.h>
# include <libft.h>
# include <libvec.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>

// Remove at the end
# include <stdio.h>

# define HEIGHT 640
# define WIDTH 480

# define N_KEY 284

typedef struct	s_env
{
	GLFWwindow	*window;
	GLuint		program_id;
	GLuint		model_id;
	GLuint		view_id;
	GLuint		projection_id;
	u_int8_t	keys[N_KEY];
}				t_env;

typedef struct	s_obj
{
	GLuint	vbo;
	GLuint	vao;
	GLuint	ebo;
	t_array	vertices;
	t_array	vertices_final;
	t_array	indices;
}			t_obj;

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

typedef	struct	s_matrice
{
	t_mat4	translation;
	t_mat4	identity;
	t_mat4	scale;
	t_mat4	model;
	t_mat4	view;
	t_mat4	projection;
}				t_matrice;

void			get_error();
t_obj			*parsing(char *path);
void			draw(t_env env, t_obj triangle, t_matrice matrice);
t_env			*init();
t_obj			*init_obj(t_obj *obj);
GLuint			load_shaders();
void			error_callback(const char *error, const char *description);

t_matrice		*init_matrice();
void			init_mvp(t_env env, t_matrice matrice);
t_vec4			mat_vec(t_mat4 mat, t_vec4 vec);
t_array			transformation(t_array vertices, t_matrice matrice);

t_mat4			update_translation(t_mat4 translation, t_env env);

#endif
