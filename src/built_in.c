/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   built_in.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgaspari <sgaspari@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/22 11:00:31 by sgaspari          #+#    #+#             */
/*   Updated: 2025/09/09 17:26:55 by sgaspari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "built_in.h"
#include "cmds.h"
#include "data.h"
#include "libft.h"
#include "macros.h"
#include "signals.h"
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

char	**create_built_ins(void)
{
	char	**arr;

	arr = malloc(sizeof(char *) * (NUM_BUILT_INS + 1));
	if (arr == NULL)
		return (NULL);
	arr[ECHO] = ft_strdup("echo");
	arr[CD] = ft_strdup("cd");
	arr[PWD] = ft_strdup("pwd");
	arr[EXPORT] = ft_strdup("export");
	arr[UNSET] = ft_strdup("unset");
	arr[ENV] = ft_strdup("env");
	arr[EXIT] = ft_strdup("exit");
	arr[NUM_BUILT_INS] = NULL;
	return (arr);
}

void	handle_built_in(t_data *data, t_cmd *cmd)
{
	data->ret_val = 0;
	if (ft_strncmp(cmd->argv[0], data->built_ins[ECHO], ft_strlen(cmd->argv[0])
			+ 1) == 0)
		echo(cmd);
	if (ft_strncmp(cmd->argv[0], data->built_ins[CD], ft_strlen(cmd->argv[0])
			+ 1) == 0)
		data->ret_val = cd(cmd);
	if (ft_strncmp(cmd->argv[0], data->built_ins[PWD], ft_strlen(cmd->argv[0])
			+ 1) == 0)
		pwd(cmd);
	if (ft_strncmp(cmd->argv[0], data->built_ins[EXPORT],
			ft_strlen(cmd->argv[0]) + 1) == 0)
		ft_export(cmd);
	if (ft_strncmp(cmd->argv[0], data->built_ins[UNSET], ft_strlen(cmd->argv[0])
			+ 1) == 0)
		unset(cmd);
	if (ft_strncmp(cmd->argv[0], data->built_ins[ENV], ft_strlen(cmd->argv[0])
			+ 1) == 0)
		env(cmd);
	if (ft_strncmp(cmd->argv[0], data->built_ins[EXIT], ft_strlen(cmd->argv[0])
			+ 1) == 0)
		ft_exit(data, cmd);
}

bool	cmd_is_built_in(char *s, char **built_ins)
{
	size_t	i;

	if (s == NULL)
		return (false);
	i = 0;
	while (built_ins[i] != NULL)
	{
		if (ft_strncmp(s, built_ins[i], ft_strlen(s) + 1) == 0)
			return (true);
		i++;
	}
	return (false);
}
