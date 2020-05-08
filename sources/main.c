/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iporsenn <iporsenn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/11 14:42:56 by iporsenn          #+#    #+#             */
/*   Updated: 2020/05/08 16:30:39 by iporsenn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_scop.h>

void	clean(t_env *env, t_obj *obj, t_matrice *matrice)
{
	glDeleteVertexArrays(1, &obj->vao);
	glDeleteBuffers(1, &obj->vbo);
	glfwDestroyWindow(env->window);
	// free(obj->vertices.memory);
	free(obj->vertices_final.memory);
	if (obj->indices.allocated != 0)
		free(obj->indices.memory);
	free(obj);
	free(matrice);
	free(env);
	glfwTerminate();
}

void	error_callback(const char *error, const char *description)
{
	ft_putstr(error);
	ft_putstr(": ");
	ft_putendl(description);
}

void	get_error()
{
	GLint	error;

	error = glGetError();
	if (error != GL_NO_ERROR)
	{
		printf("error : %d\n", error);
		error_callback("OPENGL", "Could not access uniforms.");
	}
}

static t_mat4	update_model(t_mat4 model, t_env env)
{
	if (glfwGetKey(env.window, GLFW_KEY_W) == GLFW_PRESS)
		model.y4 += 0.1;
	if (glfwGetKey(env.window, GLFW_KEY_S) == GLFW_PRESS)
		model.y4 -= 0.1;
	if (glfwGetKey(env.window, GLFW_KEY_A) == GLFW_PRESS)
		model.x4 -= 0.1;
	if (glfwGetKey(env.window, GLFW_KEY_D) == GLFW_PRESS)
		model.x4 += 0.1;
	return (model);
}

int		main(int ac, char **av)
{
	t_env		*env;
	t_obj		*obj;
	t_matrice	*matrice;

	if (ac == 2 && av[1])
	{
		env = init();
		obj = parsing(av[1]);
		matrice = init_matrice(*env);
		env->program_id = load_shaders();
		env->model_id = glGetUniformLocation(env->program_id, "model");
		env->view_id = glGetUniformLocation(env->program_id, "view");
		env->projection_id = glGetUniformLocation(env->program_id, "projection");
		get_error();
		obj = init_obj(obj);
		while (!glfwWindowShouldClose(env->window) 
			&& glfwGetKey(env->window, GLFW_KEY_ESCAPE) != GLFW_PRESS)
		{
			// update position et zoom;
			matrice->model = update_model(matrice->model, *env);
			draw(*env, *obj, *matrice);
		}
		clean(env, obj, matrice);
	}
	else
		error_callback("Usage", "./ft_scope file.obj");
	return (0);
}

// for (int i = 0; i < obj->vertices.len; i++)
// 			printf("vec.x: %f, vec.y: %f\n", (*(t_vec4*)anth(&obj->vertices_final,\
// 				i)).x, (*(t_vec4*)anth(&obj->vertices_final, i)).y);