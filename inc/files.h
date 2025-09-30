/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   files.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgaspari <sgaspari@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/05 14:38:45 by sgaspari          #+#    #+#             */
/*   Updated: 2025/09/30 14:31:20 by sgaspari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILES_H
# define FILES_H

# include <sys/types.h>

typedef struct s_tok	t_tok;
typedef struct s_cmd	t_cmd;
typedef struct s_out	t_out;

int						check_files(t_tok **tokens, int i);
int						set_fds(t_cmd *c);
void					fork_heredoc(t_cmd *c);
void					close_fds(t_cmd **cmds);
void					count_and_alloc_outfiles(t_cmd *cmd, t_tok **tokens,
							size_t index);

#endif
