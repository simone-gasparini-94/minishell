/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: duccello <duccello@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/24 17:08:42 by duccello          #+#    #+#             */
/*   Updated: 2025/09/16 09:56:19 by sgaspari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "built_in.h"
#include "cmds.h"
#include "data.h"
#include "libft.h"
#include "list.h"
#include "token.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

int	char_counter(char *input, char c)
{
	int	i;
	int	amount;

	i = 0;
	amount = 0;
	while (input[i])
	{
		if (input[i] == c)
			amount++;
		i++;
	}
	return (amount);
}

char	**create_array(t_node *envp)
{
	char	**arr;
	t_node	*curr;
	int		len;
	int		i;

	len = 0;
	curr = envp;
	while (curr != NULL)
	{
		len++;
		curr = curr->next;
	}
	arr = malloc(sizeof(char *) * (len + 1));
	if (arr == NULL)
		return (NULL);
	curr = envp;
	i = 0;
	while (curr != NULL)
	{
		arr[i++] = ft_strdup(curr->s);
		curr = curr->next;
	}
	arr[i] = NULL;
	return (arr);
}

int	find_equal(char *s)
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

size_t	find_len(char *str, char c)
{
	size_t	i;
	size_t	len;

	i = 0;
	len = 0;
	while (str[i] != '\0' && str[i] != c)
		i++;
	if (str[i] == c)
		i++;
	while (str[i] != '\0' && (ft_isalnum(str[i]) || str[i] == '_'))
	{
		i++;
		len++;
	}
	return (len);
}

char	*ft_getenv(t_tok *token, char *key)
{
	char	*s;
	t_node	*curr;
	int		len_list;
	int		len_key;

	s = NULL;
	len_key = ft_strlen(key);
	curr = token->data->envp;
	while (curr != NULL)
	{
		len_list = find_equal(curr->s);
		if (ft_strncmp(curr->s, key, len_key) == 0 && len_key == len_list)
			s = ft_strdup(&(curr->s[len_list + 1]));
		curr = curr->next;
	}
	return (s);
}
