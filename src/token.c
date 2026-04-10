/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgaspari <sgaspari@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/05 13:43:50 by sgaspari          #+#    #+#             */
/*   Updated: 2025/09/15 15:08:15 by sgaspari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "clean.h"
#include "data.h"
#include "expand.h"
#include "files.h"
#include "ft_fprintf.h"
#include "libft.h"
#include "operators.h"
#include "token.h"
#include <readline/readline.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

static char	*set_and_count(t_data *data, char *input);

t_tok	**tokenize(t_data *data, char *input)
{
	t_tok	**tokens;
	char	*tracker;

	if (input == NULL)
		return (NULL);
	tracker = set_and_count(data, input);
	if (tracker == NULL)
		return (NULL);
	tokens = malloc(sizeof(t_tok *) * (data->n_tokens));
	if (tokens == NULL)
	{
		free(tracker);
		return (NULL);
	}
	if (create_tokens(data, tokens, tracker, input) == 1)
	{
		data->ret_val = 1;
		free(tracker);
		free_tokens(tokens, data);
		return (NULL);
	}
	free(tracker);
	return (tokens);
}

static char	*set_and_count(t_data *data, char *input)
{
	char	*tracker;
	size_t	i;

	tracker = ft_strdup(input);
	i = 0;
	while (tracker[i] != '\0')
		tracker[i++] = '-';
	data->n_tokens = count_tokens(data, input, tracker);
	if (data->n_tokens == 0)
	{
		free(tracker);
		return (NULL);
	}
	return (tracker);
}

int	create_tokens(t_data *data, t_tok **tokens, char *tracker, char *input)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (i < data->n_tokens)
	{
		tokens[i] = populate_token(input, tracker, &j);
		init_token(tokens[i], data);
		trim_spaces(tokens[i]);
		trim_quotes(tokens[i]);
		expand(tokens[i]);
		check_operators(tokens[i]);
		i++;
	}
	if (tokens[data->n_tokens - 1]->string == false)
	{
		ft_fprintf(STDERR_FILENO, "syntax error\n");
		return (1);
	}
	i = 1;
	while (i < data->n_tokens)
		if (check_files(tokens, i++) == 1)
			return (1);
	return (0);
}

t_tok	*populate_token(char *input, char *tracker, size_t *j)
{
	t_tok	*token;
	size_t	start;
	size_t	len;

	len = 0;
	token = malloc(sizeof(t_tok));
	if (token == NULL)
		return (NULL);
	while (tracker[*j] == '-')
		(*j)++;
	start = *j;
	if (tracker[*j] == '+')
	{
		(*j)++;
		len++;
		while (tracker[*j] != '\0' && tracker[*j] != '+')
		{
			(*j)++;
			len++;
		}
	}
	token->s = malloc(len + 2);
	ft_strlcpy(token->s, &input[start], len + 1);
	token->quote = false;
	return (token);
}

void	init_token(t_tok *token, t_data *data)
{
	token->data = data;
	token->quote = false;
	token->dquote = false;
	token->input_operator = false;
	token->input_file = false;
	token->output_operator = false;
	token->output_file = false;
	token->append_operator = false;
	token->append_file = false;
	token->heredoc_operator = false;
	token->heredoc_delimiter = false;
	token->pipe = false;
	token->string = false;
}
