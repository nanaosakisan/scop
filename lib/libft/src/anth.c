/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   anth.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iporsenn <iporsenn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 15:45:13 by iporsenn          #+#    #+#             */
/*   Updated: 2020/02/25 06:20:06 by iporsenn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

void    *anth(t_array *array, int id)
{
    if (array == NULL)
        return (NULL);
    if (id < (int)array->len)
        return (array->first + id * array->elem_size);
    else
        return (NULL);
} 