/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ainsert.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iporsenn <iporsenn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/25 07:08:54 by iporsenn          #+#    #+#             */
/*   Updated: 2020/02/28 16:35:30 by iporsenn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

t_array     *ainsert(t_array *array, void *elem)
{
    void    *new_array;
    size_t  before;
    size_t  after;

    if (!array || !elem)
        return (NULL);
    before = array->first - array->memory;
    after = (array->allocated - array->len) * array->elem_size - before ;
    printf("before: %ld, after: %ld, elem_size: %ld, len: %ld, allocated: %ld\n",
        before, after, array->elem_size, array->len, array->allocated);
    if (before >= array->elem_size)
    {
        printf("before\n");
        ft_memmove(array->first - array->elem_size, elem, array->elem_size);
        array->first -= array->elem_size;
        array->len++;
    }
    else if (after >= array->elem_size)
    {
        printf("after\n");
        ft_memmove(array->first + array->elem_size, array->first, array->len
            * array->elem_size);
        // array->first += array->elem_size;
        // printf("buh: %d\n", *(int *)anth(array, 0));
        ft_memmove(array->first, elem, array->elem_size);
        // array->first -= array->elem_size;
        array->len++;
    }
    else
    {   
        if (!(new_array = (void *)malloc((array->allocated + 1)
            * array->elem_size)))
            return (NULL);
        ft_memmove(new_array, elem, array->elem_size);
        ft_memmove(new_array + array->elem_size, array->memory,
            array->allocated * array->elem_size);
        free(array->memory);
        array->memory = new_array;
        array->first = array->memory;
        array->len++;
        array->allocated++;
    }
    return (array);
}