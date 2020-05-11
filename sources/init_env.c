/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_env.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iporsenn <iporsenn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/17 15:00:38 by iporsenn          #+#    #+#             */
/*   Updated: 2020/05/11 16:06:36 by iporsenn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_scop.h>

void		framebuffer_size_callback(GLFWwindow *window, int width, int height)
{
	if (!window)
		return ;
	glViewport(0, 0, width, height);
}

t_env		*ft_get_env(void)
{
	static t_env *env;

	if (env == NULL)
		env = (t_env*)malloc(sizeof(t_env));
	return (env);
}

static void	init_glfw(void)
{
	if (!glfwInit())
	{
		error_callback("GLFW", "Failed to initialize GLFW");
		return ;
	}
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 1);
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
}

t_env		*init_env(void)
{
	t_env	*env;

	env = ft_get_env();
	init_glfw();
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
	glfwSetKeyCallback(env->window, key_callback);
	glfwSetScrollCallback(env->window, scroll_callback);
	glEnable(GL_DEPTH_TEST);
	glDepthFunc(GL_LESS);
	env->program_id = load_shaders();
	env->model_id = glGetUniformLocation(env->program_id, "model");
	env->view_id = glGetUniformLocation(env->program_id, "view");
	env->projection_id = glGetUniformLocation(env->program_id, "projection");
	ft_bzero(env->keys, 348);
	return (env);
}

t_state		*get_state(void)
{
	static t_state *state = NULL;

	if (state == NULL)
	{
		state = (t_state *)malloc(sizeof(t_state));
		state->angle_x = 0;
		state->angle_y = 0;
		state->scale = vec4_new(1, 1, 1, 1);
		state->translation = vec3_new(0, 0, 0);
	}
	return (state);
}
