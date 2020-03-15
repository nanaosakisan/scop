/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transformation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iporsenn <iporsenn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/11 16:08:38 by iporsenn          #+#    #+#             */
/*   Updated: 2020/03/15 13:26:12 by iporsenn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_scop.h>

t_array		translation(t_array vertices, t_mat4 translation, t_array vertices_final)
{
	int		i;
	t_array	res;
	t_vec4	push;

	i = 0;
	res = anew(NULL, vertices_final.len, vertices_final.elem_size);
	while ((size_t)i < vertices.len)
	{
		push = mat_vec(translation, *(t_vec4*)anth(&vertices, i));
		apush(&res, &push);
		i++;
	}
	if (vertices_final.allocated != 0)
		free(vertices_final.memory);
	return (res);
}
