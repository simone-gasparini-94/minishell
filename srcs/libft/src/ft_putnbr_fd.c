/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgaspari <sgaspari@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 12:16:36 by sgaspari          #+#    #+#             */
/*   Updated: 2025/05/29 13:39:53 by sgaspari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include "libft.h"

#define INT_MIN -2147483648
#define STR_INT_MIN "-2147483648"
#define INT_MIN_LEN 11

void	ft_putnbr_fd(int n, int fd)
{
	char	digit;
	char	mod;
	int		div;

	if (n == INT_MIN)
		write(fd, STR_INT_MIN, INT_MIN_LEN);
	else if (n < 0)
	{
		write(fd, "-", 1);
		ft_putnbr_fd(-n, fd);
	}
	else if (n >= 0 && n <= 9)
	{
		digit = n + '0';
		write(fd, &digit, 1);
	}
	else if (n > 9)
	{
		div = n / 10;
		mod = n % 10 + '0';
		ft_putnbr_fd(div, fd);
		write(fd, &mod, 1);
	}
}
