/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fprint_address.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgaspari <sgaspari@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/25 13:55:54 by sgaspari          #+#    #+#             */
/*   Updated: 2025/07/31 11:07:38 by sgaspari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdint.h>
#include "ft_fprintf_internal.h"

int	ft_fprint_address(int fd, void *p)
{
	uintptr_t	n;

	n = (uintptr_t) p;
	if (!p)
		return (ft_fprint_string(fd, "(nil)"));
	return (ft_fprint_string(fd, "0x") + ft_fprint_lower_hexadecimal(fd, n));
}
