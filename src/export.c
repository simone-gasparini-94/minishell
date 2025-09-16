/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgaspari <sgaspari@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/23 12:48:38 by sgaspari          #+#    #+#             */
/*   Updated: 2025/09/03 15:02:56 by sgaspari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cmds.h"
#include "data.h"
#include "list.h"
#include "libft.h"
#include <stdbool.h>
#include <stdio.h>

static bool	is_var_dup(char *s, t_node *list);
static int	find_equal(char *s);

void	ft_export(t_cmd *p)
{
	t_node	*node;

	if (is_var_dup(p->argv[1], p->data->envp) == true)
		delete_node(&p->data->envp, p->argv[1], find_equal(p->argv[1]));
	node = create_node(p->argv[1]);
	append_node(&p->data->envp, node);
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
