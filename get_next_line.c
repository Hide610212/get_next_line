/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmuto <hmuto@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 14:01:49 by hmuto             #+#    #+#             */
/*   Updated: 2025/05/19 15:00:21 by hmuto            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*extract_line(char *saved)
{
	char	*line;
	size_t	len;
	char	*newline;

	if (!saved || !*saved)
		return (NULL);
	newline = ft_strchr(saved, '\n');
	if (newline)
		len = newline - saved + 1;
	else
		len = ft_strlen(saved);
	line = ft_substr(saved, 0, len);
	return (line);
}

char	*update_saved(char *saved)
{
	char	*newline;
	char	*new_saved;

	newline = ft_strchr(saved, '\n');
	if (!newline)
	{
		free(saved);
		return (NULL);
	}
	new_saved = ft_strdup(newline + 1);
	free(saved);
	return (new_saved);
}

char	*read_and_save(int fd, char *saved)
{
	char	*buffer;
	ssize_t	r;

	buffer = malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	r = 1;
	while (!ft_strchr(saved, '\n') && r > 0)
	{
		r = read(fd, buffer, BUFFER_SIZE);
		if (r < 0)
		{
			free(buffer);
			free(saved);
			return (NULL);
		}
		buffer[r] = '\0';
		saved = ft_strjoin_and_free(saved, buffer);
	}
	free(buffer);
	return (saved);
}

char	*get_next_line(int fd)
{
	static char	*saved;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	saved = read_and_save(fd, saved);
	if (!saved)
		return (NULL);
	line = extract_line(saved);
	saved = update_saved(saved);
	return (line);
}
