/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_internal.h                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgaspari <sgaspari@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 18:05:24 by sgaspari          #+#    #+#             */
/*   Updated: 2025/07/31 11:22:02 by sgaspari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_INTERNAL_H
# define FT_PRINTF_INTERNAL_H

# include <stdarg.h>
# include <stdint.h>

int		ft_print_arg(char s, va_list args);
int		ft_print_character(int ch);
int		ft_print_string(char *s);
int		ft_print_address(void *p);
int		ft_print_decimal(int n);
int		ft_print_unsigned_decimal(unsigned int n);
int		ft_print_lower_hexadecimal(uintptr_t n);
int		ft_print_upper_hexadecimal(uintptr_t n);
int		ft_print_percent_sign(void);
int		ft_get_length_decimal(unsigned int n);
int		ft_get_length_hexadecimal(uintptr_t n);
void	ft_write_base_10(unsigned int n);
void	ft_write_lower_base_16(uintptr_t n);
void	ft_write_upper_base_16(uintptr_t n);

#endif
