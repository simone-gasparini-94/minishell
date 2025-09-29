/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmds.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgaspari <sgaspari@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/08 16:53:24 by sgaspari          #+#    #+#             */
/*   Updated: 2025/09/10 12:15:58 by sgaspari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "clean.h"
#include "cmds.h"
#include "data.h"
#include "files.h"
#include "libft.h"
#include "token.h"
#include "utils.h"
#include <stdio.h>
#include <stdlib.h>

t_cmd	**create_cmds(t_data *data)
{
	t_cmd	**cmds;
	size_t	cmd_i;
	size_t	cre_i;
	size_t	pop_i;

	cre_i = 0;
	pop_i = 0;
	data->n_cmds = count_cmds(data->tokens, data);
	cmds = malloc(sizeof(t_cmd *) * data->n_cmds);
	if (cmds == NULL)
		return (NULL);
	cmd_i = 0;
	while (cmd_i < data->n_cmds)
	{
		cmds[cmd_i] = create_cmd(data->tokens, data, &cre_i, &pop_i);
		if (cmds[cmd_i] == NULL)
		{
			free_cmds(cmds, cmd_i);
			return (NULL);
		}
		cmd_i++;
	}
	return (cmds);
}

size_t	count_cmds(t_tok **tokens, t_data *data)
{
	size_t	counter;
	size_t	i;

	counter = 1;
	i = 0;
	while (i < data->n_tokens)
	{
		if (tokens[i]->pipe == true)
			counter++;
		i++;
	}
	return (counter);
}

t_cmd	*create_cmd(t_tok **tokens, t_data *data, size_t *i, size_t *j)
{
	t_cmd	*cmd;

	cmd = malloc(sizeof(t_cmd));
	if (cmd == NULL)
		return (NULL);
	cmd->data = data;
	cmd->argv = create_argv(tokens, data, i);
	cmd->in_file = NULL;
	cmd->out_files = NULL;
	cmd->delimiter = NULL;
	cmd->path = NULL;
	cmd->envp = create_array(data->envp);
	populate_cmd(cmd, tokens, j);
	if (set_fds(cmd) == 1)
		return (NULL);
	return (cmd);
}

char	**create_argv(t_tok **tokens, t_data *data, size_t *index)
{
	char	**argv;
	size_t	counter;

	counter = 0;
	if (tokens[*index]->pipe == true)
		(*index)++;
	while (*index < data->n_tokens && tokens[*index]->pipe == false)
	{
		if (tokens[*index]->string == true)
			counter++;
		(*index)++;
	}
	argv = malloc(sizeof(char *) * (counter + 1));
	if (argv == NULL)
		return (NULL);
	return (argv);
}

void	populate_cmd(t_cmd *cmd, t_tok **tokens, size_t *index)
{
	size_t	i;
	size_t	j;

	if (tokens[*index]->pipe == true)
		(*index)++;
	i = 0;
	j = 0;
	count_and_alloc_outfiles(cmd, tokens, *index);
	while (*index < cmd->data->n_tokens && tokens[*index]->pipe == false)
	{
		if (tokens[*index]->input_file == true)
			cmd->in_file = ft_strdup(tokens[*index]->s);
		else if (tokens[*index]->output_file == true
			|| tokens[*index]->append_file == true)
			cmd->out_files[j++].name = ft_strdup(tokens[*index]->s);
		else if (tokens[*index]->heredoc_delimiter == true)
			cmd->delimiter = ft_strdup(tokens[*index]->s);
		else if (tokens[*index]->string == true)
			cmd->argv[i++] = ft_strdup(tokens[*index]->s);
		(*index)++;
	}
	cmd->argv[i] = NULL;
}
