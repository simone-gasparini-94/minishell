/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgaspari <sgaspari@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 14:24:25 by sgaspari          #+#    #+#             */
/*   Updated: 2025/09/30 15:01:17 by sgaspari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cmds.h"
#include "data.h"
#include "execute.h"
#include "libft.h"
#include "token.h"
#include "get_next_line.h"
#include "signals.h"
#include <sys/wait.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

static void	run_child_process(t_cmd *c, int *fd); 

void	fork_heredoc(t_cmd *c)
{
	int		fd[2];
	int		pid;
	int		status;

	status = 0;
	if (pipe(fd) == -1)
		exit(1);
	c->in_fd = fd[READ];
	pid = fork();
	if (pid == -1)
	{
		perror("fork");
		return ;
	}
	else if (pid == 0)
		run_child_process(c, fd);
	else
	{
		g_flag = 0;
		waitpid(pid, &status, 0);
		c->data->ret_val = get_return_val(status);
		if (c->data->ret_val == 130 || c->data->ret_val == 131)
			c->data->heredoc_killed = true;
	}
}

static void	run_child_process(t_cmd *c, int *fd);
{
	char	line;
	char	*tmp;
	
	signal(SIGINT, SIG_DFL);
	signal(SIGQUIT, SIG_DFL);
	line = get_next_line(STDIN_FILENO);
	tmp = c->delimiter;
	c->delimiter = ft_strjoin(c->delimiter, "\n");
	free(tmp);
	while (line && ft_strncmp(line, c->delimiter, ft_strlen(c->delimiter)) != 0)
	{
		write(fd[WRITE], line, ft_strlen(line));
		free(line);
		line = get_next_line(STDIN_FILENO);
	}
	free(line);
	close(fd[WRITE]);
	exit(EXIT_SUCCESS);
}
