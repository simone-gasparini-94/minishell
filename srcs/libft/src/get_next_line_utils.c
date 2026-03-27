/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgaspari <sgaspari@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 15:39:20 by sgaspari          #+#    #+#             */
/*   Updated: 2025/07/31 11:19:18 by sgaspari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "get_next_line_internal.h"

bool	is_new_line_in_str(const char *s)
{
	char	c;

	c = '\n';
	while (*s)
	{
		if (c == *s)
			return (true);
		s++;
	}
	return (false);
}

char	*initialize_buffer(void)
{
	char	*buffer;

	buffer = (char *) malloc(1);
	if (!buffer)
		return (NULL);
	buffer[0] = '\0';
	return (buffer);
}

void	*free_buffer(char **buffer)
{
	free(*buffer);
	*buffer = NULL;
	return (NULL);
}
