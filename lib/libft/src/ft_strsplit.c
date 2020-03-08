/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iporsenn <iporsenn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/03 13:48:42 by iporsenn          #+#    #+#             */
/*   Updated: 2020/03/07 15:40:01 by iporsenn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

static char	*replace_c(char *line, char c, int len)
{
	int i;

	i = 0;
	while (i < len)
	{
		if (line[i] == c)
			line[i] = '\0';
		i++;
	}
	return (line);
}

static char	**fill_array(char **split, char *line, int len)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (i < len)
	{
		if (line[i] != '\0' && (i == 0 || line[i - 1] == '\0'))
		{
			split[j] = line + i * sizeof(char);
			j++;
		}
		i++;
	}
	return (split);
}

char		**ft_strsplit(const char *str, char c)
{
	char	*line;
	char	**split;
	int		len;
	int		word;

	if (!str || !c)
		return (NULL);
	line = ft_strdup(str);
	len = ft_strlen(line);
	word = count_word(line, c);
	line = replace_c(line, c, len);
	if (!(split = (char **)malloc(word * sizeof(char *) + 1)))
		return (NULL);
	split[word] = NULL;
	return (fill_array(split, line, len));
}
