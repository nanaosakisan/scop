/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iporsenn <iporsenn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/21 16:41:30 by iporsenn          #+#    #+#             */
/*   Updated: 2020/02/21 16:42:12 by iporsenn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_scop.h"

t_obj		*parsing(char *path)
{
	t_obj	*obj;
	int		ret;
	int		fd;
	char	*line;
	char	**split;
	int		i;

	if (!(obj = (t_obj *)malloc(sizeof(t_obj))))
	{
		error_callback("PARSING", "object's malloc failed");
		return (NULL);
	}fd = 0;
	fd = open(path, fd, O_RDONLY);
	if (!fd)
	{
		error_callback("PARSING", "can't open file");
		return (NULL);
	}
	ret = 0;
	line = NULL;
	while ((ret = get_next_line(fd, &line) != 0))
	{
		printf("line: %s\n", line);
		split = ft_strsplit(line, ' ');
		if (ft_strequ(split[0], "v") == 1)
		{
			i = 1;
			obj->vertice = anew(NULL, 1, sizeof(float));
			while (split[i])
			{
				//need atoi for float (atof) ?
				apush(&obj->vertice, &split[i]);
				i++;
			}
		}
		i = 0;
		while (i < (int)obj->vertice.len)
		{
			printf("vertex: %f\n", *(float *)anth(obj->vertice.first, i));
			i++;
		}
		// while (split[i] != NULL)
		// {
		// 	printf("word: %s\n", split[i]);
		// 	i++;
		// }
		// ft_strdel(&line);
		// free(split);
	}
	return (obj);
}