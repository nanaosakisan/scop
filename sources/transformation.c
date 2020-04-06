/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transformation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iporsenn <iporsenn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/11 16:08:38 by iporsenn          #+#    #+#             */
/*   Updated: 2020/04/06 17:05:53 by iporsenn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_scop.h>

static t_array	translation(t_array vertices, t_mat4 translation)
{
	int		i;
	t_vec4	push;
	t_array	vertices_final;

	i = 0;
	vertices_final = anew(NULL, 1, sizeof(t_vec4));
	while ((size_t)i < vertices.len)
	{
		push = mat_vec(translation, *(t_vec4*)anth(&vertices, i));
		apush(&vertices_final, &push);
		i++;
	}
	return (vertices_final);
}

static t_array	scale(t_array vertice, t_mat4 scale)
{
	int		i;
	t_vec4	push;
	t_array	vertice_final;

	i = 0;
	vertice_final = anew(NULL, vertice.len, vertice.elem_size);
	while ((size_t)i < vertice.len)
	{
		push = mat_vec(scale, *(t_vec4*)anth(&vertice, i));
		apush(&vertice_final, &push);
		i++;
	}
	if (vertice.allocated != 0)
		free(vertice.memory);
	return (vertice_final);
}

static t_array	identity(t_array vertice, t_mat4 identity)
{
	int		i;
	t_vec4	push;
	t_array	vertice_final;

	i = 0;
	vertice_final = anew(NULL, vertice.len, vertice.elem_size);
	while ((size_t)i < vertice.len)
	{
		push = mat_vec(identity, *(t_vec4*)anth(&vertice, i));
		apush(&vertice_final, &push);
		i++;
	}
	if (vertice.allocated != 0)
		free(vertice.memory);
	return (vertice_final);
}

t_array			transformation(t_array vertices, t_matrice matrice)
{
	t_array	vertices_final;

	vertices_final = translation(vertices, matrice.translation);
	vertices_final = scale(vertices_final, matrice.scale);
	vertices_final = identity(vertices_final, matrice.identity);
	return (vertices_final);
}