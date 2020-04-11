/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iporsenn <iporsenn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/21 16:41:30 by iporsenn          #+#    #+#             */
/*   Updated: 2020/04/11 18:59:09 by iporsenn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_scop.h>

static t_array	parse_vertice(char **split, t_array vertices)
{
	int		i;
	t_vec4	push;

	i = 1;
	if (split[i])
	{
		push.x = (float)ft_atof(split[1]);
		push.y = (float)ft_atof(split[2]);
		push.z = (float)ft_atof(split[3]);
		push.w = 1;
		apush(&vertices, &push);
	}
	return (vertices);
}

static void	triangulate(char **str, int end, t_array *indices)
{
	int			start;
	int			push;

	start = 2;
	while (start < end - 1)
	{
		push = ft_atoi(str[start]);
		apush(indices, &push);
		push = ft_atoi(str[start + 1]);
		apush(indices, &push);
		push = ft_atoi(str[1]);
		apush(indices, &push);
		start++;
	}
}

static void	parse_indice(char **split, t_array *indices)
{
	int			i;
	int			push;

	i = 1;
	while (split[i])
		i++;
	if (i < 4)
		return ;
	if (i == 4)
	{
		i = 1;
		while (split[i])
		{
			if (split[i])
			{
				push = ft_atoi(split[i]);
				apush(indices, &push);
			}
			i++;
		}
	}
	else
		triangulate(split, i, indices);
}

static t_obj	*read_file(int fd, t_obj *obj)
{
	int		ret;
	char	*line;
	char	**split;

	ret = 0;
	line = NULL;
	while ((ret = get_next_line(fd, &line) != 0))
	{
		split = ft_strsplit(line, ' ');
		if (ft_strequ(split[0], "v") == 1)
			obj->vertices = parse_vertice(split, obj->vertices);
		else if (ft_strequ(split[0], "f") == 1)
			parse_indice(split, &obj->indices);
		ft_strdel(&line);
		free(split);
	}
	return (obj);
}

t_array			vertice_to_final(t_array vertices, t_array indices)
{
	int 	i;
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

t_obj			*parsing(char *path)
{
	t_obj	*obj;
	int		fd;

	if (!(obj = (t_obj *)malloc(sizeof(t_obj))))
	{
		error_callback("PARSING", "object's malloc failed");
		return (NULL);
	}
	fd = 0;
	fd = open(path, fd, O_RDONLY);
	if (!fd)
	{
		error_callback("PARSING", "can't open file");
		return (NULL);
	}
	obj->vertices = anew(NULL, 1, sizeof(t_vec4));
	obj->indices = anew(NULL, 0, sizeof(int));
	obj = read_file(fd, obj);
	if (obj->indices.len != 0)
		obj->vertices_final = vertice_to_final(obj->vertices, obj->indices);
	else
		obj->vertices_final = obj->vertices;
	return (obj);
}