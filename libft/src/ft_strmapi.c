/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgaspari <sgaspari@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 13:03:51 by sgaspari          #+#    #+#             */
/*   Updated: 2025/05/26 15:15:38 by sgaspari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strmapi(const char *s, char (*f)(unsigned int, char))
{
	char			*mapped_str;
	unsigned int	i;

	if (!s || !f)
		return (NULL);
	mapped_str = (char *) malloc(ft_strlen(s) + 1);
	if (!mapped_str)
		return (NULL);
	i = 0;
	while (s[i])
	{
		mapped_str[i] = (*f)(i, s[i]);
		i++;
	}
	mapped_str[i] = '\0';
	return (mapped_str);
}
