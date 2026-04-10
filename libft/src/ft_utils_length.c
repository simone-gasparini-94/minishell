/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_length.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgaspari <sgaspari@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/12 13:37:41 by sgaspari          #+#    #+#             */
/*   Updated: 2025/07/31 11:16:06 by sgaspari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdint.h>

int	ft_get_length_decimal(unsigned int n)
{
	int	length;

	length = 0;
	if (n == 0)
		length++;
	while (n)
	{
		length++;
		n /= 10;
	}
	return (length);
}

int	ft_get_length_hexadecimal(uintptr_t n)
{
	int	length;

	length = 0;
	if (n == 0)
		length++;
	while (n)
	{
		length++;
		n /= 16;
	}
	return (length);
}
