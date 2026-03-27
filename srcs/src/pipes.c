/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipes.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgaspari <sgaspari@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/26 13:23:59 by sgaspari          #+#    #+#             */
/*   Updated: 2025/09/10 13:23:45 by sgaspari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cmds.h"
#include "data.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

static int	allocate_pipes(t_data *data);
static int	initiate_pipes(t_data *data);
static void	connect_pipes(t_data *data);

int	create_pipes(t_data *data)
{
	if (allocate_pipes(data) == 1)
		return (1);
	if (initiate_pipes(data) == 1)
		return (1);
	connect_pipes(data);
	return (0);
}

static int	allocate_pipes(t_data *data)
{
	if (data->n_cmds > 1)
	{
		data->pipfd = malloc((data->n_cmds - 1) * sizeof(int [2]));
		if (!data->pipfd)
		{
			perror("malloc");
			return (1);
		}
	}
	else
		data->pipfd = NULL;
	return (0);
}

static int	initiate_pipes(t_data *data)
{
	size_t	i;

	i = 0;
	if (data->pipfd != NULL)
	{
		while (i < data->n_cmds - 1)
		{
			if (pipe(data->pipfd[i++]) == -1)
			{
				perror("pipe");
				return (1);
			}
		}
	}
	return (0);
}

static void	connect_pipes(t_data *data)
{
	size_t	i;

	i = 0;
	while (i < data->n_cmds)
	{
		if (i == 0)
			;
		else
			data->cmds[i]->in_fd = data->pipfd[i - 1][READ];
		if (i == data->n_cmds - 1)
			;
		else
			data->cmds[i]->out_fd = data->pipfd[i][WRITE];
		i++;
	}
}
