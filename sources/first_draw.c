/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   first_draw.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iporsenn <iporsenn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/11 17:47:29 by iporsenn          #+#    #+#             */
/*   Updated: 2020/02/21 14:14:00 by iporsenn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_scop.h"

void    first_draw(GLuint program_id, t_obj triangle)
{
    glClearColor(0.0f, 0.0f, 0.4f, 0.0f);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glUseProgram(program_id);
    glBindVertexArray(triangle.vao);
    // glDrawArrays(GL_TRIANGLES, 0, 3);

    glDrawElements(GL_TRIANGLES, 9, GL_UNSIGNED_INT, 0);

}