/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ashift.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iporsenn <iporsenn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/02 16:13:45 by iporsenn          #+#    #+#             */
/*   Updated: 2020/03/07 15:40:01 by iporsenn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void	*ashift(t_array *array)
{
	void	*ret;

	ret = anth(array, 0);
	array->first -= array->elem_size;
	array->len--;
	return (ret);
}
