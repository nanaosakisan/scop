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

# include <libft.h>
# include <libvec.h>
# include <mat.h>

# include <stdlib.h>
# include <math.h>
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

# define N_KEY 348

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

typedef	struct	s_state
{
	float	angle_x;
	float	angle_y;
	t_vec3	translation;
}				t_state;

typedef	struct	s_mvp
{
	t_mat4	model;
	t_mat4	view;
	t_mat4	projection;
}				t_mvp;

t_env			*init_env();
t_env			*ft_get_env();
GLuint			load_shaders();

t_obj			*init_obj(t_obj *obj);
t_state			*get_state();
t_obj			*parsing(char *path);
t_array			vertice_to_final(t_array vertices, t_array indices);

void			get_error();
void			error_callback(const char *error, const char *description);

t_mvp			*init_matrice(t_env env);

void 			key_callback(GLFWwindow* window, int key, int scancode,\
				int action, int mods);
void			scroll_callback(GLFWwindow* window, double xoffset,\
				double yoffset);
t_state			update_state(t_env env, t_state state);

void			draw(t_env env, t_obj triangle, t_mvp matrice);

//A supprimer
void    print_mat(t_mat4 mat);
void	print_vec3(t_vec3 vec);

#endif
