/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bin.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgaspari <sgaspari@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/26 15:34:49 by sgaspari          #+#    #+#             */
/*   Updated: 2025/09/04 13:16:20 by sgaspari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BIN_H
# define BIN_H

# include "cmds.h"

int		exec_binary(t_cmd *c);
void	run_child_process(t_cmd *c);
char	*join_path(char *cmd, char **paths, t_cmd *c);

#endif
