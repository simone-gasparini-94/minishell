/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgaspari <sgaspari@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/05 13:29:38 by sgaspari          #+#    #+#             */
/*   Updated: 2025/09/25 15:45:28 by sgaspari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DATA_H
# define DATA_H
# define READ 0
# define WRITE 1

# include <stdio.h>
# include <stdbool.h>

typedef struct s_cmd	t_cmd;
typedef struct s_tok	t_tok;
typedef struct s_node	t_node;

typedef struct s_data
{
	t_tok				**tokens;
	t_cmd				**cmds;
	t_node				*envp;
	char				**built_ins;
	int					(*pipfd)[2];
	size_t				n_cmds;
	size_t				n_tokens;
	size_t				n_bins;
	int					ret_val;
}						t_data;

t_data					*create_data(char **envp);

#endif
