/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iporsenn <iporsenn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/22 15:57:35 by iporsenn          #+#    #+#             */
/*   Updated: 2020/03/07 15:40:01 by iporsenn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char	*ft_strjoin(char const *s1, char const *s2)
{
	char *dest;

	if (!s1 || !s2)
		return (NULL);
	if (!(dest = ft_strnew(ft_strlen((char*)s1) + ft_strlen((char*)s2))))
		return (NULL);
	dest = ft_strcat(dest, s1);
	dest = ft_strcat(dest, s2);
	return (dest);
}
