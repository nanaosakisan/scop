/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iporsenn <iporsenn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/11 14:42:56 by iporsenn          #+#    #+#             */
/*   Updated: 2020/05/09 16:15:48 by iporsenn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_scop.h>

void	clean(t_env *env, t_obj *obj, t_mvp *matrice)
{
	glDeleteVertexArrays(1, &obj->vao);
	glDeleteBuffers(1, &obj->vbo);
	glfwDestroyWindow(env->window);
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

int		main(int ac, char **av)
{
	static t_env	*env;
	t_obj			*obj;
	t_mvp			*matrice;

	if (ac == 2 && av[1])
	{
		obj = parsing(av[1]);
		env = init_env();
		matrice = init_matrice(*env);
		get_error();
		obj = init_obj(obj);
		while (!glfwWindowShouldClose(env->window))
		{
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