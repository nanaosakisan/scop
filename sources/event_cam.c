/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_cam.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iporsenn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/24 13:23:58 by iporsenn          #+#    #+#             */
/*   Updated: 2020/06/24 13:24:00 by iporsenn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_scop.h>

void	scroll_callback_cam(GLFWwindow *window, double xoffset, double yoffset)
{
	t_state *state;

	(void)window;
	(void)xoffset;
	state = get_state();
	state->fov += 0.1 * yoffset;

}

void			mouse_callback(GLFWwindow *window, double xpos, double ypos)
{
	t_state	*state;
	float	xoffset;
	float	yoffset;
	float	sensititvity;
	t_vec3	dir;

	if (glfwGetMouseButton(window, GLFW_MOUSE_BUTTON_LEFT) == GLFW_PRESS)
	{
		state = get_state();
		if (state->first_mouse)
		{
			state->last_cursor[0] = xpos;
			state->last_cursor[1] = ypos;
			state->first_mouse = 0;
		}
		xoffset = xpos - state->last_cursor[0];
		yoffset = ypos - state->last_cursor[1];
		state->last_cursor[0] = xoffset;
		state->last_cursor[1] = yoffset;
		sensititvity = 0.001;
		xoffset *= sensititvity;
		yoffset *= sensititvity;
		state->yaw += xoffset;
		state->pitch += yoffset;
		dir.x = cos(state->yaw) * cos(state->pitch);
		dir.y = sin(state->pitch);
		dir.z = sin(state->yaw) * cos(state->pitch);
		state->front = vec3_normalize(dir);
	}
}

static t_state	update_pos(t_env env, t_state state)
{
	float	speed = 0.01;

	if (env.keys[GLFW_KEY_W])
		state.pos = vec3_add(state.pos, vec3_scale(state.front, speed));
	if (env.keys[GLFW_KEY_S])
		state.pos = vec3_sub(state.pos, vec3_scale(state.front, speed));;
	if (env.keys[GLFW_KEY_D])
		state.pos = vec3_add(state.pos,\
			vec3_normalize(vec3_scale(vec3_cross(state.front, state.up), speed)));
	if (env.keys[GLFW_KEY_A])
		state.pos = vec3_sub(state.pos,\
			vec3_normalize(vec3_scale(vec3_cross(state.front, state.up), speed)));
	// printf("pos:\n");
	// print_vec3(state.pos);
	return (state);
}

t_state			update_state_cam(t_env env, t_state state)
{
	// state = update_orientation(env, state);
	state = update_pos(env, state);
	return (state);
}