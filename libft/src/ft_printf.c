/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgaspari <sgaspari@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 18:05:18 by sgaspari          #+#    #+#             */
/*   Updated: 2025/07/31 11:11:34 by sgaspari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "ft_printf_internal.h"

int	ft_printf(const char *s, ...)
{
	va_list	args;
	int		f_length;

	f_length = 0;
	va_start(args, s);
	while (*s)
	{
		if (*s == '%')
			f_length += ft_print_arg(*(++s), args);
		else
		{
			write(1, s, 1);
			f_length++;
		}
		s++;
	}
	va_end(args);
	return (f_length);
}
