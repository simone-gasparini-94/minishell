/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fprint_lower_hexadecimal.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgaspari <sgaspari@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/25 14:00:53 by sgaspari          #+#    #+#             */
/*   Updated: 2025/07/31 11:08:32 by sgaspari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_internal.h"
#include "ft_fprintf_internal.h"

int	ft_fprint_lower_hexadecimal(int fd, uintptr_t n)
{
	ft_fwrite_lower_base_16(fd, n);
	return (ft_get_length_hexadecimal(n));
}
