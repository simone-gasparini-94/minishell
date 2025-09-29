/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgaspari <sgaspari@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/26 15:06:26 by sgaspari          #+#    #+#             */
/*   Updated: 2025/09/04 16:21:23 by sgaspari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

typedef struct s_data	t_data;
typedef struct s_node	t_node;

int						char_counter(char *input, char c);
char					**create_array(t_node *envp);
int						find_equal(char *s);
size_t					find_len(char *str, char c);
char					*ft_getenv(t_data *data, char *key);

#endif
