/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iporsenn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/11 16:40:22 by iporsenn          #+#    #+#             */
/*   Updated: 2020/03/11 16:40:25 by iporsenn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_scop.h>

t_mat4	update_translation(t_mat4 translation)
{
	printf("key.w: %d\n", glfwGetKeyScancode(GLFW_KEY_W));
	translation.z1 = -0.5 * glfwGetKeyScancode(GLFW_KEY_W) + 0.5\
		* glfwGetKeyScancode(GLFW_KEY_S);
	translation.z2 = -0.5 * glfwGetKeyScancode(GLFW_KEY_A) + 0.5\
		* glfwGetKeyScancode(GLFW_KEY_D);
	return (translation);
}

void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
    if (key == GLFW_KEY_W || key == GLFW_KEY_S || key == GLFW_KEY_A
		|| key == GLFW_KEY_D && action == GLFW_PRESS)
        update_translation();
}
