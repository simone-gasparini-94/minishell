/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_decimal.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgaspari <sgaspari@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/05 13:21:16 by sgaspari          #+#    #+#             */
/*   Updated: 2025/07/31 11:10:16 by sgaspari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_internal.h"

int	ft_print_decimal(int n)
{
	long	abs_value;

	abs_value = n;
	if (n < 0)
	{
		abs_value = -abs_value;
		return (ft_print_character('-')
			+ ft_print_unsigned_decimal((unsigned int) abs_value));
	}
	return (ft_print_unsigned_decimal((unsigned int) abs_value));
}
