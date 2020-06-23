/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_tool.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iporsenn <iporsenn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/11 19:01:44 by iporsenn          #+#    #+#             */
/*   Updated: 2020/04/11 19:02:09 by iporsenn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_scop.h>

t_array	vertice_to_final(t_array vertices, t_array indices)
{
	int		i;
	t_array	vertices_final;
	t_vec4	push;

	i = 0;
	vertices_final = anew(NULL, 1, sizeof(t_vec4));
	while ((size_t)i < indices.len)
	{
		push = *(t_vec4*)anth(&vertices, (*(int*)anth(&indices, i)) - 1);
		apush(&vertices_final, &push);
		i++;
	}
	return (vertices_final);
}
