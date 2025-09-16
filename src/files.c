/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   files.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgaspari <sgaspari@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/09 11:30:58 by sgaspari          #+#    #+#             */
/*   Updated: 2025/09/09 14:21:11 by sgaspari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "token.h"
#include "files.h"
#include "ft_fprintf.h"
#include <stdbool.h>
#include <unistd.h>

static int	handle_input(t_tok *token);
static int	handle_output(t_tok *token);
static int	handle_heredoc(t_tok *token);
static int	handle_append(t_tok *token);

int	check_files(t_tok **tokens, int i)
{
	if (tokens[i - 1]->input_operator == true)
		return (handle_input(tokens[i]));
	else if (tokens[i - 1]->output_operator == true)
		return (handle_output(tokens[i]));
	else if (tokens[i - 1]->heredoc_operator == true)
		return (handle_heredoc(tokens[i]));
	else if (tokens[i - 1]->append_operator == true)
		return (handle_append(tokens[i]));
	return (0);
}

static int	handle_input(t_tok *token)
{
	if (token->string == false)
	{
		ft_fprintf(STDERR_FILENO, "syntax error\n");
		return (1);
	}
	else
	{
		token->string = false;
		token->input_file = true;
	}
	return (0);
}

static int	handle_output(t_tok *token)
{
	if (token->string == false)
	{
		ft_fprintf(STDERR_FILENO, "syntax error\n");
		return (1);
	}
	else
	{
		token->string = false;
		token->output_file = true;
	}
	return (0);
}

static int	handle_heredoc(t_tok *token)
{
	if (token->string == false)
	{
		ft_fprintf(STDERR_FILENO, "syntax error\n");
		return (1);
	}
	else
	{
		token->string = false;
		token->heredoc_delimiter = true;
	}
	return (0);
}

static int	handle_append(t_tok *token)
{
	if (token->string == false)
	{
		ft_fprintf(STDERR_FILENO, "syntax error\n");
		return (1);
	}
	else
	{
		token->string = false;
		token->append_file = true;
	}
	return (0);
}
