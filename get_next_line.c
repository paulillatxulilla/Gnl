/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: padan-pe <padan-pe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 18:43:54 by padan-pe          #+#    #+#             */
/*   Updated: 2025/03/07 17:00:13 by padan-pe         ###   ########.fr       */
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
		return (0);
	while (s[i] != '\0' && s[i] != '\n')
		i++;
	return (i);
}

char	*ft_strdup(const char *s)
{
	size_t	len;
	char	*dest;

	len = ft_strlen(s) + 1;
	dest = (char *)malloc(len);
	if (dest == NULL)
		return (NULL);
	ft_strncpy(dest, s, len);
	return (dest);
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
	char		*readbuf;
	int			bytesread;
	char		buffer[BUFFER_SIZE + 1];

	if (fd < 0)
		return (NULL);
	while (!ft_strchr(b, '\n'))
	{
		bytesread = read (fd, buffer, BUFFER_SIZE);
		if (bytesread <= 0)
			return (NULL);
		buffer[bytesread] = '\0';
		b = ft_strjoin(b, buffer);
	}
	return (b);
}

char *ft_getline (int fd)
{
	char	*buffer;
	static char	*resto;
	char	*line;
	int		find;
	char	*buffer2;
	
	buffer = ft_readbuffer(fd, resto);
	if (!buffer)
		return (NULL);
	find = ft_untiln(buffer);
	line = ft_substr(buffer, 0, find);
	resto = ft_strchr(buffer, '\n') + 1;
	return (line);
}

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
	result = ft_getline(fd);
	while (result)
	{
		printf("%s\n", result);
		result = ft_getline(fd);
	}
	free(result);
	close (fd);
	return (0);
}
