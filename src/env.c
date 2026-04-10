/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgaspari <sgaspari@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/23 12:54:55 by sgaspari          #+#    #+#             */
/*   Updated: 2025/08/29 15:48:51 by sgaspari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cmds.h"
#include "data.h"
#include "ft_fprintf.h"
#include "list.h"
#include <unistd.h>

void	env(t_cmd *cmd)
{
	t_node	*curr;

	curr = cmd->data->envp;
	while (curr != NULL)
	{
		ft_fprintf(cmd->out_fd, "%s\n", curr->s);
		curr = curr->next;
	}
}
