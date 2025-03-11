/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: padan-pe <padan-pe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 18:44:23 by padan-pe          #+#    #+#             */
/*   Updated: 2025/03/11 19:36:28 by padan-pe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
#ifndef BUFFER_SIZE
    # define BUFFER_SIZE 1
#endif
# include <stdlib.h>
# include <unistd.h>

char	*ft_readbuffer(int fd, char *b);
char *get_next_line (int fd);
int	ft_untiln(const char *s);
size_t	ft_strlen(const char *s);
char	*ft_strchr(const char *s, int c);
char	*ft_strjoin(char *s1, char *s2);
size_t	ft_strlcat(char *dest, const char *src, size_t size);
char	*ft_strncpy(char *dest, const char *src, size_t dsize);
char	*ft_substr(char const *s, unsigned int start, size_t len);
#endif