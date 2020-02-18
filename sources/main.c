/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iporsenn <iporsenn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/11 14:42:56 by iporsenn          #+#    #+#             */
/*   Updated: 2020/02/18 11:17:29 by iporsenn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_scop.h"

void    error_callback(const char *description)
{
    ft_putstr("Error: ");
    ft_putendl(description);
}

void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
    // make sure the viewport matches the new window dimensions; note that width and 
    // height will be significantly larger than specified on retina displays.
    glViewport(0, 0, width, height);
}

int     main(int ac, char **av)
{
    GLFWwindow *window;
    GLuint      program_id;
    float vertices[] = {
        -0.5f, -0.5f, 0.0f,
        0.5f, -0.5f, 0.0f,
        0.0f,  0.5f, 0.0f
    };

    if (ac > 0 && av[0])
    {
        if (!(window = init()))
        {
            error_callback("cannot create window.");
            return (0);
        }
        glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);
        gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);
        glfwSetInputMode(window, GLFW_STICKY_KEYS, GL_TRUE);
        program_id = load_shaders();

        unsigned int VBO, VAO;
        glGenVertexArrays(1, &VAO);
        glGenBuffers(1, &VBO);

        glBindVertexArray(VAO);
        glBindBuffer(GL_ARRAY_BUFFER, VBO);

        glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

        glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
        glEnableVertexAttribArray(0);

        glBindBuffer(GL_ARRAY_BUFFER, 0); 

        glBindVertexArray(0);       
        while (!glfwWindowShouldClose(window) 
            && glfwGetKey(window, GLFW_KEY_ESCAPE) != GLFW_PRESS)
        {
            glClearColor(0.0f, 0.0f, 0.4f, 0.0f);
            glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
             
            glUseProgram(program_id);
            glBindVertexArray(VAO);
            glDrawArrays(GL_TRIANGLES, 0, 3);

                 /* Swap front and back buffers */
            glfwSwapBuffers(window);

            /* Poll for and process events */
            glfwPollEvents();
     
        }

        glDeleteVertexArrays(1, &VAO);
        glDeleteBuffers(1, &VBO);
        glfwDestroyWindow(window);
        glfwTerminate();
    }
    return (0);
}
