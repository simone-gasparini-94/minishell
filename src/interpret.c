/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   interpret.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgaspari <sgaspari@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/09 19:00:17 by sgaspari          #+#    #+#             */
/*   Updated: 2025/09/11 10:49:55 by sgaspari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "built_in.h"
#include "clean.h"
#include "cmds.h"
#include "data.h"
#include "execute.h"
#include "interpret.h"
#include "list.h"
#include "pipes.h"
#include "token.h"
#include <readline/history.h>
#include <readline/readline.h>
#include <stdio.h>
#include <stdlib.h>

static size_t	count_bins(t_data *data);

void	interpret(t_data *data, char *s)
{
	size_t	i;

	if (s == NULL)
		exit(EXIT_SUCCESS);
	i = 0;
	while (s[i] == ' ')
		i++;
	if (s[i] == '\0')
		;
	else
	{
		add_history(s);
		if (init(data, s) == 0)
		{
			execute(data->cmds, data);
		}
		destroy(data);
	}
}

int	init(t_data *data, char *s)
{
	data->tokens = NULL;
	data->cmds = NULL;
	data->pipfd = NULL;
	data->tokens = tokenize(data, s);
	if (data->tokens == NULL)
		return (1);
	data->cmds = create_cmds(data);
	if (data->cmds == NULL)
		return (1);
	data->n_bins = count_bins(data);
	if (create_pipes(data) == 1)
		return (1);
	return (0);
}

void	destroy(t_data *data)
{
	if (data->cmds != NULL)
		free_cmds(data->cmds, data->n_cmds);
	if (data->tokens != NULL)
		free_tokens(data->tokens, data);
	if (data->pipfd != NULL)
		free(data->pipfd);
}

static size_t	count_bins(t_data *data)
{
	size_t	i;
	size_t	bins;

	i = 0;
	bins = 0;
	while (i < data->n_cmds)
	{
		if (data->cmds[i]->argv[0] != NULL
			&& cmd_is_built_in(data->cmds[i]->argv[0],
				data->built_ins) == false)
			bins++;
		i++;
	}
	return (bins);
}
