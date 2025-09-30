/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgaspari <sgaspari@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 14:24:25 by sgaspari          #+#    #+#             */
/*   Updated: 2025/09/30 16:58:40 by sgaspari         ###   ########.fr       */
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

#define BUF_LEN 1024

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
	char	buf[BUF_LEN];
	char	*tmp;
	ssize_t	num_read;
	
	signal(SIGINT, SIG_DFL);
	signal(SIGQUIT, SIG_DFL);
	tmp = c->delimiter;
	c->delimiter = ft_strjoin(c->delimiter, "\n");
	free(tmp);
	while (1)
	{
		num_read = read(1, buf, BUF_LEN);
		if (num_read == -1)
		{
			perror("read");
			return ;
		}
		if (num_read == 0)
			break ;
		if (ft_strncmp(buf, c->delimiter, ft_strlen(c->delimiter)) == 0)
			break ;
		write(fd[WRITE], buf, num_read);
	}
	close(fd[WRITE]);
	exit(EXIT_SUCCESS);
}
