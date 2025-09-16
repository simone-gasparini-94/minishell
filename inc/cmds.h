/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmds.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgaspari <sgaspari@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/08 16:55:25 by sgaspari          #+#    #+#             */
/*   Updated: 2025/09/15 14:03:51 by sgaspari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CMDS_H
# define CMDS_H

# include <stdio.h>
# include <stdbool.h>

typedef struct s_data	t_data;
typedef struct s_tok	t_tok;
typedef struct s_node	t_node;
typedef struct s_cmd
{
	t_data				*data;
	t_tok				**tokens;
	char				**argv;
	char				**envp;
	char				*path;
	char				*in_file;
	char				*out_file;
	char				*append_file;
	char				*delimiter;
	int					in_fd;
	int					out_fd;
}						t_cmd;

t_cmd					**create_cmds(t_data *data);
size_t					count_cmds(t_tok **tokens, t_data *data);
t_cmd					*create_cmd(t_tok **tokens, t_data *data, size_t *i,
							size_t *j);
char					**create_argv(t_tok **tokens, t_data *data,
							size_t *index);
void					populate_cmd(t_cmd *cmd, t_tok **tokens, size_t *index);
bool					create_path(t_cmd *cmd);

#endif
