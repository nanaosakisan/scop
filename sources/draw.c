/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iporsenn <iporsenn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/11 17:47:29 by iporsenn          #+#    #+#             */
/*   Updated: 2020/03/15 13:08:00 by iporsenn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_scop.h>

void	draw(t_env env, t_obj obj)
{
	glClearColor(0.0f, 0.0f, 0.4f, 0.0f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glUseProgram(env.program_id);
	glBindVertexArray(obj.vao);
	if (obj.indices.len == 0)
		glDrawArrays(GL_TRIANGLES, 0, obj.vertices.len);
	else
		glDrawElements(GL_TRIANGLES, obj.indices.len, GL_UNSIGNED_INT, 0);
	glfwSwapBuffers(env.window);
	glfwPollEvents();
}
