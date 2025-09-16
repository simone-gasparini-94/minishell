/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_address.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgaspari <sgaspari@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/06 13:20:39 by sgaspari          #+#    #+#             */
/*   Updated: 2025/07/31 11:09:44 by sgaspari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_internal.h"

int	ft_print_address(void *p)
{
	uintptr_t	n;

	n = (uintptr_t) p;
	if (!p)
		return (ft_print_string("(nil)"));
	return (ft_print_string("0x") + ft_print_lower_hexadecimal(n));
}
