/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgaspari <sgaspari@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 16:42:01 by sgaspari          #+#    #+#             */
/*   Updated: 2025/05/23 13:26:51 by sgaspari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	ch;
	char	*p;

	if (!s)
		return (NULL);
	p = NULL;
	ch = (char) c;
	while (*s)
	{
		if (ch == *s)
			p = (char *) s;
		s++;
	}
	if (ch == *s)
		p = (char *) s;
	return (p);
}
