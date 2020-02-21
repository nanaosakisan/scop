/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_shaders.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iporsenn <iporsenn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/14 15:31:54 by iporsenn          #+#    #+#             */
/*   Updated: 2020/02/20 17:31:11 by iporsenn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_scop.h"

static int      check_shader_link(GLuint program_id, GLuint shader_id)
{
    GLint       compil_res;
	GLsizei     logsize;
    char        *log;

    glGetProgramiv(program_id, GL_LINK_STATUS, &compil_res);
    if (compil_res != GL_TRUE)
    {
        glGetProgramiv(program_id, GL_INFO_LOG_LENGTH, &logsize);
        if (!(log = ft_strnew(logsize)))
        {
            error_callback("MALLOC", "log's malloc failed.");
            glDeleteShader(shader_id);
            glDeleteProgram(program_id);
            return (-1);
        }
        glGetProgramInfoLog(program_id, logsize, NULL, log);
        error_callback("SHADER", "cannot compile shader id");
        error_callback("SHADER", log);
        ft_strdel(&log);
        glDeleteShader(shader_id);
        glDeleteProgram(program_id);
        return (-1);
    }
    return (1);
}

static int      check_shader_compilation(GLuint shader_id)
{
    GLint       compil_res;
    GLsizei     logsize;
    char        *log;

    compil_res = GL_FALSE;
    glGetShaderiv(shader_id, GL_COMPILE_STATUS, &compil_res);
    log = NULL;
    log = 0;
    if(compil_res != GL_TRUE)
    {
        glGetShaderiv(shader_id, GL_INFO_LOG_LENGTH, &logsize);
        if (!(log = ft_strnew(logsize)))
        {
            error_callback("MALLOC", "log's malloc failed.");
            glDeleteShader(shader_id);
            return (-1);
        }
        glGetShaderInfoLog(shader_id, logsize, &logsize, log);
        error_callback("SHADER", "cannot compile shader id");
        error_callback("SHADER", log);
        ft_strdel(&log);
        glDeleteShader(shader_id);
        return (-1);
    }
    return (1);
}

static char    *load_source(char *filename)
{
    int         fd;
    struct stat st;
    char        *source;
    int         ret;

    if ((fd = open(filename, O_RDONLY)) == -1)
        error_callback("FD", "cannot open vertex shader.");
    if (stat(filename , &st) == -1) 
        error_callback("STAT", "cannot read stat.");
    if (!(source = ft_strnew(st.st_size)))
        error_callback("MALLOC", "source's malloc failed.");
    if ((ret = read(fd, source, st.st_size)) == -1)
        error_callback("READ", "cannot read vertex shader.");
    close(fd);
    return (source);
}

static GLuint   create_shader(GLenum shader, char *source)
{
    GLuint      shader_id;

    shader_id = 0;
    shader_id = glCreateShader(shader);
    if (shader_id == 0)
        error_callback("SHADER", "cannot create shader id.");
	glShaderSource(shader_id, 1, (const GLchar *const *)&source , NULL);
	glCompileShader(shader_id);
    ft_strdel(&source);
    if (check_shader_compilation(shader_id) == -1)
        return (0);
    return (shader_id);
}

GLuint          load_shaders()
{
	GLuint      vertex_id;
    GLuint      fragment_id;
    char        *vertex_source;
    char        *fragment_source;
    GLuint      program_id;

    vertex_source = load_source("./shaders/vertex_shader.glsl");
    fragment_source = load_source("./shaders/fragment_shader.glsl");
    vertex_id = create_shader(GL_VERTEX_SHADER, vertex_source);
    fragment_id = create_shader(GL_FRAGMENT_SHADER, fragment_source);
    program_id = glCreateProgram();
	glAttachShader(program_id, vertex_id);
    glAttachShader(program_id, fragment_id);
	glLinkProgram(program_id);
    if (check_shader_link(program_id, vertex_id) == -1)
        return (0);
	glDetachShader(program_id, vertex_id);
	glDeleteShader(vertex_id);
    if (check_shader_link(program_id, fragment_id) == -1)
        return (0);
	glDetachShader(program_id, fragment_id);
	glDeleteShader(fragment_id);
	return program_id;
}