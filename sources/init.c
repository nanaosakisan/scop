/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iporsenn <iporsenn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/17 15:00:38 by iporsenn          #+#    #+#             */
/*   Updated: 2020/04/12 18:32:43 by iporsenn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_scop.h>


void	framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
	// make sure the viewport matches the new window dimensions; note that
	// width and height will be significantly larger than specified on retina
	// displays.
	if (!window)
		return ;
	glViewport(0, 0, width, height);
}

t_obj	*init_obj(t_obj *obj)
{

	float	*vert;

	vert = (float *)obj->vertices_final.first;
	glGenBuffers(1, &obj->vbo);
	glBindBuffer(GL_ARRAY_BUFFER, obj->vbo);
	glBufferData(GL_ARRAY_BUFFER, (obj->vertices.elem_size * obj->vertices_final.len),
		vert, GL_STATIC_DRAW);
	glGenVertexArrays(1, &obj->vao);
	glBindVertexArray(obj->vao);
	glVertexAttribPointer(0, 4, GL_FLOAT, GL_FALSE, 4 * sizeof(float),
		(void*)0);
	glEnableVertexAttribArray(0);
	glBindBuffer(GL_ARRAY_BUFFER, 0); 
	glBindVertexArray(0);
	glBindVertexArray(obj->vao);
	return (obj);
}

t_env	*init()
{
	t_env	*env;

	if (!(env = (t_env*)malloc(sizeof(env))))
	{
		error_callback("MALLOC", "environment's malloc failed.");
		return (NULL);
	}
	if (!glfwInit())
	{
		error_callback("GLFW", "Failed to initialize GLFW");
		return (NULL);
	}
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 1);
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	env->window = glfwCreateWindow(HEIGHT, WIDTH, "ft_scop", NULL, NULL);
	if (!env->window)
	{
		error_callback("WINDOW", "Failed to open window");
		glfwTerminate();
		return (NULL);
	}
	glfwMakeContextCurrent(env->window);
	glfwSetFramebufferSizeCallback(env->window, framebuffer_size_callback);
	gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);
	glfwSetInputMode(env->window, GLFW_STICKY_KEYS, GL_TRUE);
	env->angle_x = 0;
	env->angle_y = 0;
	env->angle_z = 0;
	return (env);
}
