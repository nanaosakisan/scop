/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iporsenn <iporsenn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/11 17:47:29 by iporsenn          #+#    #+#             */
/*   Updated: 2020/05/11 15:54:41 by iporsenn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_scop.h>

static void	init_mvp(t_env env, t_mvp matrice)
{
	// glUniformMatrix4fv(env.model_id, 1, GL_FALSE,\
	// 	(const GLfloat*)&matrice.model);
	glUniformMatrix4fv(env.view_id, 1, GL_FALSE,\
		(const GLfloat*)&matrice.view);
	glUniformMatrix4fv(env.projection_id, 1, GL_FALSE,\
		(const GLfloat*)&matrice.projection);
}

void		draw(t_env env, t_obj obj, t_mvp matrice)
{
	t_state *state;
	t_vec3 cubePositions[] = {
        vec3_new( 0.0f,  0.0f,  0.0f),
        vec3_new( 2.0f,  5.0f, -15.0f),
        vec3_new(-1.5f, -2.2f, -2.5f),
        vec3_new(-3.8f, -2.0f, -12.3f),
        vec3_new( 2.4f, -0.4f, -3.5f),
        vec3_new(-1.7f,  3.0f, -7.5f),
        vec3_new( 1.3f, -2.0f, -2.5f),
        vec3_new( 1.5f,  2.0f, -2.5f),
        vec3_new( 1.5f,  0.2f, -1.5f),
        vec3_new(-1.3f,  1.0f, -1.5f)
    };

	state = NULL;
	glClearColor(0.0f, 0.0f, 0.4f, 0.0f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glUseProgram(env.program_id);
	glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
	state = get_state();

	*state = update_state_cam(env, *state);
	matrice.view = init_view(state->pos, vec3_add(state->pos, state->front),\
		state->up);
	matrice.projection = init_projection(state->fov, -1, 1000);
	init_mvp(env, matrice);

 	for (unsigned int i = 0; i < 10; i++)
    {
        // calculate the model matrix for each object and pass it to shader before drawing
        matrice.model = init_identity(vec4_new(1, 1, 1, 1)); // make sure to initialize matrix to identity matrix first
        matrice.model = mat_mat(matrice.model, init_translation_inv(cubePositions[i]));
        float angle = 20.0f * i;
        matrice.model = mat_mat(matrice.model, init_rot_x(angle * (M_PI / 180)));
       	glUniformMatrix4fv(env.model_id, 1, GL_FALSE,\
			(const GLfloat*)&matrice.model);

        // glDrawArrays(GL_TRIANGLES, 0, 36);
    }

	glDrawArrays(GL_TRIANGLES, 0, obj.vertices_final.len);
	glfwSwapBuffers(env.window);
	glfwPollEvents();
}
