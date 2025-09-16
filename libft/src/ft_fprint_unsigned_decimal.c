/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fprint_unsigned_decimal.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgaspari <sgaspari@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/25 14:04:25 by sgaspari          #+#    #+#             */
/*   Updated: 2025/07/31 11:09:10 by sgaspari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_internal.h"
#include "ft_fprintf_internal.h"

int	ft_fprint_unsigned_decimal(int fd, unsigned int n)
{
	ft_fwrite_base_10(fd, n);
	return (ft_get_length_decimal(n));
}
