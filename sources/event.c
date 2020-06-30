/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iporsenn <iporsenn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/11 16:40:22 by iporsenn          #+#    #+#             */
/*   Updated: 2020/05/08 16:15:30 by iporsenn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_scop.h>

void	key_callback(GLFWwindow *window, int key, int scancode, int action,\
int mods)
{
	t_env	*env;

	(void)window;
	(void)scancode;
	(void)mods;
	env = ft_get_env();
	if (key == GLFW_KEY_ESCAPE)
		exit(EXIT_SUCCESS);
	if (action == GLFW_PRESS)
		env->keys[key] = 1;
	if (action == GLFW_RELEASE)
		env->keys[key] = 0;
}

void	scroll_callback(GLFWwindow *window, double xoffset, double yoffset)
{
	t_state *state;

	(void)window;
	(void)xoffset;
	state = get_state();
	state->translation.z += 0.1 * yoffset;
}

t_state	update_state(t_env env, t_state state)
{
	// double	pos[2];
	// float	d_time;
	// int		width;
	// int		height;
	// int		mousse_speed;

	// d_time = 0.01;
	// mousse_speed = 3;
	// glfwSetInputMode(env.window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);
	// glfwGetCursorPos(env.window, &pos[0], &pos[1]);
	// glfwGetWindowSize(env.window, &width, &height);
	// if (glfwGetMouseButton(env.window, GLFW_MOUSE_BUTTON_LEFT) == GLFW_PRESS)
	// {
	// 	state.angle_x = mousse_speed * d_time * (width / 2 - pos[0]);
	// 	state.angle_y = mousse_speed * d_time * (height / 2 - pos[1]);
	// }
	// state.translation.y += env.keys[GLFW_KEY_W] * 0.01 - env.keys[GLFW_KEY_S]\
	// 	* 0.01;
	// state.translation.x += env.keys[GLFW_KEY_D] * 0.01 - env.keys[GLFW_KEY_A]\
	// 	* 0.01;
	// state.translation.z += env.keys[GLFW_KEY_Q] * 0.01 - env.keys[GLFW_KEY_E]\
	// 	* 0.01;

	if (env.keys[GLFW_KEY_A])
		state.translation.x -= 0.05;
	if (env.keys[GLFW_KEY_D])
		state.translation.x += 0.05;
	if (env.keys[GLFW_KEY_W])
		state.translation.y -= 0.05;
	if (env.keys[GLFW_KEY_S])
		state.translation.y += 0.05;
	if (env.keys[GLFW_KEY_Q])
		state.translation.z += 0.05;
	if (env.keys[GLFW_KEY_E])
		state.translation.z -= 0.05;
	return (state);
}