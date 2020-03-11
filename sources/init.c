/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iporsenn <iporsenn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/17 15:00:38 by iporsenn          #+#    #+#             */
/*   Updated: 2020/02/21 15:38:39 by iporsenn         ###   ########.fr       */
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

t_matrice	*init_matrice()
{
	t_matrice	*matrice;

	if (!(matrice = (t_matrice*)malloc(sizeof(t_matrice))))
		return (NULL);
	matrice->translation.x1 = 1;
	matrice->translation.y1 = 0;
	matrice->translation.z1 = 0;
	matrice->translation.w1 = 0;
	matrice->translation.x2 = 0;
	matrice->translation.y2 = 1;
	matrice->translation.z2 = 0;
	matrice->translation.w2 = 0;
	matrice->translation.x3 = 0;
	matrice->translation.y3 = 0;
	matrice->translation.z3 = 1;
	matrice->translation.w3 = 0;
	matrice->translation.x4 = 0;
	matrice->translation.y4 = 0;
	matrice->translation.z4 = 0;
	matrice->translation.w4 = 1;
	return (matrice);
}

t_obj	*init_triangle_obj(t_obj *obj)
{

	float	*vert;
	int		*indices;

	vert = (float *)obj->vertices.first;
	indices = (int *)obj->indices.first;
	glGenBuffers(1, &obj->vbo);
	if (obj->indices.len != 0)
		glGenBuffers(1, &obj->ebo);
	glBindBuffer(GL_ARRAY_BUFFER, obj->vbo);
	glBufferData(GL_ARRAY_BUFFER, (obj->vertices.elem_size * obj->vertices.len),
		vert, GL_STATIC_DRAW);
	glGenVertexArrays(1, &obj->vao);
	glBindVertexArray(obj->vao);
	if (obj->indices.len != 0)
	{
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, obj->ebo);
		glBufferData(GL_ELEMENT_ARRAY_BUFFER, (obj->indices.elem_size
			* obj->indices.len), indices, GL_STATIC_DRAW); 	
	}
	glVertexAttribPointer(0, 4, GL_FLOAT, GL_FALSE, 4 * sizeof(float),
		(void*)0);
	glEnableVertexAttribArray(0);

	glBindBuffer(GL_ARRAY_BUFFER, 0); 
	glBindVertexArray(0);  
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
	return (env);
}
