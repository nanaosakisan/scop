/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iporsenn <iporsenn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/17 15:00:38 by iporsenn          #+#    #+#             */
/*   Updated: 2020/02/21 14:11:13 by iporsenn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_scop.h"


void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
    // make sure the viewport matches the new window dimensions; note that width and 
    // height will be significantly larger than specified on retina displays.
    glViewport(0, 0, width, height);
}

t_obj   *init_triangle_obj()
{
    t_obj   *obj;
    // float   vertices[] = {
    //     -0.5f, -0.5f, 0.0f,
    //     0.5f, -0.5f, 0.0f,
    //     0.0f,  0.5f, 0.0f
    // };

    float vertices[] = {
        0.0f, 0.5f, 0.0f,
        -0.25f, 0.0f, 0.0f,
        0.25f, 0.0f, 0.0f,
        -0.5f, -0.5f, 0.0f,
        0.0f, -0.5f, 0.0f, 
        0.5f, -0.5f, 0.0f 
    };

    uint32_t indices[] = {
        0, 1 , 2,
        1, 3, 4,
        2, 4, 5
    };

    if(!(obj = (t_obj*)malloc(sizeof(t_obj))))
    {
        error_callback("MALLOC", "objetc's malloc failed.");
        return (NULL);
    }
    if (!(obj->vertices = (float *)malloc(9 * sizeof(float))))
    {
        error_callback("MALLOC", "vertice's malloca failed.");
        return (NULL);
    }
        glGenVertexArrays(1, &obj->vao);
        glGenBuffers(1, &obj->vbo);
        glGenBuffers(1, &obj->ebo);

        glBindVertexArray(obj->vao);
        glBindBuffer(GL_ARRAY_BUFFER, obj->vbo);
        glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, obj->ebo);
        glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW); 

        glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
        glEnableVertexAttribArray(0);

        glBindBuffer(GL_ARRAY_BUFFER, 0); 
        glBindVertexArray(0);  
    return (obj);
}

t_env   *init()
{
    t_env       *env;

    if (!(env = (t_env*)malloc(sizeof(env))))
    {
        error_callback("MALLOC", "environment's malloc failed.");
        return (NULL);
    }
    if (!glfwInit())
    {
        error_callback("GLFW", "Failed to initialize GLFW");
        return (NULL);
    }
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 1);
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    env->window = glfwCreateWindow(HEIGHT, WIDTH, "ft_scop", NULL, NULL);
    if (!env->window)
    {
        error_callback("WINDOW", "Failed to open window");
        glfwTerminate();
        return (NULL);
    }
    glfwMakeContextCurrent(env->window);
    glfwSetFramebufferSizeCallback(env->window, framebuffer_size_callback);
    gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);
    glfwSetInputMode(env->window, GLFW_STICKY_KEYS, GL_TRUE);
    return (env);
}