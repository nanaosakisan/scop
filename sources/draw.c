/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   first_draw.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iporsenn <iporsenn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/11 17:47:29 by iporsenn          #+#    #+#             */
/*   Updated: 2020/02/21 15:40:36 by iporsenn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_scop.h"

void	draw(GLuint program_id, t_obj obj)
{
	glUseProgram(program_id);
	glBindVertexArray(obj.vao);
	if (obj.indices.len == 0)
		glDrawArrays(GL_TRIANGLES, 0, obj.vertices.len);
	else
		glDrawElements(GL_TRIANGLES, obj.indices.len, GL_UNSIGNED_INT, 0);
}
