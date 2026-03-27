/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgaspari <sgaspari@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/22 14:46:31 by sgaspari          #+#    #+#             */
/*   Updated: 2025/09/09 17:57:39 by sgaspari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "list.h"
#include "clean.h"
#include <stdlib.h>

t_node	*create_list(char **arr)
{
	t_node	*list;
	t_node	*node;
	size_t	i;

	list = NULL;
	i = 0;
	while (arr[i] != NULL)
	{
		node = create_node(arr[i]);
		if (node == NULL)
		{
			free_list(list);
			return (NULL);
		}
		append_node(&list, node);
		i++;
	}
	return (list);
}

t_node	*create_node(char *s)
{
	t_node	*node;

	node = malloc(sizeof(t_node));
	if (node == NULL)
		return (NULL);
	node->s = ft_strdup(s);
	node->next = NULL;
	return (node);
}

void	append_node(t_node **list, t_node *node)
{
	t_node	*last_node;

	if (*list == NULL)
		*list = node;
	else
	{
		last_node = find_last_node(*list);
		last_node->next = node;
	}
}

void	delete_node(t_node **list, char *s, int len)
{
	t_node	*curr;
	t_node	*prev;

	prev = *list;
	curr = prev->next;
	if (ft_strncmp(prev->s, s, len) == 0)
	{
		*list = curr;
		free(prev->s);
		free(prev);
		return ;
	}
	while (curr != NULL)
	{
		if (ft_strncmp(curr->s, s, len) == 0)
		{
			prev->next = curr->next;
			free(curr->s);
			free(curr);
			break ;
		}
		prev = curr;
		curr = curr->next;
	}
}

t_node	*find_last_node(t_node *list)
{
	t_node	*curr;

	curr = list;
	while (curr->next != NULL)
		curr = curr->next;
	return (curr);
}
