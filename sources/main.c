/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iporsenn <iporsenn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/11 14:42:56 by iporsenn          #+#    #+#             */
/*   Updated: 2020/03/08 15:34:12 by iporsenn         ###   ########.fr       */
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
    t_obj   *test;
    
    if (ac == 2 && av[1])
    {

        test = parsing(av[1]);
        env = init();
        env->program_id = load_shaders();
        test = init_triangle_obj(test);
        while (!glfwWindowShouldClose(env->window) 
            && glfwGetKey(env->window, GLFW_KEY_ESCAPE) != GLFW_PRESS)
        {
            glClearColor(0.0f, 0.0f, 0.4f, 0.0f);
            glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
            draw(env->program_id, *test);
            /* Swap front and back buffers */
            glfwSwapBuffers(env->window);

            /* Poll for and process events */
            glfwPollEvents();
        }

        glDeleteVertexArrays(1, &test->vao);
        glDeleteBuffers(1, &test->vbo);
        glDeleteBuffers(1, &test->ebo);
        glfwDestroyWindow(env->window);
        free(env);
        glfwTerminate();
    }
    else
        error_callback("Usage", "./ft_scope file.obj");
    return (0);
}
