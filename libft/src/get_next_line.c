/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgaspari <sgaspari@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 11:51:24 by sgaspari          #+#    #+#             */
/*   Updated: 2025/09/23 15:20:29 by sgaspari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "libft.h"
#include "get_next_line.h"

static void	init_buffer(char **buffer);
static char	*append_to_buffer(char **buffer, char *buf);
static char	*extract_line(char **buffer);
static char	*update_buffer(char **buffer);

char	*get_next_line(int fd)
{
	static char	*buffer[MAX_FD];
	char		buf[BUFFER_SIZE + 1];
	char		*next_line;
	ssize_t		num_read;

	if (fd < 0 || fd >= MAX_FD || BUFFER_SIZE <= 0)
		return (NULL);
	init_buffer(&(buffer[fd]));
	while (ft_strchr(buffer[fd], '\n') == NULL)
	{
		num_read = read(fd, buf, BUFFER_SIZE);
		if (num_read == -1)
		{
			free(buffer[fd]);
			return (NULL);
		}
		if (num_read == 0)
			break ;
		buf[num_read] = '\0';
		buffer[fd] = append_to_buffer(&(buffer[fd]), buf);
	}
	next_line = extract_line(&(buffer[fd]));
	buffer[fd] = update_buffer(&(buffer[fd]));
	return (next_line);
}

static void	init_buffer(char **buffer)
{
	if (*buffer == NULL)
	{
		*buffer = malloc(1);
		if (*buffer == NULL)
			return ;
		(*buffer)[0] = '\0';
	}
}

static char	*append_to_buffer(char **buffer, char *buf)
{
	char	*new_buffer;
	size_t	len_new;
	size_t	len_buffer;
	size_t	len_buf;

	if (*buffer == NULL)
		return (NULL);
	len_buffer = ft_strlen(*buffer);
	len_buf = ft_strlen(buf);
	len_new = len_buffer + len_buf;
	new_buffer = malloc(len_new + 1);
	if (new_buffer == NULL)
	{
		free(*buffer);
		return (NULL);
	}
	ft_strlcpy(new_buffer, *buffer, len_new + 1);
	ft_strlcat(new_buffer, buf, len_new + 1);
	free(*buffer);
	*buffer = NULL;
	return (new_buffer);
}

static char	*extract_line(char **buffer)
{
	char	*line;
	size_t	len;

	if (*buffer == NULL)
		return (NULL);
	if ((*buffer)[0] == '\0')
	{
		free(*buffer);
		*buffer = NULL;
		return (NULL);
	}
	len = 0;
	while ((*buffer)[len] != '\0' && (*buffer)[len] != '\n')
		len++;
	if ((*buffer)[len] == '\n')
		len++;
	line = malloc(len + 1);
	if (line == NULL)
	{
		free(*buffer);
		*buffer = NULL;
		return (NULL);
	}
	ft_strlcpy(line, *buffer, len + 1);
	return (line);
}

static char	*update_buffer(char **buffer)
{
	char	*new;
	size_t	len;

	if (*buffer == NULL)
		return (NULL);
	len = 0;
	while ((*buffer)[len] != '\0' && (*buffer)[len] != '\n')
		len++;
	if ((*buffer)[len] == '\0')
	{
		free(*buffer);
		return (NULL);
	}
	new = ft_strdup((*buffer) + len + 1);
	free(*buffer);
	return (new);
}
