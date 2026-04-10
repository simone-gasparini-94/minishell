/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fprintf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgaspari <sgaspari@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/25 13:38:54 by sgaspari          #+#    #+#             */
/*   Updated: 2025/07/31 11:09:33 by sgaspari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "ft_fprintf_internal.h"

int	ft_fprintf(int fd, const char *s, ...)
{
	va_list	args;
	int		f_length;

	f_length = 0;
	va_start(args, s);
	while (*s)
	{
		if (*s == '%')
			f_length += ft_fprint_arg(fd, *(++s), args);
		else
		{
			write(fd, s, 1);
			f_length++;
		}
		s++;
	}
	va_end(args);
	return (f_length);
}
