/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: padan-pe <padan-pe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 18:43:54 by padan-pe          #+#    #+#             */
/*   Updated: 2025/03/05 18:52:29 by padan-pe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>
#include "get_next_line.h"
#include <stdio.h>
#include <stdlib.h>

char	*ft_readbuffer(int fd)
{
	char		*readbuf;
	int			bytesread;
	// char		buffer[BUFFER_SIZE + 1];
	char *buffer = malloc(sizeof(char)* BUFFER_SIZE + 1);

	if (fd < 0)
		return (NULL);
	bytesread = read (fd, buffer, BUFFER_SIZE);
	if (bytesread <= 0)
		return (NULL);
	buffer[bytesread] = '\0';
	// readbuf = ft_strdup(buffer);
	return (buffer);
}

char *ft_getline (int fd)
{
	char	*buffer;
	static char	*resto;
	char	*line = malloc(sizeof(char)* BUFFER_SIZE + 1);;
	int		find;

	/*if (resto)
	{
		temp = ft_strjoin(resto, buffer);
		free(resto);
		free (buffer);
		buffer = temp;
	}*/

	buffer = ft_readbuffer(fd);
	if (!buffer)
		return (NULL);
	find = ft_untiln(buffer);
	line = ft_strlcpy(line, buffer, find);
	resto = ft_strchr(buffer, '\n') + 1;
	free(buffer);
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
	printf("Linea %s", result);
	free(result);
	close (fd);
	return (0);
}
