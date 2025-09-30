/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgaspari <sgaspari@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 14:24:25 by sgaspari          #+#    #+#             */
/*   Updated: 2025/09/30 17:29:12 by sgaspari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cmds.h"
#include "data.h"
#include "execute.h"
#include "libft.h"
#include "token.h"
#include "signals.h"
#include <readline/readline.h>
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
	if (pid == 0)
	{
		g_flag = 1;
		close(fd[READ]);
		run_child_process(c, fd);
	}
	else
	{
		close(fd[WRITE]);
		g_flag = 0;
		waitpid(pid, &status, 0);
		c->data->ret_val = get_return_val(status);
		if (c->data->ret_val == 130 || c->data->ret_val == 131)
			c->data->heredoc_killed = true;
	}
}

static void	run_child_process(t_cmd *c, int *fd)
{
	char	*line;
	
	signal(SIGINT, SIG_DFL);
	signal(SIGQUIT, SIG_DFL);
	while (1)
	{
		line = readline("> ");
		if (line == NULL)
			break ;
		if (ft_strncmp(line, c->delimiter, ft_strlen(c->delimiter)) == 0)
		{
			free(line);
			break ;
		}
		write(fd[WRITE], line, ft_strlen(line));
		write(fd[WRITE], "\n", 1);
		free(line);
	}
	close(fd[WRITE]);
	exit(EXIT_SUCCESS);
}
