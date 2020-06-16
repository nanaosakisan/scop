/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iporsenn <iporsenn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/11 17:47:29 by iporsenn          #+#    #+#             */
/*   Updated: 2020/05/08 15:39:10 by iporsenn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_scop.h>

static t_mat4	update_model(t_mat4 model, t_env env)
{
	if (glfwGetKey(env.window, GLFW_KEY_W) == GLFW_PRESS)
		model.y4 += 0.01;
	if (glfwGetKey(env.window, GLFW_KEY_S) == GLFW_PRESS)
		model.y4 -= 0.01;
	if (glfwGetKey(env.window, GLFW_KEY_A) == GLFW_PRESS)
		model.x4 -= 0.01;
	if (glfwGetKey(env.window, GLFW_KEY_D) == GLFW_PRESS)
		model.x4 += 0.01;
	return (model);
}


void	draw(t_env env, t_obj obj, t_matrice matrice)
{
	glClearColor(0.0f, 0.0f, 0.4f, 0.0f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
				// update position et zoom;
			// matrice.model = update_model(matrice.model, env);
			// *state = update_state(*env, *state);
			// matrice->view = init_view(state->cam_pos, vec3_add(state->cam_pos,\
			// 	state->cam_front), state->cam_up);
	glUseProgram(env.program_id);	
	init_mvp(env, matrice);
	glDrawArrays(GL_TRIANGLES, 0, obj.vertices_final.len);
	glfwSwapBuffers(env.window);
	glfwPollEvents();
}
