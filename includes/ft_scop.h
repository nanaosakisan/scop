/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_scop.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iporsenn <iporsenn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/11 14:48:34 by iporsenn          #+#    #+#             */
/*   Updated: 2020/03/07 17:39:18 by iporsenn         ###   ########.fr       */
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

typedef struct  s_env
{
    GLFWwindow  *window;
    GLuint      program_id;
}               t_env;

typedef struct  s_obj
{
    GLuint      vbo;
    GLuint      vao;
    GLuint      ebo;
    t_array     vertices;
    // float       *vertices;
    t_array     indices;
    // float       *indices;
}               t_obj;

t_obj		*parsing(char *path);
void        draw(GLuint program_id, t_obj triangle);
t_env       *init();
t_obj       *init_triangle_obj(t_obj *obj);
t_obj       *init_triangle_obj2();
GLuint      load_shaders();
void        error_callback(const char *error, const char *description);

 #endif
