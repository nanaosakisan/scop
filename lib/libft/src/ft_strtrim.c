/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iporsenn <iporsenn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/22 16:00:13 by iporsenn          #+#    #+#             */
/*   Updated: 2020/03/07 15:40:01 by iporsenn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char	*ft_strtrim(const char *s)
{
	char	*dest;
	size_t	len;

	if (!s)
		return (NULL);
	len = 0;
	while (*s == ' ' || *s == '\n' || *s == '\t')
		s++;
	len = ft_strlen(s) - 1;
	while (s[len] == ' ' || s[len] == '\n' || s[len] == '\t')
		len--;
	len += 1;
	if (ft_strlen(s) == 0)
		return (ft_strnew(1));
	else
		return (!(dest = ft_strsub(s, 0, len))) ? NULL : dest;
}
