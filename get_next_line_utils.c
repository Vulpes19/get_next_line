/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaioumy <abaioumy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 18:24:52 by abaioumy          #+#    #+#             */
/*   Updated: 2021/12/14 14:00:23 by abaioumy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*ft_cat(char *dest, char *src, char *ptr, int len)
{
	int	i;
	int	j;

	j = 0;
	i = 0;
	while (i < len)
	{
		if (dest)
		{
			while (dest[j])
			{
				ptr[i] = dest[j];
				i++;
				j++;
			}
		}
		j = 0;
		while (src[j])
		{
			ptr[i] = src[j];
			i++;
			j++;
		}
	}
	ptr[i] = '\0';
	return (ptr);
}

size_t	ft_strlen(char *str)
{
	size_t	i;

	if (!str)
		return (0);
	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	free_pointer(char **ptr)
{
	if (*ptr)
	{
		free(*ptr);
		*ptr = NULL;
	}
}
char	*ft_strjoin(char **s1,char *s2)
{
	int		s2len;
	int		s1len = 0;
	char	*ptr;

	if (*s1 == NULL && s2 == NULL)
		return (NULL);
	// if (!*s1)
	// 	*s1 = ft_strdup("");
	s1len = ft_strlen(*s1);
	s2len = ft_strlen(s2);
	s1len += s2len;
	ptr = (char *)malloc(sizeof(char) * s1len + 1);
	if (!ptr)
		return (0);
	ptr = ft_cat(*s1, s2, ptr, s1len);
	free_pointer(s1);
	return (ptr);
}

int	check_nl(char *saved)
{
	int	i;

	i = 0;
	if (saved)
	{
		while (saved[i])
		{
			if (saved[i] == '\n')
				return (i);
			i++;
		}
	}
	return (0);
}

char	*ft_strdup(char *src)
{
	int		i;
	int		len;
	char	*dest;

	i = 0;
	len = ft_strlen(src);
	dest = (char *)malloc(sizeof(char) * len + 1);
	if (!dest)
		return (0);
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';

	return (dest);
}

char	*subfunc(char *s, char *substr, int start, int len)
{
	int	i;

	i = 0;
	while (s[start] && len)
	{
		substr[i++] = s[start++];
		len--;
	}
	substr[i] = '\0';
	return (substr);
}

char	*ft_substr(char *s, unsigned int start, size_t len)
{
	int		i;
	char	*substr;
	int		len1;
	i = 0;
	len1 = ft_strlen(s);
	substr = NULL;
	if (!s || !*s)
		return (0);
	if ((int)start > len1)
		return (ft_strdup(""));
	if (len1 == (int)len)
		substr = (char *)malloc(sizeof(char) * len - start + 1);
	else if (len1 + start >= len)
		substr = (char *)malloc(sizeof(char) * len + 1);
	else if (len1 + start < len)
		substr = (char *)malloc(sizeof(char) * len1 + 1);
	if (!substr)
		return (NULL);
	return (subfunc(s, substr, start, len));
}