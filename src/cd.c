/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgaspari <sgaspari@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/21 17:49:22 by sgaspari          #+#    #+#             */
/*   Updated: 2025/09/10 14:06:52 by sgaspari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "built_in.h"
#include "cmds.h"
#include "data.h"
#include "libft.h"
#include "list.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

static int	handle_abs_path(char *s);
static int	handle_rel_path(char *s);
static void	update_wd(t_node *list);

int	cd(t_cmd *cmd)
{
	if (cmd->argv[1] == NULL)
		;
	else if (cmd->argv[1][0] == '/')
	{
		if (handle_abs_path(cmd->argv[1]) == 1)
			return (1);
	}
	else
	{
		if (handle_rel_path(cmd->argv[1]) == 1)
			return (1);
	}
	update_wd(cmd->data->envp);
	return (0);
}

static int	handle_abs_path(char *s)
{
	if (chdir(s) == -1)
	{
		perror("chdir");
		return (1);
	}
	return (0);
}

static int	handle_rel_path(char *s)
{
	char	*tmp;
	char	*cwd;
	char	*nd;

	cwd = getcwd(NULL, 0);
	if (cwd == NULL)
	{
		perror("getcwd");
		return (1);
	}
	tmp = cwd;
	cwd = ft_strjoin(cwd, "/");
	free(tmp);
	nd = ft_strjoin(cwd, s);
	if (chdir(nd) == -1)
	{
		perror("chdir");
		return (1);
	}
	if (cwd != NULL)
		free(cwd);
	if (nd != NULL)
		free(nd);
	return (0);
}

static void	update_wd(t_node *list)
{
	t_node	*node;
	char	*key;
	char	*cwd;
	char	*new_pwd;

	key = ft_strdup("PWD=");
	delete_node(&list, key, ft_strlen(key));
	cwd = getcwd(NULL, 0);
	new_pwd = ft_strjoin(key, cwd);
	free(key);
	free(cwd);
	node = create_node(new_pwd);
	append_node(&list, node);
	free(new_pwd);
}
