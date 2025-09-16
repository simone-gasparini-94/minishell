/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fprintf_internal.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgaspari <sgaspari@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/25 14:07:32 by sgaspari          #+#    #+#             */
/*   Updated: 2025/07/31 11:21:48 by sgaspari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_FPRINTF_INTERNAL_H
# define FT_FPRINTF_INTERNAL_H

# include <stdint.h>
# include <stdarg.h>

int		ft_fprint_arg(int fd, char s, va_list args);
int		ft_fprint_character(int fd, int ch);
int		ft_fprint_string(int fd, char *s);
int		ft_fprint_address(int fd, void *p);
int		ft_fprint_decimal(int fd, int n);
int		ft_fprint_unsigned_decimal(int fd, unsigned int n);
int		ft_fprint_lower_hexadecimal(int fd, uintptr_t n);
int		ft_fprint_upper_hexadecimal(int fd, uintptr_t n);
int		ft_fprint_percent_sign(int fd);
void	ft_fwrite_base_10(int fd, unsigned int n);
void	ft_fwrite_lower_base_16(int fd, uintptr_t n);
void	ft_fwrite_upper_base_16(int fd, uintptr_t n);

#endif
