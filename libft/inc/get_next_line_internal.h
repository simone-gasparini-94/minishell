/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_internal.h                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgaspari <sgaspari@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 13:34:14 by sgaspari          #+#    #+#             */
/*   Updated: 2025/07/31 11:21:33 by sgaspari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_INTERNAL_H
# define GET_NEXT_LINE_INTERNAL_H

# include <stdbool.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 4
# endif

char	*initialize_buffer(void);
bool	is_new_line_in_str(const char *s);
void	*free_buffer(char **buffer);

#endif
