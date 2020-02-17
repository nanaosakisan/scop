/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iporsenn <iporsenn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/11 14:42:56 by iporsenn          #+#    #+#             */
/*   Updated: 2020/02/17 14:33:06 by iporsenn         ###   ########.fr       */
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
        glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
        glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 1);
        glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
        glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
        window = glfwCreateWindow(HEIGHT, WIDTH, "ft_scop", NULL, NULL);
        if (!window)
        {
            error_callback("Failed to open window");
            glfwTerminate();
            return -1;
        }
        glfwMakeContextCurrent(window);
        gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);
        glfwSetInputMode(window, GLFW_STICKY_KEYS, GL_TRUE);
       	GLuint program_id = glCreateProgram();
        program_id = load_shaders(program_id, GL_VERTEX_SHADER, "./shaders/vertex_shader.glsl");
        program_id = load_shaders(program_id, GL_FRAGMENT_SHADER, "./shaders/fragment_shader.glsl");

        glClearColor(0.0f, 0.0f, 0.4f, 0.0f);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        while (!glfwWindowShouldClose(window) 
            && glfwGetKey(window, GLFW_KEY_ESCAPE) != GLFW_PRESS)
        {
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
