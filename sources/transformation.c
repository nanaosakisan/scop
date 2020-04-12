/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transformation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iporsenn <iporsenn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/11 16:08:38 by iporsenn          #+#    #+#             */
/*   Updated: 2020/04/12 18:19:05 by iporsenn         ###   ########.fr       */
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
	if (vertices.allocated != 0)
		free(vertices.memory);
	return (vertices_final);
}

static t_array	scale(t_array vertices, t_mat4 scale)
{
	int		i;
	t_vec4	push;
	t_array	vertice_final;

	i = 0;
	vertice_final = anew(NULL, vertices.len, vertices.elem_size);
	while ((size_t)i < vertices.len)
	{
		push = mat_vec(scale, *(t_vec4*)anth(&vertices, i));
		apush(&vertice_final, &push);
		i++;
	}
	if (vertices.allocated != 0)
		free(vertices.memory);
	return (vertice_final);
}

static t_array	identity(t_array vertices, t_mat4 identity)
{
	int		i;
	t_vec4	push;
	t_array	vertice_final;

	i = 0;
	vertice_final = anew(NULL, vertices.len, vertices.elem_size);
	while ((size_t)i < vertices.len)
	{
		push = mat_vec(identity, *(t_vec4*)anth(&vertices, i));
		apush(&vertice_final, &push);
		i++;
	}
	if (vertices.allocated != 0)
		free(vertices.memory);
	return (vertice_final);
}

static t_array	rotation(t_array vertices, t_matrice matrice)
{
	int		i;
	t_vec4	push;
	t_array	vertice_final;

	i = 0;
	vertice_final = anew(NULL, vertices.len, vertices.elem_size);
	while ((size_t)i < vertices.len)
	{
		push = mat_vec(matrice.rot_x, *(t_vec4*)anth(&vertices, i));
		push = mat_vec(matrice.rot_y, push);
		push = mat_vec(matrice.rot_z, push);
		apush(&vertice_final, &push);
		i++;
	}
	if (vertices.allocated != 0)
		free(vertices.memory);
	return (vertice_final);
}

t_array			transformation(t_array vertices_final, t_matrice matrice)
{
	vertices_final = identity(vertices_final, matrice.identity);
	vertices_final = scale(vertices_final, matrice.scale);
	vertices_final = rotation(vertices_final, matrice);
	vertices_final = translation(vertices_final, matrice.translation);
	return (vertices_final);
}