/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transformation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iporsenn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/11 16:08:38 by iporsenn          #+#    #+#             */
/*   Updated: 2020/03/11 16:08:39 by iporsenn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_scop.h>

t_array		translation(t_array vertices, t_mat4 translation, t_array vertices_final)
{
	int		i;
	t_vec4	push;

	i = 0;
	while ((size_t)i < vertices.len)
	{
		push = mat_vec(translation, *(t_vec4*)anth(&vertices, i));
		// ft_memmove(vertices_final.first + i * vertices_final.elem_size, &push, vertices_final.elem_size);
		apush(&vertices_final, &push);
		i++;
	}
	return (vertices_final);
}
