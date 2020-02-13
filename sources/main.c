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
        glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 2);
        glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 0);
        window = glfwCreateWindow(HEIGHT, WIDTH, "ft_scop", NULL, NULL);
        if (!window)
        {
            error_callback("Failed to open window");
            glfwTerminate();
            return -1;
        }
        glfwMakeContextCurrent(window);
        glfwSetInputMode(window, GLFW_STICKY_KEYS, GL_TRUE);
        load_shaders();

    //     // An array of 3 vectors which represents 3 vertices
    //     static const GLfloat g_vertex_buffer_data[] = {
    //     -1.0f, -1.0f, 0.0f,
    //     1.0f, -1.0f, 0.0f,
    //     0.0f,  1.0f, 0.0f,
    //     };
    //     // This will identify our vertex buffer
    //     GLuint vertexbuffer;
    //     // Generate 1 buffer, put the resulting identifier in vertexbuffer
    //     glGenBuffers(1, &vertexbuffer);
    //     // The following commands will talk about our 'vertexbuffer' buffer
    //     glBindBuffer(GL_ARRAY_BUFFER, vertexbuffer);
    //     // Give our vertices to OpenGL.
    //     glBufferData(GL_ARRAY_BUFFER, sizeof(g_vertex_buffer_data), g_vertex_buffer_data, GL_STATIC_DRAW);

    //     glEnableVertexAttribArray(0);
    //     glBindBuffer(GL_ARRAY_BUFFER, vertexbuffer);
    //     glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, (void*)0);
    //     // Draw the triangle !
    //     glDrawArrays(GL_TRIANGLES, 0, 3); // Starting from vertex 0; 3 vertices total -> 1 triangle
    //     glDisableVertexAttribArray(0);

    //     // while (!glfwWindowShouldClose(window) 
    //     //     && glfwGetKey(window, GLFW_KEY_ESCAPE) != GLFW_PRESS)
    //     // {
    //     //     // first_draw();

    //     //     /* Swap front and back buffers */
    //     //     glfwSwapBuffers(window);

    //     //     /* Poll for and process events */
    //     //     glfwPollEvents();
    //     // }
    //     glfwDestroyWindow(window);
    //     glfwTerminate();
    }
    return (0);
}
