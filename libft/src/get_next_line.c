/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgaspari <sgaspari@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 13:32:13 by sgaspari          #+#    #+#             */
/*   Updated: 2025/07/31 11:32:12 by sgaspari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <stddef.h>
#include "libft.h"
#include "get_next_line_internal.h"

static char	*append_to_buffer(char *buffer, const char *read_buffer);
static char	*extract_next_line(char *buffer);
static char	*extract_new_buffer(char *buffer);

char	*get_next_line(int fd)
{
	char		*next_line;
	static char	*buffer;
	char		read_buffer[BUFFER_SIZE + 1];
	ssize_t		bytes_read;

	if (fd < 0)
		return (NULL);
	if (!buffer)
		buffer = initialize_buffer();
	while (!is_new_line_in_str(buffer))
	{
		bytes_read = read(fd, read_buffer, BUFFER_SIZE);
		if (bytes_read == 0)
			break ;
		if (bytes_read < 0)
			return (NULL);
		read_buffer[bytes_read] = '\0';
		buffer = append_to_buffer(buffer, read_buffer);
	}
	if (!buffer || buffer[0] == '\0')
		return (free_buffer(&buffer));
	next_line = extract_next_line(buffer);
	buffer = extract_new_buffer(buffer);
	return (next_line);
}

static char	*append_to_buffer(char *buffer, const char *read_buffer)
{
	char	*new_buffer;
	size_t	len_buffer;
	size_t	len_read_buffer;
	size_t	len_new_buffer;

	if (!buffer || !read_buffer)
		return (NULL);
	len_buffer = ft_strlen(buffer);
	len_read_buffer = ft_strlen(read_buffer);
	len_new_buffer = len_buffer + len_read_buffer;
	new_buffer = (char *) malloc(len_new_buffer + 1);
	if (!new_buffer)
		return (NULL);
	new_buffer[0] = '\0';
	ft_strlcat(new_buffer, buffer, len_new_buffer + 1);
	free_buffer(&buffer);
	ft_strlcat(new_buffer, read_buffer, len_new_buffer + 1);
	return (new_buffer);
}

static char	*extract_next_line(char *buffer)
{
	char	*next_line;
	size_t	len;

	len = 0;
	while (buffer[len] && buffer[len] != '\n')
		len++;
	if (buffer[len] == '\n')
		len++;
	next_line = (char *) malloc(len + 1);
	if (!next_line)
		return (NULL);
	next_line[0] = '\0';
	ft_strlcat(next_line, buffer, len + 1);
	return (next_line);
}

static char	*extract_new_buffer(char *buffer)
{
	char	*new_buffer;
	size_t	i;
	size_t	len;

	i = 0;
	while (buffer[i] && buffer[i] != '\n')
		i++;
	if (buffer[i] == '\n')
		i++;
	len = 0;
	while (buffer[i + len])
		len++;
	new_buffer = (char *) malloc(len + 1);
	if (!new_buffer)
		return (NULL);
	new_buffer[0] = '\0';
	ft_strlcat(new_buffer, buffer + i, len + 1);
	free_buffer(&buffer);
	return (new_buffer);
}
