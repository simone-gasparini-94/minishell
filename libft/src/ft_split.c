/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgaspari <sgaspari@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 15:08:14 by sgaspari          #+#    #+#             */
/*   Updated: 2025/05/26 15:18:39 by sgaspari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "libft.h"

#define TRUE 1
#define FALSE 0

static int	ft_count_rows(const char *s, char c);
static char	*ft_populate(const char **s, char c);
static void	ft_free_all(char **s, int rows); 

char	**ft_split(const char *s, char c)
{
	char		**arr_of_str;
	int			i;
	int			rows;

	if (!s)
		return (NULL);
	rows = ft_count_rows(s, c);
	arr_of_str = (char **) ft_calloc(rows + 1, sizeof(char *));
	if (!arr_of_str)
		return (NULL);
	i = 0;
	while (i < rows)
	{
		arr_of_str[i] = ft_populate(&s, c);
		if (!arr_of_str[i])
		{
			ft_free_all(arr_of_str, i);
			return (NULL);
		}
		i++;
	}
	arr_of_str[rows] = NULL;
	return (arr_of_str);
}

static char	*ft_populate(const char **s, char c)
{
	int		len;
	char	*str;

	len = 0;
	while (c == **s && **s)
		(*s)++;
	while (c != **s && **s)
	{
		len++;
		(*s)++;
	}
	str = (char *) ft_calloc(len + 1, sizeof(char));
	if (!str)
		return (NULL);
	ft_strlcpy(str, *s - len, len + 1);
	return (str);
}

static int	ft_count_rows(const char *s, char c)
{
	int		rows;
	int		in_word;

	rows = 0;
	in_word = FALSE;
	while (*s)
	{
		if (c != *s && in_word == FALSE)
		{
			rows++;
			in_word = TRUE;
		}
		else if (c == *s && in_word == TRUE)
		{
			in_word = FALSE;
		}
		s++;
	}
	return (rows);
}

static void	ft_free_all(char **s, int rows)
{
	int		i;

	i = 0;
	while (i < rows)
		free(s[i++]);
	free(s);
}
