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

void    first_draw(GLuint program_id, t_obj triangle)
{
    glUseProgram(program_id);
    glBindVertexArray(triangle.vao);
    glDrawArrays(GL_TRIANGLES, 0, 3);
    // glDrawElements(GL_TRIANGLES, 9, GL_UNSIGNED_INT, 0);

}