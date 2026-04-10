/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgaspari <sgaspari@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/22 14:54:02 by sgaspari          #+#    #+#             */
/*   Updated: 2025/09/03 14:59:27 by sgaspari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIST_H
# define LIST_H

typedef struct s_node
{
	char			*s;
	struct s_node	*next;
}	t_node;

t_node	*create_list(char **arr);
t_node	*create_node(char *s);
void	append_node(t_node **list, t_node *node);
void	delete_node(t_node **list, char *s, int len);
t_node	*find_last_node(t_node *list);

#endif
