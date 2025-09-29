/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgaspari <sgaspari@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/04 13:34:32 by sgaspari          #+#    #+#             */
/*   Updated: 2025/09/15 14:04:42 by sgaspari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cmds.h"
#include "data.h"
#include "libft.h"
#include "list.h"
#include "clean.h"
#include "ft_fprintf.h"
#include <errno.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>

static char	*path_start(t_node *envp);
static char	**parse_path(t_node *envp);
static char	*join_path(char *cmd, char **paths, t_cmd *c);

bool	create_path(t_cmd *cmd)
{
	char	*path;
	char	**paths;

	paths = parse_path(cmd->data->envp);
	if (paths == NULL)
	{
		ft_fprintf(STDERR_FILENO, "%s: path not found\n", cmd->argv[0]);
		cmd->data->ret_val = 127;
		return (false);
	}
	path = join_path(cmd->argv[0], paths, cmd);
	free_array(paths);
	cmd->path = path;
	return (true);
}

static char	*join_path(char *cmd, char **paths, t_cmd *c)
{
	char	*tmp;
	char	*full;
	int		i;

	(void)c;
	if (ft_strchr(cmd, '/') && access(cmd, X_OK) == 0)
		return (ft_strdup(cmd));
	i = 0;
	while (paths[i])
	{
		tmp = ft_strjoin(paths[i++], "/");
		full = ft_strjoin(tmp, cmd);
		free(tmp);
		if (access(full, X_OK) == 0)
			return (full);
		free(full);
	}
	ft_fprintf(STDERR_FILENO, "%s: command not found\n", cmd);
	return (NULL);
}

static char	**parse_path(t_node *envp)
{
	char	**paths;
	char	*start;

	start = path_start(envp);
	if (!start)
		return (NULL);
	paths = ft_split(start, ':');
	return (paths);
}

static char	*path_start(t_node *envp)
{
	t_node	*curr;

	curr = envp;
	while (curr != NULL)
	{
		if (ft_strncmp(curr->s, "PATH=", 5) == 0)
			return (curr->s + 5);
		curr = curr->next;
	}
	return (NULL);
}
