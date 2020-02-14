/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_shaders.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iporsenn <iporsenn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/14 15:31:54 by iporsenn          #+#    #+#             */
/*   Updated: 2020/02/14 16:47:18 by iporsenn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_scop.h"

// GLuint LoadShaders(const char * vertex_file_path,const char * fragment_file_path)
void load_shaders(t_shader_type shader, char *filename)
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
    // source[st.st_size] = '\0';
    ft_putendl(source);
    shader_id = 0;
    if (shader == VERTEX)
        shader_id = glCreateShader(GL_VERTEX_SHADER);
    else if (shader == FRAGMENT)
        shader_id = glCreateShader(GL_FRAGMENT_SHADER);
    if (shader_id == 0)
        error_callback("cannot create shader id.");
	glShaderSource(shader_id, 1, (const GLchar *const *)&source , NULL);
	glCompileShader(shader_id);
    ft_strdel(&source);

	// Check Vertex Shader
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
	// printf("Linking program\n");
	// GLuint ProgramID = glCreateProgram();
	// glAttachShader(ProgramID, shader_id);
	// glAttachShader(ProgramID, FragmentShaderID);
	// glLinkProgram(ProgramID);

	// // Check the program
	// glGetProgramiv(ProgramID, GL_LINK_STATUS, &compil_res);
	// glGetProgramiv(ProgramID, GL_INFO_LOG_LENGTH, &InfoLogLength);
	// if ( InfoLogLength > 0 ){
	// 	std::vector<char> ProgramErrorMessage(InfoLogLength+1);
	// 	glGetProgramInfoLog(ProgramID, InfoLogLength, NULL, &ProgramErrorMessage[0]);
	// 	printf("%s\n", &ProgramErrorMessage[0]);
	// }

	
	// glDetachShader(ProgramID, shader_id);
	// glDetachShader(ProgramID, FragmentShaderID);
	
	// glDeleteShader(shader_id);
	// glDeleteShader(FragmentShaderID);

	// return ProgramID;
}