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

static void	init_mvp(t_env env, t_mvp matrice)
{
	glUniformMatrix4fv(env.model_id, 1, GL_FALSE,\
		(const GLfloat*)&matrice.model);
	glUniformMatrix4fv(env.view_id, 1, GL_FALSE,\
		(const GLfloat*)&matrice.view);
	glUniformMatrix4fv(env.projection_id, 1, GL_FALSE,\
		(const GLfloat*)&matrice.projection);
}

void		draw(t_env env, t_obj obj, t_mvp matrice)
{
	t_state *state;

	state = NULL;
	glClearColor(0.0f, 0.0f, 0.4f, 0.0f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glUseProgram(env.program_id);
	glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
	state = get_state();
	*state = update_state(env, *state);
	matrice.model = mat_mat(matrice.model, init_identity(state->scale));
	matrice.model = mat_mat(matrice.model, init_rot_x(state->angle_y));
	matrice.model = mat_mat(matrice.model, init_rot_y(state->angle_x));
	matrice.model = mat_mat(init_translation_inv(state->translation),\
		matrice.model);
	init_mvp(env, matrice);
	glDrawArrays(GL_TRIANGLES, 0, obj.vertices_final.len);
	glfwSwapBuffers(env.window);
	glfwPollEvents();
}
