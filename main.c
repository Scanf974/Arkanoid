/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsautron <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/02 05:47:03 by bsautron          #+#    #+#             */
/*   Updated: 2015/05/02 13:55:39 by bsautron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <arkanoid.h>

static void error_callback(int error, const char *description)
{
	ft_putendl_fd(description, 2);
}

static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
	if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
		glfwSetWindowShouldClose(window, GL_TRUE);

}

void		ft_render(t_env *env)
{
	glBegin(GL_QUADS);
	//glColor3f(1.f, 0.f, 0.f);
	glVertex2f(-0.5f, -0.9f);
	glVertex2f(0.5f, -0.9f);
	glVertex2f(0.5f, -0.95f);
	glVertex2f(-0.5f, -0.95f);
	glEnd();

}


void ft_ball(t_env *env)
{
	float DEG2RAD = 3.14159/180;
	glBegin(GL_LINE_LOOP);

	for (int i=0; i < 360; i++)
	{
		float degInRad = i*DEG2RAD;
		glVertex2f(cos(degInRad)*env->ball.radius, sin(degInRad)*env->ball.radius);
	}

	glEnd();
}

void		ft_rectangle(t_env *env, float x, float y)
{
	float	h;
	float	w;

	h = (float)env->height;
	w = (float)env->width;
	glBegin(GL_QUADS);
	glVertex2f(x + 0.2, y);
	glVertex2f(x, y);
	glVertex2f(x, y + 0.2);
	glVertex2f(x + 0.2, y + 0.2);
	glEnd();
}

int			main(void)
{
	GLFWwindow* window;
	GLuint		vs;
	t_env		env;

	env.ball.radius = 0.03;
	env.bar.h = 10;
	env.bar.w = 50;
	// glfwSetErrorCallback(error_callback);
	if (!glfwInit())
		exit(EXIT_FAILURE);
	window = glfwCreateWindow(640, 480, "Simple example", NULL, NULL);
	if (!window)
	{
		glfwTerminate();
		exit(EXIT_FAILURE);
	}
	glfwMakeContextCurrent(window);
	glfwSetKeyCallback(window, key_callback);
	while (!glfwWindowShouldClose(window))
	{
		float ratio;

		glfwGetFramebufferSize(window, &env.width, &env.height);
		ratio = env.width / (float) env.height;
		glViewport(0, 0, env.width, env.height);
		glClear(GL_COLOR_BUFFER_BIT);
		glMatrixMode(GL_PROJECTION);
		glLoadIdentity();
		glOrtho(-ratio, ratio, -1.f, 1.f, 1.f, -1.f);

		glMatrixMode(GL_MODELVIEW);
		glLoadIdentity();

		ft_render(&env);
		ft_ball(&env);
		ft_rectangle(&env, 0.5f, 0.6f);

		glfwSwapBuffers(window);
		glfwPollEvents();
	}
	glfwDestroyWindow(window);
	glfwTerminate();
	exit(EXIT_SUCCESS);
}
