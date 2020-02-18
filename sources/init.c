/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iporsenn <iporsenn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/17 15:00:38 by iporsenn          #+#    #+#             */
/*   Updated: 2020/02/17 16:18:54 by iporsenn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_scop.h"

GLFWwindow    *init()
{
    GLFWwindow *window;
    
    if (!glfwInit())
    {
        error_callback("Failed to initialize GLFW");
        return (NULL);
    }
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 1);
    // glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    window = glfwCreateWindow(HEIGHT, WIDTH, "ft_scop", NULL, NULL);
    if (!window)
    {
        error_callback("Failed to open window");
        glfwTerminate();
        return (NULL);
    }
    glfwMakeContextCurrent(window);
    return window;
}