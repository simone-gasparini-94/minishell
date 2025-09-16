/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_descriptors.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgaspari <sgaspari@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/26 13:46:10 by sgaspari          #+#    #+#             */
/*   Updated: 2025/09/10 13:39:05 by sgaspari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cmds.h"
#include "data.h"
#include "ft_fprintf.h"
#include "get_next_line.h"
#include "libft.h"
#include <errno.h>
#include <fcntl.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

void	piping_heredoc(t_cmd *c);

int	set_fds(t_cmd *c)
{
	if (c->in_file != NULL)
		c->in_fd = open(c->in_file, O_RDONLY);
	else if (c->delimiter != NULL)
		piping_heredoc(c);
	else
		c->in_fd = STDIN_FILENO;
	if (c->in_fd == -1)
	{
		ft_fprintf(STDERR_FILENO, "%s: %s\n", c->in_file, strerror(errno));
		c->data->ret_val = 1;
		return (1);
	}
	if (c->out_file != NULL)
		c->out_fd = open(c->out_file, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	else if (c->append_file != NULL)
		c->out_fd = open(c->append_file, O_WRONLY | O_CREAT | O_APPEND, 0644);
	else
		c->out_fd = STDOUT_FILENO;
	if (c->out_fd == -1)
	{
		ft_fprintf(STDERR_FILENO, "%s: %s\n", c->out_file, strerror(errno));
		c->data->ret_val = 1;
	}
	return (0);
}

void	close_fds(t_cmd **cmds)
{
	size_t	i;

	i = 0;
	while (i < cmds[0]->data->n_cmds)
	{
		if (cmds[i]->in_fd > 2)
			close(cmds[i]->in_fd);
		if (cmds[i]->out_fd > 2)
			close(cmds[i]->out_fd);
		i++;
	}
}

void	piping_heredoc(t_cmd *c)
{
	int		fd[2];
	char	*line;
	char	*tmp;

	if (pipe(fd) == -1)
		exit(1);
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
	c->in_fd = fd[READ];
}
