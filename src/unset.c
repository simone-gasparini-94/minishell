/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgaspari <sgaspari@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/23 13:31:40 by sgaspari          #+#    #+#             */
/*   Updated: 2025/09/24 12:00:04 by sgaspari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "built_in.h"
#include "cmds.h"
#include "data.h"
#include "libft.h"
#include "list.h"
#include "ft_fprintf.h"
#include <stdbool.h>
#include <stdlib.h>
#include <unistd.h>

static bool	is_parameter_name_invalid(char *s);

void	unset(t_cmd *p)
{
	char	*s;
	size_t	i;

	if (p->argv[1] == NULL)
	{
		ft_fprintf(STDERR_FILENO, "unset: not enough arguments\n");
		p->data->ret_val = 1;
	}
	i = 1;
	while (p->argv[i] != NULL)
	{
		if (is_parameter_name_invalid(p->argv[i]) == true)
		{
			ft_fprintf(STDERR_FILENO,
				"unset: %s: invalid parameter name\n", p->argv[i]);
			p->data->ret_val = 1;
		}
		else
		{
			s = ft_strjoin(p->argv[i], "=");
			delete_node(&p->data->envp, s, ft_strlen(s));
			free(s);
		}
		i++;
	}
}

static bool	is_parameter_name_invalid(char *s)
{
	size_t	i;

	if (ft_isdigit(s[0]) == true)
		return (true);
	i = 0;
	while (s[i] != '\0')
	{
		if (!(ft_isalnum(s[i]) || s[i] == '_'))
			return (true);
		i++;
	}
	return (false);
}
