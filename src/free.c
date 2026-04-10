/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: duccello <duccello@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 18:25:11 by duccello          #+#    #+#             */
/*   Updated: 2025/09/29 18:25:13 by duccello         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "clean.h"
#include "cmds.h"
#include "data.h"
#include "list.h"
#include "token.h"
#include <stdlib.h>

void	free_array(char **c)
{
	int	i;

	if (c == NULL)
		return ;
	i = 0;
	while (c[i])
	{
		free(c[i]);
		c[i] = NULL;
		i++;
	}
	free(c);
	c = NULL;
}

void	free_cmds(t_cmd **c, size_t num)
{
	size_t	i;

	if (c == NULL)
		return ;
	i = 0;
	while (i < num)
	{
		if (c[i]->path != NULL)
			free(c[i]->path);
		if (c[i]->argv != NULL)
			free_array(c[i]->argv);
		if (c[i]->envp != NULL)
			free_array(c[i]->envp);
		if (c[i]->in_file != NULL)
			free(c[i]->in_file);
		if (c[i]->out_files != NULL)
			free_struct(c[i]);
		if (c[i]->delimiter != NULL)
			free(c[i]->delimiter);
		free(c[i++]);
	}
	free(c);
	c = NULL;
}

void	free_struct(t_cmd *cmd)
{
	size_t	i;

	i = 0;
	while (i < cmd->n_out_fds)
	{
		free(cmd->out_files[i].name);
		i++;
	}
	free(cmd->out_files);
}

void	free_list(t_node *list)
{
	t_node	*curr;
	t_node	*prev;

	prev = list;
	curr = prev->next;
	while (curr != NULL)
	{
		free(prev->s);
		free(prev);
		prev = curr;
		curr = curr->next;
	}
	free(prev->s);
	free(prev);
}

void	free_tokens(t_tok **tokens, t_data *data)
{
	size_t	i;

	i = 0;
	if (tokens != NULL)
	{
		while (i < data->n_tokens)
		{
			if (tokens[i]->s != NULL)
			{
				free(tokens[i]->s);
				tokens[i]->s = NULL;
			}
			if (tokens[i] != NULL)
				free(tokens[i]);
			i++;
		}
		free(tokens);
		tokens = NULL;
	}
}
