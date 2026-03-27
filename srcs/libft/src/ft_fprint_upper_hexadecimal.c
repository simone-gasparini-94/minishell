/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fprint_upper_hexadecimal.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgaspari <sgaspari@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/25 14:05:16 by sgaspari          #+#    #+#             */
/*   Updated: 2025/07/31 11:14:44 by sgaspari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_internal.h"
#include "ft_fprintf_internal.h"

int	ft_fprint_upper_hexadecimal(int fd, uintptr_t n)
{
	ft_fwrite_upper_base_16(fd, n);
	return (ft_get_length_hexadecimal(n));
}
