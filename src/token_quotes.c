/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_quotes.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgaspari <sgaspari@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/08 19:47:01 by sgaspari          #+#    #+#             */
/*   Updated: 2025/09/08 19:48:27 by sgaspari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>

void	toggle_quotes(char c, bool *in_quote, bool *in_dquote)
{
	if (c == '\'')
	{
		if (*in_quote == false && *in_dquote == false)
			*in_quote = true;
		else if (*in_quote == true && *in_dquote == false)
			*in_quote = false;
	}
	else if (c == '"')
	{
		if (*in_dquote == false && *in_quote == false)
			*in_dquote = true;
		else if (*in_dquote == true && *in_quote == false)
			*in_dquote = false;
	}
}
