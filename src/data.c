/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgaspari <sgaspari@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/05 13:37:52 by sgaspari          #+#    #+#             */
/*   Updated: 2025/09/09 20:16:07 by sgaspari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"
#include "data.h"
#include "built_in.h"
#include <stdlib.h>
#include <stdbool.h>

t_data	*create_data(char **envp)
{
	t_data	*data;

	data = malloc(sizeof(t_data));
	if (data == NULL)
		return (NULL);
	data->envp = create_list(envp);
	data->built_ins = create_built_ins();
	data->ret_val = 0;
	return (data);
}
