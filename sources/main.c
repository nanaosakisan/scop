/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iporsenn <iporsenn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/11 14:42:56 by iporsenn          #+#    #+#             */
/*   Updated: 2020/02/21 15:40:20 by iporsenn         ###   ########.fr       */
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
    // t_obj   *triangle;
    // t_obj   *triangle2;
    t_obj   *test;

    if (ac == 2 && av[1])
    {

        test = parsing(av[1]);
    //     env = init();
    //     env->program_id = load_shaders();
    //     triangle = init_triangle_obj();
    //     triangle2 = init_triangle_obj2();
    //     while (!glfwWindowShouldClose(env->window) 
    //         && glfwGetKey(env->window, GLFW_KEY_ESCAPE) != GLFW_PRESS)
    //     {
    //         glClearColor(0.0f, 0.0f, 0.4f, 0.0f);
    //         glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    //         first_draw(env->program_id, *triangle);
    //         first_draw(env->program_id, *triangle2);
    //         /* Swap front and back buffers */
    //         glfwSwapBuffers(env->window);

    //         /* Poll for and process events */
    //         glfwPollEvents();
     
    //     }

    //     glDeleteVertexArrays(1, &triangle->vao);
    //     glDeleteBuffers(1, &triangle->vbo);
    //     glfwDestroyWindow(env->window);
    //     free(env);
    //     glfwTerminate();
    }
    else
        error_callback("Usage", "./ft_scope file.obj");
    return (0);
}
