/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_string.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgaspari <sgaspari@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/05 12:52:50 by sgaspari          #+#    #+#             */
/*   Updated: 2025/07/31 11:11:01 by sgaspari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft.h"

int	ft_print_string(char *s)
{
	int	length;

	if (!s)
		s = "(null)";
	length = ft_strlen(s);
	write(1, s, length);
	return (length);
}
