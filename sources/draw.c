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

void	draw(t_env env, t_obj obj, t_matrice matrice)
{
	static t_state *state = NULL;

	glClearColor(0.0f, 0.0f, 0.4f, 0.0f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glUseProgram(env.program_id);
	state = init_state(state);
	*state = update_orientation(*state, env);
	matrice.model = mat_mat(matrice.model, init_rot_x(state->angle_x));
	matrice.model = mat_mat(matrice.model, init_rot_y(state->angle_y));
	matrice.model = update_model(matrice.model, env);
	init_mvp(env, matrice);
	glDrawArrays(GL_TRIANGLES, 0, obj.vertices_final.len);
	glfwSwapBuffers(env.window);
	glfwPollEvents();
}
