/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_arg.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgaspari <sgaspari@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/05 11:46:26 by sgaspari          #+#    #+#             */
/*   Updated: 2025/07/31 11:09:55 by sgaspari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_internal.h"

int	ft_print_arg(char c, va_list args)
{
	int	length;

	length = 0;
	if (c == 'c')
		length += ft_print_character(va_arg(args, int));
	else if (c == 's')
		length += ft_print_string(va_arg(args, char *));
	else if (c == 'p')
		length += ft_print_address(va_arg(args, void *));
	else if (c == 'd' || c == 'i')
		length += ft_print_decimal(va_arg(args, int));
	else if (c == 'u')
		length += ft_print_unsigned_decimal(va_arg(args, unsigned int));
	else if (c == 'x')
		length += ft_print_lower_hexadecimal(va_arg(args, unsigned int));
	else if (c == 'X')
		length += ft_print_upper_hexadecimal(va_arg(args, unsigned int));
	else if (c == '%')
		length += ft_print_percent_sign();
	return (length);
}
