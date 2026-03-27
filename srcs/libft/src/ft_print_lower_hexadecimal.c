/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_lower_hexadecimal.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgaspari <sgaspari@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/06 12:40:51 by sgaspari          #+#    #+#             */
/*   Updated: 2025/07/31 11:10:33 by sgaspari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_internal.h"

int	ft_print_lower_hexadecimal(uintptr_t n)
{
	ft_write_lower_base_16(n);
	return (ft_get_length_hexadecimal(n));
}
