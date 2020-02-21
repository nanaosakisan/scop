/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_scop.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iporsenn <iporsenn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/11 14:48:34 by iporsenn          #+#    #+#             */
/*   Updated: 2020/02/21 14:14:23 by iporsenn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SCOP_H
# define FT_SCOP_H

# ifdef __APPLE__
#  include <OpenGL/gl3.h>
#  define GLFW_INCLUDE_NONE
# else
#  include <glad/glad.h>
# endif
# include <GLFW/glfw3.h>

# include <stdlib.h>
# include <math.h>
# include <libft.h>
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
    float       *vertices;
    float       *indices;
}               t_obj;


void        first_draw(GLuint program_id, t_obj triangle);
t_env       *init();
t_obj       *init_triangle_obj();
GLuint      load_shaders();
void        error_callback(const char *error, const char *description);

 #endif
