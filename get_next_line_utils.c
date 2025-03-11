/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: padan-pe <padan-pe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 18:44:09 by padan-pe          #+#    #+#             */
/*   Updated: 2025/03/11 19:31:15 by padan-pe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <unistd.h>

char	*ft_strchr(const char *s, int c)
{
	char	*st;
	char	cc;

	cc = (char) c;
	st = (char *)s;
	if(!st)
		return (NULL);
	while (*st != '\0')
	{
		if (*st == cc)
			return (st);
		st++;
	}
	if (cc == '\0')
		return (st);
	return (NULL);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*str;
	int		i;
	int		j;

	i = -1;
	j = -1;
	if (!s1 || !s2)
	{
		s1 = malloc(sizeof(char) + 1);
		if (!s1 || !s2)
			return (NULL);
		s1[0] = '\0';
	}
	str = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (str)
	{
		while (s1[++i] != '\0')
			str[i] = s1[i];
		while (s2[++j] != '\0')
			str[i + j] = s2[j];
		str[i + j] = '\0';
	}
	free(s1);
	return (str);
}

char	*ft_strncpy(char *dest, const char *src, size_t dsize)
{
	size_t	i;

	i = 0;
	while (i < dsize && src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	while (i < dsize)
	{
		dest[i] = '\0';
		i++;
	}
	return (dest);
}

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	dlen;
	size_t	slen;
	size_t	i;

	i = 0;
	dlen = 0;
	slen = 0;
	while (dest[dlen] != '\0' && dlen < size)
		dlen++;
	while (src[slen] != '\0')
		slen++;
	if (size <= dlen)
		return (size + slen);
	while (src[i] != '\0' && (dlen + i) < (size - 1))
	{
		dest[dlen + i] = src[i];
		i++;
	}
	dest[dlen + i] = '\0';
	return (dlen + slen);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	slen;
	int		j;
	char	*ss;

	i = start;
	j = 0;
	slen = ft_strlen(s);
	if (s == NULL)
		return (NULL);
	if ((start + len) > slen)
		len = slen - start;
	if ((start) > slen)
		return (NULL);
	ss = (char *) malloc(sizeof(char *) * (len + 1));
	if (ss == NULL)
		return (NULL);
	while (s[i] != '\0' && (start + len) > i)
	{
		ss[j] = s[i];
		j++;
		i++;
	}
	ss[j] = '\0';
	return (ss);
}
