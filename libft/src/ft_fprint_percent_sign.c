/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fprint_percent_sign.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgaspari <sgaspari@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/25 14:02:17 by sgaspari          #+#    #+#             */
/*   Updated: 2025/07/31 11:08:42 by sgaspari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fprintf_internal.h"

int	ft_fprint_percent_sign(int fd)
{
	return (ft_fprint_character(fd, '%'));
}
