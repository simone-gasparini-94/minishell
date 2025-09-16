/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgaspari <sgaspari@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 12:05:56 by sgaspari          #+#    #+#             */
/*   Updated: 2025/05/26 15:12:38 by sgaspari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "libft.h"

#define TRUE 1
#define FALSE 0

static void	find_limits(size_t *start, size_t *end,
				const char *s, const char *set);
static int	is_in_set(const char ch, const char *set);

char	*ft_strtrim(const char *s, const char *set)
{
	char	*trimmed_str;
	size_t	i;
	size_t	start;
	size_t	end;
	size_t	len;

	if (!s || !set)
		return (NULL);
	find_limits(&start, &end, s, set);
	if (start > end)
		return (ft_strdup(""));
	len = end - start + 1;
	trimmed_str = (char *)malloc(len + 1);
	if (!trimmed_str)
		return (NULL);
	i = 0;
	while (i < len)
	{
		trimmed_str[i] = s[i + start];
		i++;
	}
	trimmed_str[i] = '\0';
	return (trimmed_str);
}

static void	find_limits(size_t *start, size_t *end,
				const char *s, const char *set)
{
	size_t	len;

	*start = 0;
	len = ft_strlen(s);
	if (len == 0)
		*end = len;
	else
		*end = len - 1;
	while (*start <= *end && is_in_set(s[*start], set))
		(*start)++;
	while (*end >= *start && is_in_set(s[*end], set))
		(*end)--;
}

static int	is_in_set(const char ch, const char *set)
{
	while (*set)
		if (ch == *set++)
			return (TRUE);
	return (FALSE);
}
