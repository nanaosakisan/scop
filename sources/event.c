/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iporsenn <iporsenn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/11 16:40:22 by iporsenn          #+#    #+#             */
/*   Updated: 2020/03/18 12:01:01 by iporsenn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_scop.h>

t_mat4	update_translation(t_mat4 translation, t_env env)
{
	if (glfwGetKey(env.window, GLFW_KEY_W) == GLFW_PRESS)
		translation.w1 += 0.1;
	if (glfwGetKey(env.window, GLFW_KEY_S) == GLFW_PRESS)
		translation.w1 -= 0.1;
	if (glfwGetKey(env.window, GLFW_KEY_A) == GLFW_PRESS)
		translation.w2 += 0.1;
	if (glfwGetKey(env.window, GLFW_KEY_D) == GLFW_PRESS)
		translation.w2 -= 0.1;
	return (translation);
}

// void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
// {
//     if (key == GLFW_KEY_W || key == GLFW_KEY_S || key == GLFW_KEY_A
// 		|| key == GLFW_KEY_D && action == GLFW_PRESS)
//         update_translation();
// }
