/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: padan-pe <padan-pe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 18:43:54 by padan-pe          #+#    #+#             */
/*   Updated: 2025/03/11 19:37:57 by padan-pe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>
#include "get_next_line.h"
#include <stdio.h>
#include <stdlib.h>

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

size_t	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*ft_readbuffer(int fd, char *b)
{
	int			bytesread;
	char		*buffer;
	
	buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (fd < 0)
		return (NULL);
	while (!ft_strchr(b, '\n'))
	{
		bytesread = read (fd, buffer, BUFFER_SIZE);
		if (bytesread == -1)
			return (NULL);
		if (bytesread == 0)
			break;
		buffer[bytesread] = '\0';		
		b = ft_strjoin(b, buffer);
	}
	free (buffer);
	return (b);
}

char *get_next_line (int fd)
{
	char		*buffer;
	static char	*resto;
	char		*line;
	int			find;
	
	buffer = ft_readbuffer(fd, resto);
	if (!buffer)
		return (NULL);
	find = ft_untiln(buffer);
	line = ft_substr(buffer, 0, find);
	if (ft_strchr(buffer, '\n'))
		resto = ft_substr(buffer, find + 1, BUFFER_SIZE);
	else
		resto = NULL;
	free (buffer);
	return (line);
}

/* int	main (int argc, char **argv)
{
	int fd;
	char *result;
	
	if (argc != 2)
		return (0);
	fd = open("lorem ipsum.txt", O_RDONLY);
	if (fd == -1)
		{
			perror("error :[");
			return (1);
		}
	result = ft_getline(fd);
	while (result)
	{
		printf("%s\n", result);
		free(result);
		result = ft_getline(fd);
	}
	
	close (fd);
	return (0);
}
 */