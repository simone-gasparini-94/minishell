/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fprint_character.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgaspari <sgaspari@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/25 13:59:02 by sgaspari          #+#    #+#             */
/*   Updated: 2025/07/31 11:08:05 by sgaspari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_fprint_character(int fd, int n)
{
	int		length;
	char	ch;

	length = 1;
	ch = (char) n;
	write(fd, &ch, length);
	return (length);
}
