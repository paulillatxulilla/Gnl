/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: padan-pe <padan-pe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 18:43:54 by padan-pe          #+#    #+#             */
/*   Updated: 2025/02/27 19:53:22 by padan-pe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>
#include "get_next_line.h"
#include <stdio.h>
#include <stdlib.h>

char	readbuffer(int fd)
{
	int		readbuf;
	char	buffer[BUFFER_SIZE];
	char	*line;

	if (fd < 0)
		return (NULL);
	readbuf = read (fd, buffer, BUFFER_SIZE);
	if (readbuf <= 0)
		return (NULL);
	while (readbuf != '\n' || '\0')
		line = readbuf;
	return (line);
}

char getline
{
	
}

char	*get_next_line(int fd)
{
	int			i;
	int			len;
	
	char		buffer[1000 + 1];
	static char	*line;

	
	len = ft_untiln(buffer);
	line = (char *)malloc(len + 1);
	if (!line)
		return (NULL);
	i = 0;
	while (line && i < len)
	{
		line [i] = buffer[i];
		i++;
	}
	line [len] = '\0';
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
	result = get_next_line(fd);
	printf("Linea %s", result);
	free(result);
	result = get_next_line(fd);
	printf("Linea %s", result);
/* 	while ((result = get_next_line(fd)))
		printf("linea %s", result); */
	free (result);
	close (fd);
	return (0);
}