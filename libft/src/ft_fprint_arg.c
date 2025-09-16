/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fprint_arg.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgaspari <sgaspari@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/25 13:57:00 by sgaspari          #+#    #+#             */
/*   Updated: 2025/07/31 11:07:52 by sgaspari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fprintf_internal.h"

int	ft_fprint_arg(int fd, char c, va_list args)
{
	int	length;

	length = 0;
	if (c == 'c')
		length += ft_fprint_character(fd, va_arg(args, int));
	else if (c == 's')
		length += ft_fprint_string(fd, va_arg(args, char *));
	else if (c == 'p')
		length += ft_fprint_address(fd, va_arg(args, void *));
	else if (c == 'd' || c == 'i')
		length += ft_fprint_decimal(fd, va_arg(args, int));
	else if (c == 'u')
		length += ft_fprint_unsigned_decimal(fd, va_arg(args, unsigned int));
	else if (c == 'x')
		length += ft_fprint_lower_hexadecimal(fd, va_arg(args, unsigned int));
	else if (c == 'X')
		length += ft_fprint_upper_hexadecimal(fd, va_arg(args, unsigned int));
	else if (c == '%')
		length += ft_fprint_percent_sign(fd);
	return (length);
}
