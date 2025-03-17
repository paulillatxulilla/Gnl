/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: padan-pe <padan-pe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 18:43:54 by padan-pe          #+#    #+#             */
/*   Updated: 2025/03/17 14:37:37 by padan-pe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "get_next_line.h"

int	ft_untiln(const char *s)
{
	int	i;

	i = 0;
	if (!s)
		return (-1);
	while (s[i] != '\0' && s[i] != '\n')
		i++;
	return (i);
}

char	*ft_readbuffer(int fd, char *rest)
{
	int			bytesread;
	char		*buffer;

	buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (fd < 0)
	{
		free (buffer);
		return (NULL);
	}
	while (!ft_strchr(rest, '\n'))
	{
		bytesread = read (fd, buffer, BUFFER_SIZE);
		if (bytesread == -1)
		{
			free(buffer);
			return (NULL);
		}
		if (bytesread == 0)
			break ;
		buffer[bytesread] = '\0';
		rest = ft_strjoin(rest, buffer);
	}
	free (buffer);
	return (rest);
}

char	*get_next_line(int fd)
{
	char		*buffer;
	static char	*rest = NULL;
	char		*line;
	int			find;

	buffer = ft_readbuffer(fd, rest);
	find = ft_untiln(buffer);
	line = ft_substr(buffer, 0, find + 1);
	if (ft_strchr(buffer, '\n'))
		rest = ft_substr(buffer, find + 1, BUFFER_SIZE);
	else
		rest = NULL;
	free (buffer);
	return (line);
}
/* 

#include <stdio.h>

int	main (int argc, char **argv)
{
	int fd;
	char *result;
	
	if (argc != 2)
		return (0);
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		{
			perror("error :[");
			return (1);
		}
	result = get_next_line(fd);
	while (result)
	{
		printf("{%s}", result);
		free(result);
		result = get_next_line(fd);
	}
	
	close (fd);
	return (0);
}
 */