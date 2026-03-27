/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgaspari <sgaspari@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 13:48:21 by sgaspari          #+#    #+#             */
/*   Updated: 2025/05/26 15:16:41 by sgaspari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>
#include <stdlib.h>
#include "libft.h"

static int	ft_get_length(int n);

char	*ft_itoa(int n)
{
	long		abs_value;
	int			str_length;
	char		*digits;

	str_length = ft_get_length(n);
	abs_value = n;
	digits = (char *) malloc(str_length + 1);
	if (!digits)
		return (NULL);
	if (n < 0)
	{
		digits[0] = '-';
		abs_value *= -1;
	}
	digits[str_length--] = '\0';
	digits[str_length--] = (abs_value % 10) + '0';
	abs_value /= 10;
	while (abs_value)
	{
		digits[str_length--] = (abs_value % 10) + '0';
		abs_value /= 10;
	}
	return (digits);
}

static int	ft_get_length(int n)
{
	int	length;
	int	i;

	length = 0;
	if (n <= 0)
		length++;
	i = n;
	while (i)
	{
		length++;
		i /= 10;
	}
	return (length);
}
