/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fprint_string.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgaspari <sgaspari@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/25 14:02:51 by sgaspari          #+#    #+#             */
/*   Updated: 2025/07/31 11:08:57 by sgaspari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft.h"

int	ft_fprint_string(int fd, char *s)
{
	int	length;

	if (!s)
		s = "(null)";
	length = ft_strlen(s);
	write(fd, s, length);
	return (length);
}
