/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   anew.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iporsenn <iporsenn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 11:10:24 by iporsenn          #+#    #+#             */
/*   Updated: 2020/03/07 15:39:54 by iporsenn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

t_array		anew(void *first, size_t len, size_t elem_size)
{
	t_array	array;

	if (first == NULL && len != 0)
		array.memory = (void *)malloc(len * elem_size);
	else
		array.memory = first;
	array.first = array.memory;
	if (first == NULL)
		array.len = 0;
	else
		array.len = len;
	array.allocated = len;
	array.elem_size = elem_size;
	return (array);
}
