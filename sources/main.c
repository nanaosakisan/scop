/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iporsenn <iporsenn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/11 14:42:56 by iporsenn          #+#    #+#             */
/*   Updated: 2020/03/15 13:36:30 by iporsenn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_scop.h>

void	clean(t_env *env, t_obj *obj, t_matrice *matrice)
{
	glDeleteVertexArrays(1, &obj->vao);
	glDeleteBuffers(1, &obj->vbo);
	glDeleteBuffers(1, &obj->ebo);
	glfwDestroyWindow(env->window);
	free(obj->vertices.memory);
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

int		main(int ac, char **av)
{
	t_env		*env;
	t_obj		*obj;
	t_matrice	*matrice;


	if (ac == 2 && av[1])
	{

		obj = parsing(av[1]);
		matrice = init_matrice();
		obj->vertices_final = anew(NULL, 1, sizeof(t_vec4));
		obj->vertices_final = translation(obj->vertices, matrice->translation,\
			obj->vertices_final);
		env = init();
		env->program_id = load_shaders();
		obj = init_obj(obj);
		while (!glfwWindowShouldClose(env->window) 
			&& glfwGetKey(env->window, GLFW_KEY_ESCAPE) != GLFW_PRESS)
		{
			matrice->translation = update_translation(matrice->translation,
				*env);
			obj->vertices_final = translation(obj->vertices,\
				matrice->translation, obj->vertices_final);
			draw(*env, *obj);
		}
		clean(env, obj, matrice);
	}
	else
		error_callback("Usage", "./ft_scope file.obj");
	return (0);
}

// for (int i = 0; i < obj->vertices.len; i++)
// 	printf("vec.x: %f, vec.y: %f\n", (*(t_vec4*)anth(&obj->vertices_final,\
// 		i)).x, (*(t_vec4*)anth(&obj->vertices_final, i)).y);
