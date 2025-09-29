/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bin.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgaspari <sgaspari@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/26 15:32:36 by sgaspari          #+#    #+#             */
/*   Updated: 2025/09/15 14:02:17 by sgaspari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bin.h"
#include "clean.h"
#include "data.h"
#include "ft_fprintf.h"
#include "signals.h"
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>
#include <unistd.h>

#define CMD_NOT_FOUND 127

static void	close_unused_child_pipes(t_data *data, int in_use, int out_use);

int	exec_binary(t_cmd *c)
{
	int	pid;

	if (c->path != NULL && access(c->path, X_OK) == 0)
		c->data->ret_val = 0;
	else 
		c->data->ret_val = 127;
	pid = fork();
	if (pid == 0)
		run_child_process(c);
	else
		g_flag = 1;
	return (pid);
}

void	run_child_process(t_cmd *c)
{
	signal(SIGINT, SIG_DFL);
	signal(SIGQUIT, SIG_DFL);
	close_unused_child_pipes(c->data, c->in_fd, c->out_fd);
	if (c->in_fd != STDIN_FILENO)
	{
		if (c->in_fd != -1)
		{
			dup2(c->in_fd, STDIN_FILENO);
			close(c->in_fd);
		}
	}
	if (c->out_fd != STDOUT_FILENO)
	{
		dup2(c->out_fd, STDOUT_FILENO);
		close(c->out_fd);
	}
	if (c->path != NULL && access(c->path, X_OK) == 0 && c->in_fd != -1)
		execve(c->path, c->argv, c->envp);
	free_data(c->data);
	exit(EXIT_FAILURE);
}

static void	close_unused_child_pipes(t_data *data, int in_use, int out_use)
{
	size_t	i;

	i = 0;
	while (i < data->n_cmds - 1)
	{
		if (data->pipfd[i][READ] != in_use && data->pipfd[i][READ] != out_use)
			close(data->pipfd[i][READ]);
		if (data->pipfd[i][WRITE] != in_use && data->pipfd[i][WRITE] != out_use)
			close(data->pipfd[i][WRITE]);
		i++;
	}
}
