/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operators.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgaspari <sgaspari@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/05 14:37:56 by sgaspari          #+#    #+#             */
/*   Updated: 2025/09/09 11:40:59 by sgaspari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "operators.h"
#include "ft_fprintf.h"
#include "libft.h"
#include "token.h"
#include <stdbool.h>
#include <unistd.h>

void	check_operators(t_tok *token)
{
	if (token->quote == true || token->dquote == true)
		token->string = true;
	else if (ft_strncmp(token->s, "<<", 3) == 0)
		token->heredoc_operator = true;
	else if (ft_strncmp(token->s, ">>", 3) == 0)
		token->append_operator = true;
	else if (ft_strncmp(token->s, "<", 2) == 0)
		token->input_operator = true;
	else if (ft_strncmp(token->s, ">", 2) == 0)
		token->output_operator = true;
	else if (ft_strncmp(token->s, "|", 2) == 0)
		token->pipe = true;
	else
		token->string = true;
}
