/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgaspari <sgaspari@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 14:06:13 by sgaspari          #+#    #+#             */
/*   Updated: 2025/05/23 12:13:49 by sgaspari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*temp_p;

	if (!b)
		return (NULL);
	temp_p = (unsigned char *) b;
	while (len--)
		*temp_p++ = (unsigned char) c;
	return (b);
}
