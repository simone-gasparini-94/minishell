/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgaspari <sgaspari@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/05 12:58:20 by sgaspari          #+#    #+#             */
/*   Updated: 2025/09/11 10:56:43 by sgaspari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <readline/readline.h>
#include <readline/history.h>
#include "banner.h"
#include "signals.h"
#include "interpret.h"
#include "data.h"
#include "clean.h"
#include <stdlib.h>

int	main(int argc, char *argv[], char *envp[])
{
	t_data	*data;
	char	*s;

	(void)argc;
	(void)argv;
	banner();
	handle_signals();
	data = create_data(envp);
	while (1)
	{
		s = readline("> ");
		interpret(data, s);
		free(s);
	}
	rl_clear_history();
	return (0);
}
