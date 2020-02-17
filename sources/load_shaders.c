/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_shaders.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iporsenn <iporsenn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/14 15:31:54 by iporsenn          #+#    #+#             */
/*   Updated: 2020/02/17 13:47:08 by iporsenn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_scop.h"

GLuint load_shaders(GLuint program_id, GLenum shader, char *filename)
{
	GLuint      shader_id;
    GLint       compil_res;
	GLsizei     logsize;
    char        *log;
    int         fd;
    struct stat st;
    char        *source;
    int         ret;

    if ((fd = open(filename, O_RDONLY)) == -1)
        error_callback("cannot open vertex shader.");
    if (stat(filename , &st) == -1) 
        error_callback("cannot read stat.");
    if (!(source = ft_strnew(st.st_size)))
        error_callback("source's malloc failed.");
    if ((ret = read(fd, source, st.st_size)) == -1)
        error_callback("cannot read vertex shader.");
    close(fd);
    shader_id = 0;
    shader_id = glCreateShader(shader);
    if (shader_id == 0)
        error_callback("cannot create shader id.");
	glShaderSource(shader_id, 1, (const GLchar *const *)&source , NULL);
	glCompileShader(shader_id);
    ft_strdel(&source);

	// Check Shader
    compil_res = GL_FALSE;
    glGetShaderiv(shader_id, GL_COMPILE_STATUS, &compil_res);
    log = NULL;
    log = 0;
    if(compil_res != GL_TRUE)
    {
        glGetShaderiv(shader_id, GL_INFO_LOG_LENGTH, &logsize);
        if (!(log = ft_strnew(logsize)))
        {
            error_callback("log's malloc failed.");
            glDeleteShader(shader_id);
        }
        glGetShaderInfoLog(shader_id, logsize, &logsize, log);
        error_callback("cannot compile shader id");
        error_callback(log);
        ft_strdel(&log);
        glDeleteShader(shader_id);
    }

	// // Link the program
	glAttachShader(program_id, shader_id);
	glLinkProgram(program_id);

	// Check the program
	glGetProgramiv(program_id, GL_LINK_STATUS, &compil_res);
    if (compil_res != GL_TRUE)
    {
        glGetProgramiv(program_id, GL_INFO_LOG_LENGTH, &logsize);
        if (!(log = ft_strnew(logsize)))
        {
            error_callback("log's malloc failed.");
            glDeleteShader(shader_id);
        }
        glGetProgramInfoLog(program_id, logsize, NULL, log);
        error_callback("cannot compile shader id");
        error_callback(log);
        ft_strdel(&log);
        glDeleteShader(shader_id);
    }
	
	glDetachShader(program_id, shader_id);
	glDeleteShader(shader_id);
	return program_id;
}