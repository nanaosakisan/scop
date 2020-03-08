/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apop.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iporsenn <iporsenn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/02 15:52:03 by iporsenn          #+#    #+#             */
/*   Updated: 2020/03/07 15:40:01 by iporsenn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void	*apop(t_array *array)
{
	void	*ret;

	ret = anth(array, array->len - 1);
	array->len--;
	return (ret);
}
