/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_write.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgaspari <sgaspari@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/05 11:36:16 by sgaspari          #+#    #+#             */
/*   Updated: 2025/07/31 11:16:29 by sgaspari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdint.h>
#include <unistd.h>

#define BASE_10_SIZE 10
#define BASE_16_SIZE 16
#define LOWER_HEX "0123456789abcdef"
#define UPPER_HEX "0123456789ABCDEF"

void	ft_write_base_10(unsigned int n)
{
	char	digits[BASE_10_SIZE];
	int		i;

	if (n == 0)
	{
		write(1, "0", 1);
		return ;
	}
	i = 0;
	while (n)
	{
		digits[i++] = (n % 10) + '0';
		n /= 10;
	}
	while (--i >= 0)
		write(1, &digits[i], 1);
}

void	ft_write_lower_base_16(uintptr_t n)
{
	char	*hex;
	char	digits[BASE_16_SIZE];
	int		i;

	if (n == 0)
	{
		write(1, "0", 1);
		return ;
	}
	hex = LOWER_HEX;
	i = 0;
	while (n)
	{
		digits[i++] = hex[n % 16];
		n /= 16;
	}
	while (--i >= 0)
		write(1, &digits[i], 1);
}

void	ft_write_upper_base_16(uintptr_t n)
{
	char	*hex;
	char	digits[BASE_16_SIZE];
	int		i;

	if (n == 0)
	{
		write(1, "0", 1);
		return ;
	}
	hex = UPPER_HEX;
	i = 0;
	while (n)
	{
		digits[i++] = hex[n % 16];
		n /= 16;
	}
	while (--i >= 0)
		write(1, &digits[i], 1);
}
