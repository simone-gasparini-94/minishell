/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgaspari <sgaspari@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/23 13:31:40 by sgaspari          #+#    #+#             */
/*   Updated: 2025/09/03 15:00:03 by sgaspari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cmds.h"
#include "data.h"
#include "libft.h"
#include "list.h"
#include <stdlib.h>

void	unset(t_cmd *p)
{
	char	*s;

	s = ft_strjoin(p->argv[1], "=");
	delete_node(&p->data->envp, s, ft_strlen(s));
	free(s);
}
