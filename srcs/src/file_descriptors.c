/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_descriptors.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgaspari <sgaspari@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/26 13:46:10 by sgaspari          #+#    #+#             */
/*   Updated: 2025/09/30 14:31:34 by sgaspari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cmds.h"
#include "data.h"
#include "ft_fprintf.h"
#include "libft.h"
#include "files.h"
#include "token.h"
#include <errno.h>
#include <fcntl.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

static void	open_outfiles(t_cmd *c);

int	set_fds(t_cmd *c)
{
	if (c->in_file != NULL)
		c->in_fd = open(c->in_file, O_RDONLY);
	else if (c->delimiter != NULL)
		fork_heredoc(c);
	else
		c->in_fd = STDIN_FILENO;
	if (c->in_fd == -1)
	{
		ft_fprintf(STDERR_FILENO, "%s: %s\n", c->in_file, strerror(errno));
		c->data->ret_val = 1;
	}
	open_outfiles(c);
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

static void	open_outfiles(t_cmd *c)
{
	size_t	i;

	i = 0;
	if (c->n_out_fds == 0)
		c->out_fd = STDOUT_FILENO;
	while (i < (c->n_out_fds))
	{
		if (c->out_files[i].append == false)
			c->out_fd = open(c->out_files[i].name, O_WRONLY | O_CREAT | O_TRUNC,
					0644);
		else if (c->out_files[i].append == true)
			c->out_fd = open(c->out_files[i].name,
					O_WRONLY | O_CREAT | O_APPEND, 0644);
		if (c->out_fd == -1)
		{
			ft_fprintf(STDERR_FILENO, "%s: %s\n", c->out_files[i].name,
				strerror(errno));
			c->data->ret_val = 1;
		}
		if (i != c->n_out_fds - 1)
			close(c->out_fd);
		i++;
	}
}

void	count_and_alloc_outfiles(t_cmd *cmd, t_tok **tokens, size_t index)
{
	size_t	start_index;
	size_t	i;

	start_index = index;
	cmd->n_out_fds = 0;
	while (index < cmd->data->n_tokens && tokens[index]->pipe == false)
	{
		if (tokens[index]->append_file == true
			|| tokens[index]->output_file == true)
			cmd->n_out_fds++;
		index++;
	}
	cmd->out_files = malloc(sizeof(t_out) * cmd->n_out_fds);
	if (!cmd->out_files)
		return ;
	i = 0;
	while (start_index < cmd->data->n_tokens
		&& tokens[start_index]->pipe == false)
	{
		if (tokens[start_index]->output_file == true)
			cmd->out_files[i++].append = false;
		else if (tokens[start_index]->append_file == true)
			cmd->out_files[i++].append = true;
		start_index++;
	}
}
