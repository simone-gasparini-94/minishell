/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_trim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgaspari <sgaspari@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/05 14:10:53 by sgaspari          #+#    #+#             */
/*   Updated: 2025/09/15 14:48:43 by sgaspari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "token.h"
#include "ft_fprintf.h"
#include <unistd.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

static size_t	get_len(t_tok *token, size_t len);
static char		*copy_unquoted(t_tok *token, size_t len);
static char		*copy_trimmed(t_tok *token, size_t len);

void	trim_spaces(t_tok *token)
{
	char	*s;
	size_t	len;

	len = get_len(token, (size_t)ft_strlen(token->s));
	s = copy_trimmed(token, len);
	if (s == NULL)
	{
		perror("malloc");
		return ;
	}
	free(token->s);
	token->s = s;
}

static size_t	get_len(t_tok *token, size_t len)
{
	size_t	i;
	size_t	j;
	size_t	new_len;

	new_len = len;
	i = 0;
	while (token->s[i] == ' ')
	{
		i++;
		new_len--;
	}
	j = 0;
	while (token->s[len - 1] == ' ')
	{
		j++;
		new_len--;
		len--;
	}
	return (new_len);
}

static char	*copy_trimmed(t_tok *token, size_t len)
{
	char	*s;
	size_t	i;
	size_t	j;

	i = 0;
	s = malloc(len + 1);
	if (s == NULL)
		return (NULL);
	while (token->s[i] == ' ')
		i++;
	j = 0;
	while (j < len)
	{
		s[j] = token->s[i + j];
		j++;
	}
	s[j] = '\0';
	return (s);
}

void	trim_quotes(t_tok *token)
{
	char	*s;
	size_t	len;

	len = (size_t)ft_strlen(token->s);
	if ((token->s[0] == '"' && token->s[len - 1] == '"') || (token->s[0] == '\''
			&& token->s[len - 1] == '\''))
	{
		if (token->s[0] == '\'' && token->s[len - 1] == '\'')
			token->quote = true;
		if (token->s[0] == '"' && token->s[len - 1] == '"')
			token->dquote = true;
		len -= 2;
		s = copy_unquoted(token, len);
		if (s == NULL)
		{
			perror("malloc");
			return ;
		}
		free(token->s);
		token->s = s;
	}
}

static char	*copy_unquoted(t_tok *token, size_t len)
{
	size_t	i;
	char	*s;

	s = malloc(len + 1);
	if (s == NULL)
		return (NULL);
	i = 0;
	while (i < len)
	{
		s[i] = token->s[i + 1];
		i++;
	}
	s[i] = '\0';
	return (s);
}
