/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iporsenn <iporsenn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/17 15:00:38 by iporsenn          #+#    #+#             */
/*   Updated: 2020/05/09 15:09:34 by iporsenn         ###   ########.fr       */
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
	static const GLfloat g_color_buffer_data[] = {
		0.583f,  0.771f,  0.014f,
		0.609f,  0.115f,  0.436f,
		0.327f,  0.483f,  0.844f,
		0.822f,  0.569f,  0.201f,
		0.435f,  0.602f,  0.223f,
		0.310f,  0.747f,  0.185f,
		0.597f,  0.770f,  0.761f,
		0.559f,  0.436f,  0.730f,
		0.359f,  0.583f,  0.152f,
		0.483f,  0.596f,  0.789f,
		0.559f,  0.861f,  0.639f,
		0.195f,  0.548f,  0.859f,
		0.014f,  0.184f,  0.576f,
		0.771f,  0.328f,  0.970f,
		0.406f,  0.615f,  0.116f,
		0.676f,  0.977f,  0.133f,
		0.971f,  0.572f,  0.833f,
		0.140f,  0.616f,  0.489f,
		0.997f,  0.513f,  0.064f,
		0.945f,  0.719f,  0.592f,
		0.543f,  0.021f,  0.978f,
		0.279f,  0.317f,  0.505f,
		0.167f,  0.620f,  0.077f,
		0.347f,  0.857f,  0.137f,
		0.055f,  0.953f,  0.042f,
		0.714f,  0.505f,  0.345f,
		0.783f,  0.290f,  0.734f,
		0.722f,  0.645f,  0.174f,
		0.302f,  0.455f,  0.848f,
		0.225f,  0.587f,  0.040f,
		0.517f,  0.713f,  0.338f,
		0.053f,  0.959f,  0.120f,
		0.393f,  0.621f,  0.362f,
		0.673f,  0.211f,  0.457f,
		0.820f,  0.883f,  0.371f,
		0.982f,  0.099f,  0.879f
	};

	GLuint colorbuffer;

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

	glGenBuffers(1, &colorbuffer);
	glBindBuffer(GL_ARRAY_BUFFER, colorbuffer);
	glBufferData(GL_ARRAY_BUFFER, sizeof(g_color_buffer_data), g_color_buffer_data, GL_STATIC_DRAW);
	glEnableVertexAttribArray(1);
	glBindBuffer(GL_ARRAY_BUFFER, colorbuffer);
	glVertexAttribPointer(
		1,                                // attribute. No particular reason for 1, but must match the layout in the shader.
		3,                                // size
		GL_FLOAT,                         // type
		GL_FALSE,                         // normalized?
		0,                                // stride
		(void*)0                          // array buffer offset
	);
	// Enable depth test
	glEnable(GL_DEPTH_TEST);
	// Accept fragment if it closer to the camera than the former one
	glDepthFunc(GL_LESS);
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

t_state		*init_state(t_state *state)
{
	if (state == NULL)
	{
		printf("buh\n");
		state = (t_state *)malloc(sizeof(t_state));
		state->angle_x = 0;
		state->angle_y = 0;
	}
	return (state);
}