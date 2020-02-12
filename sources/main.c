/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iporsenn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/11 14:42:56 by iporsenn          #+#    #+#             */
/*   Updated: 2019/11/11 14:42:59 by iporsenn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_scop.h"

void    error_callback(const char *description)
{
    ft_putstr("Error: ");
    ft_putendl(description);
}

int     main(int ac, char **av)
{
    GLFWwindow *window;

    if (ac > 0 && av[0])
    {
        if (!glfwInit())
        {
            error_callback("Failed to initialize GLFW");
            return -1;
        }
        window = glfwCreateWindow(HEIGHT, WIDTH, "ft_scop", NULL, NULL);
        if (!window)
        {
            error_callback("Failed to open window");
            glfwTerminate();
            return -1;
        }
        glfwMakeContextCurrent(window);
        glfwSetInputMode(window, GLFW_STICKY_KEYS, GL_TRUE);
        while (!glfwWindowShouldClose(window) 
            && glfwGetKey(window, GLFW_KEY_ESCAPE) != GLFW_PRESS)
        {
            // first_draw();

            /* Swap front and back buffers */
            glfwSwapBuffers(window);

            /* Poll for and process events */
            glfwPollEvents();
        }
        glfwDestroyWindow(window);
        glfwTerminate();
    }
    return (0);
}
