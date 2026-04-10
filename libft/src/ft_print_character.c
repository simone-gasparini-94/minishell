/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_character.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgaspari <sgaspari@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/05 12:38:03 by sgaspari          #+#    #+#             */
/*   Updated: 2025/07/31 11:10:05 by sgaspari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_print_character(int n)
{
	int		length;
	char	ch;

	length = 1;
	ch = (char) n;
	write(1, &ch, length);
	return (length);
}
