/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgaspari <sgaspari@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/05 13:37:52 by sgaspari          #+#    #+#             */
/*   Updated: 2025/09/30 13:22:37 by sgaspari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "built_in.h"
#include "cmds.h"
#include "data.h"
#include "libft.h"
#include "list.h"
#include "utils.h"
#include <stdbool.h>
#include <stdlib.h>

static void	modify_shell_name(t_data *data);
static void	modify_shell_lvl(t_data *data);
static void	increase_level(t_data *data, t_node *curr, char *key);

t_data	*create_data(char **envp)
{
	t_data	*data;

	data = malloc(sizeof(t_data));
	if (data == NULL)
		return (NULL);
	data->envp = create_list(envp);
	data->built_ins = create_built_ins();
	data->ret_val = 0;
	modify_shell_name(data);
	modify_shell_lvl(data);
	return (data);
}

static void	modify_shell_name(t_data *data)
{
	t_node	*curr;
	t_node	*node;

	node = NULL;
	curr = data->envp;
	while (curr != NULL)
	{
		if (ft_strncmp(curr->s, "SHELL=", ft_strlen("SHELL=")) == 0)
		{
			delete_node(&data->envp, "SHELL=", ft_strlen("SHELL="));
			node = create_node("SHELL=minishell");
			append_node(&data->envp, node);
			return ;
		}
		curr = curr->next;
	}
}

static void	modify_shell_lvl(t_data *data)
{
	t_node	*curr;

	curr = data->envp;
	while (curr != NULL)
	{
		if (ft_strncmp(curr->s, "SHLVL=", ft_strlen("SHLVL=")) == 0)
		{
			increase_level(data, curr, "SHLVL=");
			return ;
		}
		curr = curr->next;
	}
}

static void	increase_level(t_data *data, t_node *curr, char *key)
{
	char	*new_level;
	char	*new_shlvl;
	size_t	level;
	t_node	*node;

	node = NULL;
	level = ft_atoi(curr->s + 6);
	level++;
	new_level = ft_itoa(level);
	new_shlvl = ft_strjoin(key, new_level);
	free(new_level);
	delete_node(&data->envp, key, ft_strlen(key));
	node = create_node(new_shlvl);
	free(new_shlvl);
	append_node(&data->envp, node);
}
