/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iporsenn <iporsenn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/11 14:42:56 by iporsenn          #+#    #+#             */
/*   Updated: 2020/02/21 14:13:57 by iporsenn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_scop.h"

void    error_callback(const char *error, const char *description)
{
    ft_putstr(error);
    ft_putstr(": ");
    ft_putendl(description);
}

int     main(int ac, char **av)
{
    t_env   *env;
    t_obj   *triangle;

    if (ac > 0 && av[0])
    {
        env = init();
        env->program_id = load_shaders();
        triangle = init_triangle_obj();
        while (!glfwWindowShouldClose(env->window) 
            && glfwGetKey(env->window, GLFW_KEY_ESCAPE) != GLFW_PRESS)
        {
            first_draw(env->program_id, *triangle);
            /* Swap front and back buffers */
            glfwSwapBuffers(env->window);

            /* Poll for and process events */
            glfwPollEvents();
     
        }

        glDeleteVertexArrays(1, &triangle->vao);
        glDeleteBuffers(1, &triangle->vbo);
        glfwDestroyWindow(env->window);
        free(env);
        glfwTerminate();
    }
    return (0);
}
