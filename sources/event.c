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

// void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
// {
//     if (key == GLFW_KEY_W || key == GLFW_KEY_S || key == GLFW_KEY_A
// 		|| key == GLFW_KEY_D && action == GLFW_PRESS)
//         update_translation();
// }

t_state		update_orientation(t_state state, t_env env)
{
	double	pos_x;
	double	pos_y;
	float	d_time;
	int		width;
	int		height;
	int		mousse_speed;

	// d_time = 0.01;
	// mousse_speed = 3;
	// glfwSetInputMode(env.window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);
	// glfwGetCursorPos(env.window, &pos_x, &pos_y);
	// glfwGetWindowSize(env.window, &width, &height);
	// glfwSetCursorPos(env.window, width / 2, height / 2);
	// if (glfwGetMouseButton(env.window, GLFW_MOUSE_BUTTON_LEFT) == GLFW_PRESS)
	// {
	// 	state.angle_x = mousse_speed * d_time * (width / 2 - pos_x);
	// 	state.angle_y = mousse_speed * d_time * (height / 2 - pos_y);
	// }

	if (glfwGetKey(env.window, GLFW_KEY_RIGHT) == GLFW_PRESS)
		state.angle_x += 0.1;
	if (glfwGetKey(env.window, GLFW_KEY_LEFT) == GLFW_PRESS)
		state.angle_x -= 0.1;
	// printf("angle_x: %f")
	return (state);
}