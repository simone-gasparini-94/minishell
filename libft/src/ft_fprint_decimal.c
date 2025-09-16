/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fprint_decimal.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgaspari <sgaspari@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/25 13:59:48 by sgaspari          #+#    #+#             */
/*   Updated: 2025/07/31 11:08:16 by sgaspari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fprintf_internal.h"

int	ft_fprint_decimal(int fd, int n)
{
	long	abs_value;

	abs_value = n;
	if (n < 0)
	{
		abs_value = -abs_value;
		return (ft_fprint_character(fd, '-')
			+ ft_fprint_unsigned_decimal(fd, (unsigned int) abs_value));
	}
	return (ft_fprint_unsigned_decimal(fd, (unsigned int) abs_value));
}
