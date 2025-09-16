/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_upper_hexadecimal.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgaspari <sgaspari@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/06 13:14:23 by sgaspari          #+#    #+#             */
/*   Updated: 2025/07/31 11:11:21 by sgaspari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_internal.h"

int	ft_print_upper_hexadecimal(uintptr_t n)
{
	ft_write_upper_base_16(n);
	return (ft_get_length_hexadecimal(n));
}
