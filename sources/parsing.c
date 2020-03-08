/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iporsenn <iporsenn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/21 16:41:30 by iporsenn          #+#    #+#             */
/*   Updated: 2020/03/08 15:41:05 by iporsenn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_scop.h"

static t_array	parse_vertice(char **split, t_array vertices)
{
	t_vec4 vec;

	vec.x = (float)ft_atof(split[1]);
	vec.y = (float)ft_atof(split[2]);
	vec.z = (float)ft_atof(split[3]);
	apush(&vertices, &vec);

	return (vertices);
}

static t_array	parse_indice(char **split, t_array indices)
{
	int	i;
	int	push;

	i = 1;
	while (split[i])
	{
		if (split[i])
		{
			push = ft_atoi(split[i]);
			apush(&indices, &push);
		}
		i++;
	}
	return (indices);
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
			obj->indices = parse_indice(split, obj->indices);
		ft_strdel(&line);
		free(split);
	}
	return (obj);
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
	obj->vertices = anew(NULL, 1, sizeof(t_vec3));
	obj->indices = anew(NULL, 1, sizeof(int));
	obj = read_file(fd, obj);
	return (obj);
}