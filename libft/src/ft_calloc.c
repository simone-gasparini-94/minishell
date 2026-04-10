/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgaspari <sgaspari@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 18:16:24 by sgaspari          #+#    #+#             */
/*   Updated: 2025/05/26 15:16:19 by sgaspari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void			*void_p;
	unsigned char	*p;
	size_t			i;

	if (size != 0 && nmemb > ((size_t)-1) / size)
		return (NULL);
	void_p = (void *) malloc(nmemb * size);
	if (!void_p)
		return (NULL);
	p = (unsigned char *)void_p;
	i = 0;
	while (i < nmemb * size)
		p[i++] = 0;
	return (void_p);
}
