/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: duccello <duccello@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/24 17:09:47 by duccello          #+#    #+#             */
/*   Updated: 2025/09/11 11:15:03 by sgaspari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "clean.h"
#include "cmds.h"
#include "data.h"
#include "list.h"
#include "token.h"
#include <stdlib.h>

void	free_data(t_data *data)
{
	if (data == NULL)
		return ;
	if (data->cmds != NULL)
		free_cmds(data->cmds, data->n_cmds);
	if (data->tokens != NULL)
		free_tokens(data->tokens, data);
	if (data->envp != NULL)
		free_list(data->envp);
	if (data->built_ins != NULL)
		free_array(data->built_ins);
	if (data->pipfd != NULL)
	{
		free(data->pipfd);
		data->pipfd = NULL;
	}
	free(data);
}
