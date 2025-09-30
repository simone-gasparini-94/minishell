/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgaspari <sgaspari@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/26 15:37:40 by sgaspari          #+#    #+#             */
/*   Updated: 2025/09/30 14:37:23 by sgaspari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXECUTE_H
# define EXECUTE_H

# include "cmds.h"
# include "data.h"
# include <stdint.h>

void	execute(t_cmd **cmds, t_data *data);
void	pids_and_ret(int *pid, int j, t_data *data);
void	allocate_pids(t_data *data, int **pid);
uint8_t	get_return_val(int status);

#endif
