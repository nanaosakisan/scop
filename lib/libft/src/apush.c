/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apush.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iporsenn <iporsenn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 11:17:33 by iporsenn          #+#    #+#             */
/*   Updated: 2020/02/28 15:18:17 by iporsenn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

t_array     *apush(t_array *array, void *elem)
{
    void    *new_array;
    size_t  before;
    size_t  after;

    if (!array || !elem)
        return (NULL);
    before = array->first - array->memory;
    after = (array->allocated - array->len) * array->elem_size - before ;
    if (after >= array->elem_size)
    {
        ft_memmove(array->first + array->len * array->elem_size, elem,
            array->elem_size);
        array->len++;
    }
    else if (before >= array->elem_size)
    {
        ft_memmove(array->first - array->elem_size, array->first, array->len
            * array->elem_size);
        array->first -= array->elem_size;
        ft_memmove(array->first + array->len * array->elem_size, elem,
            array->elem_size);
        array->len++;
    }
    else
    {   
        if (!(new_array = (void *)malloc((array->allocated + 1)
            * array->elem_size)))
            return (NULL);
        ft_memmove(new_array, array->memory, array->allocated * array->elem_size);
        ft_memmove(new_array + array->allocated * array->elem_size, elem,
            array->elem_size);
        free(array->memory);
        array->memory = new_array;
        array->first = array->memory;
        array->len++;
        array->allocated++;
    }
    return (array);
}