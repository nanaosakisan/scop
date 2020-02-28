/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iporsenn <iporsenn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 13:20:21 by iporsenn          #+#    #+#             */
/*   Updated: 2020/02/28 16:32:15 by iporsenn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

void    clean_array(t_array *array)
{
    free(array->memory);
    array->allocated = 0;
    array->len = 0;
    array->elem_size = 0;
}

int     test_apush()
{
    t_array array;
    int     *test_no_memory;
    int     *test_after;
    int     *test_before;
    int     push;

    push = 2;
    test_no_memory = (int *)malloc(sizeof(int));
    test_no_memory[0] = 1;
    array = anew(test_no_memory, 1, sizeof(int));
    apush(&array, &push);
    if (*(int *)anth(&array, 0) != 1 || *(int *)anth(&array, 1) != 2)
        return (-1);
    clean_array(&array);
    test_after = (int *)malloc(2 * sizeof(int));
    test_after[0] = 1;
    array = anew(test_after, 1, sizeof(int));
    array.allocated = 2;
    apush(&array, &push);
    if (*(int *)anth(&array, 0) != 1 || *(int *)anth(&array, 1) != 2)
        return (-1);
    clean_array(&array);
    test_before = (int *)malloc(2 * sizeof(int));
    test_before[0] = 1;
    test_before[1] = 1;
    array = anew(test_before, 1, sizeof(int));
    array.allocated = 2;
    array.first += array.elem_size;
    apush(&array, &push);
    if (*(int *)anth(&array, 0) != 1 || *(int *)anth(&array, 1) != 2)
        return (-1);
    return (1);
}

int     test_ainsert()
{
    t_array array;
    int     *test_no_memory;
    int     *test_after;
    int     *test_before;
    int     push;

    push = 1;
    test_no_memory = (int *)malloc(sizeof(int));
    test_no_memory[0] = 2;
    array = anew(test_no_memory, 1, sizeof(int));
    ainsert(&array, &push);
    if (*(int *)anth(&array, 0) != 1 || *(int *)anth(&array, 1) != 2)
        return (-1);
    clean_array(&array);
    test_after = (int *)malloc(2 * sizeof(int));
    test_after[0] = 2;
    array = anew(test_after, 1, sizeof(int));
    array.allocated = 2;
    ainsert(&array, &push);
    printf("test 0: %d, test 1: %d\n", *(int *)anth(&array, 0), *(int *)anth(&array, 1));
    if (*(int *)anth(&array, 0) != 1 || *(int *)anth(&array, 1) != 2)
        return (-1);
    clean_array(&array);
    test_before = (int *)malloc(2 * sizeof(int));
    test_before[0] = 2;
    test_before[1] = 2;
    array = anew(test_before, 1, sizeof(int));
    array.allocated = 2;
    array.first += array.elem_size;
    ainsert(&array, &push);
    printf("test 0: %d, test 1: %d\n", *(int *)anth(&array, 0), *(int *)anth(&array, 1));
    if (*(int *)anth(&array, 0) != 1 || *(int *)anth(&array, 1) != 2)
        return (-1);
    return (1);
}

int     test_anew() 
{
    t_array array;
    int     *test;

    array = anew(NULL, 10, sizeof(int));
    if (array.allocated != 10 || array.len != 0 || array.elem_size != sizeof(int))
        return (-1);
    clean_array(&array);
    test = malloc(sizeof(int));
    test[0] = 2;
    array = anew(test, 1, sizeof(int));
    if (array.allocated != 1 || array.len != 1 || array.elem_size != sizeof(int)
        || *(int *)anth(&array, 0) != 2)
        return (-1);
    free(array.memory);
    return (1);
}

int     main(void)
{
    int     test;

    if ((test = test_anew()) == -1)
        printf("anew: fail\n");
    else
        printf("anew: success\n");
    if ((test = test_apush()) == -1)
        printf("apush: fail\n");
    else
        printf("apush: success\n");
    if ((test = test_ainsert()) == -1)
        printf("ainsert: fail\n");
    else
        printf("ainsert: success\n");
    return (0);
}