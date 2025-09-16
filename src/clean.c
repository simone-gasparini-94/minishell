/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: duccello <duccello@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/24 17:09:47 by duccello          #+#    #+#             */
/*   Updated: 2025/09/11 11:15:03 by sgaspari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
		if (c[i]->out_file != NULL)
			free(c[i]->out_file);
		if (c[i]->append_file != NULL)
			free(c[i]->append_file);
		if (c[i]->delimiter != NULL)
			free(c[i]->delimiter);
		free(c[i++]);
	}
	free(c);
	c = NULL;
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

void	free_data(t_data *data)
{
	if (data == NULL)
		return ;
	if (data->cmds != NULL)
		free_cmds(data->cmds, data->n_cmds);
	if (data->tokens != NULL)
		free_tokens(data->tokens, data);
	if (data->envp != NULL)
		free_list(data->envp);
	if (data->built_ins != NULL)
		free_array(data->built_ins);
	if (data->pipfd != NULL)
	{
		free(data->pipfd);
		data->pipfd = NULL;
	}
	free(data);
}
