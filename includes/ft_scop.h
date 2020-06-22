/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_scop.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iporsenn <iporsenn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/11 14:48:34 by iporsenn          #+#    #+#             */
/*   Updated: 2020/05/09 15:43:36 by iporsenn         ###   ########.fr       */
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

# ifndef M_PI 
#  define M_PI 3.1415926535 
# endif

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

typedef	struct	s_state
{
	float	angle_x;
	float	angle_y;
	t_vec4	scale;
	t_vec3	translation;
}				t_state;

typedef	struct	s_mvp
{
	t_mat4	model;
	t_mat4	view;
	t_mat4	projection;
}				t_mvp;

t_env			*ft_get_env();
void 			key_callback(GLFWwindow* window, int key, int scancode,\
				int action, int mods);
t_env			*init();
t_obj			*init_obj(t_obj *obj);
t_state			*get_state();
GLuint			load_shaders();
t_obj			*parsing(char *path);
t_array			vertice_to_final(t_array vertices, t_array indices);

void			get_error();
void			error_callback(const char *error, const char *description);

void			draw(t_env env, t_obj triangle, t_mvp matrice);

t_mvp			*init_matrice();
t_mat4			init_identity(t_vec4 vec);
t_mat4			init_view(t_vec3 pos, t_vec3 target, t_vec3 up);
void			init_mvp(t_env env, t_mvp matrice);
t_mat4			init_rot_x(float angle_x);
t_mat4			init_rot_y(float angle_y);
t_mat4			init_translation(t_vec3 trans);
t_mat4			init_translation_inv(t_vec3 trans);

t_state			update_state(t_env env, t_state state);
t_state			update_translation(t_state state, t_env env);
t_mat4			update_model(t_mat4 model, t_env env);

t_vec4			mat_vec(t_mat4 mat, t_vec4 vec);
t_mat4			mat_mat(t_mat4 m1, t_mat4 m2);

//A supprimer
void    print_mat(t_mat4 mat);
void	print_vec3(t_vec3 vec);

#endif
