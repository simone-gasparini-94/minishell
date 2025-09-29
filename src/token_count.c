/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_count.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgaspari <sgaspari@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/09 11:06:34 by sgaspari          #+#    #+#             */
/*   Updated: 2025/09/15 14:54:35 by sgaspari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fprintf.h"
#include "libft.h"
#include "token.h"
#include "data.h"
#include <stdbool.h>
#include <unistd.h>

static int	find_new_token(char *s, bool *in_word, int *counter, char *c);
static void	handle_operator(bool *in_word, int *counter, char *c);
static void	handle_character(bool *in_word, int *counter, char *c);
static void	init_bools(bool *in_quote, bool *in_dquote, bool *in_word);

int	count_tokens(t_data *data, char *s, char *tracker)
{
	int		counter;
	bool	in_quote;
	bool	in_dquote;
	bool	in_word;
	int		i;

	init_bools(&in_quote, &in_dquote, &in_word);
	counter = 0;
	i = 0;
	while (s[i] == ' ')
		i++;
	while (s[i] != '\0' && tracker[i] != '\0')
	{
		if (in_quote == false && in_dquote == false)
			i += find_new_token(&s[i], &in_word, &counter, &tracker[i]);
		toggle_quotes(s[i++], &in_quote, &in_dquote);
	}
	if (in_quote == true || in_dquote == true)
	{
		ft_fprintf(STDERR_FILENO, "syntax error\n");
		data->ret_val = 1;
		return (0);
	}
	return (counter);
}

static void	init_bools(bool *in_quote, bool *in_dquote, bool *in_word)
{
	*in_quote = false;
	*in_dquote = false;
	*in_word = false;
}

static int	find_new_token(char *s, bool *in_word, int *counter, char *c)
{
	int	i;

	i = 0;
	if (ft_strncmp(s, ">>", 2) == 0 || ft_strncmp(s, "<<", 2) == 0)
	{
		handle_operator(in_word, counter, c);
		i++;
	}
	else if (*s == '>' || *s == '<' || *s == '|')
		handle_operator(in_word, counter, c);
	else if (*s != ' ' && *in_word == false)
		handle_character(in_word, counter, c);
	else if (*s == ' ' && *in_word == true)
		*in_word = false;
	return (i);
}

static void	handle_operator(bool *in_word, int *counter, char *c)
{
	*in_word = false;
	(*counter)++;
	*c = '+';
}

static void	handle_character(bool *in_word, int *counter, char *c)
{
	*in_word = true;
	(*counter)++;
	*c = '+';
}
