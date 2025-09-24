/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgaspari <sgaspari@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/23 12:48:38 by sgaspari          #+#    #+#             */
/*   Updated: 2025/09/24 11:54:59 by sgaspari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "built_in.h"
#include "cmds.h"
#include "data.h"
#include "ft_fprintf.h"
#include "list.h"
#include "libft.h"
#include <stdbool.h>
#include <stdio.h>
#include <unistd.h>

static bool is_parameter_name_invalid(char *s);
static bool	is_var_dup(char *s, t_node *list);
static int	find_equal(char *s);

void	ft_export(t_cmd *p)
{
	t_node	*node;
	size_t	i;

	if (p->argv[1] == NULL)
		env(p);
	i = 1;
	while (p->argv[i] != NULL)
	{
		if (is_parameter_name_invalid(p->argv[i]) == true)
		{
			ft_fprintf(STDERR_FILENO,
					"export: %s: invalid parameter name\n", p->argv[i]);
			p->data->ret_val = 1;
		}
		else if (ft_strchr(p->argv[i], '=') == NULL)
			;
		else
		{
			if (is_var_dup(p->argv[i], p->data->envp) == true)
				delete_node(&p->data->envp, p->argv[i], find_equal(p->argv[i]));
			node = create_node(p->argv[i]);
			append_node(&p->data->envp, node);
		}
		i++;
	}
}

static bool is_parameter_name_invalid(char *s)
{
	size_t	i;

	if (s[0] == '=' || ft_isdigit(s[0]))
		return (true);
	i = 0;
	while (s[i] != '=' && s[i] != '\0')
	{
		if (!(ft_isalnum(s[i]) || s[i] == '_'))
			return (true);
		i++;
	}
	return (false);
}

static bool	is_var_dup(char *s, t_node *list)
{
	t_node	*curr;
	int		len;

	curr = list;
	len = find_equal(s);
	if (len == -1)
		return (false);
	while (curr != NULL)
	{
		if (ft_strncmp(curr->s, s, len) == 0)
		{
			return (true);
		}
		curr = curr->next;
	}
	return (false);
}

static int	find_equal(char *s)
{
	int	len;

	len = 0;
	while (s[len] != '\0')
	{
		if (s[len] == '=')
			return (len);
		len++;
	}
	return (-1);
}
