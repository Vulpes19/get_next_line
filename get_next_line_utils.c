/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaioumy <abaioumy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 18:24:52 by abaioumy          #+#    #+#             */
/*   Updated: 2021/12/12 22:00:13 by abaioumy         ###   ########.fr       */
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
	unsigned char	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strjoin(char *s1,char *s2)
{
	int		s2len;
	int		s1len = 0;
	char	*ptr;

	// if (s1 == NULL || s2 == NULL)
	// 	return (0);
	if (s1)
		s1len = ft_strlen(s1);
	s2len = ft_strlen(s2);
	s1len += s2len;
	ptr = (char *)malloc(sizeof(char) * s1len + 1);
	if (!ptr)
		return (0);
	ptr = ft_cat(s1, s2, ptr, s1len);
	free(s1);
	return (ptr);
}

char	*ft_strchr(const char *str, int c)
{
	int		i;
	int		len;
	char	*ptr;

	i = 0;
	ptr = (char *)str;
	len = ft_strlen(ptr);
	if (c == 0)
		return (ptr + len);
	while (ptr[i])
	{
		if (ptr[i] == (char)c)
			return (&ptr[i]);
		i++;
	}
	return (NULL);
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
				return (1);
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

char	*subfunc(const char *s, char *substr, int start, int len)
{
	int	i;

	i = 0;
	while (s[start] && len)
	{
		substr[i] = s[start];
		i++;
		start++;
		len--;
	}
	substr[i] = '\0';
	return (substr);
}
void	*ft_calloc(size_t count, size_t size)
{
	unsigned int	len;
	void			*ptr;

	len = count * size;
	ptr = malloc(len * sizeof(char));
	if (!ptr)
		return (0);
	ft_bzero(ptr, len);
	return (ptr);
}
void	ft_bzero(void *str, size_t n)
{
	size_t	i;
	char	*ptr;

	i = 0;
	ptr = (char *)str;
	while (i < n)
	{
		ptr[i] = '\0';
		i++;
	}
}
char	*ft_substr(char *s, unsigned int start, size_t len)
{
	int		i;
	char	*substr;

	i = 0;
	substr = NULL;
	if (!s)
		return (0);
	if (start > ft_strlen(s) || len == 0)
		return (ft_strdup(""));
	if (ft_strlen(s) == len)
		substr = (char *)malloc(sizeof(char) * len - start + 1);
	else if (ft_strlen(s) + start >= len)
		substr = (char *)malloc(sizeof(char) * len + 1);
	else if (ft_strlen(s) + start < len)
		substr = (char *)malloc(sizeof(char) * ft_strlen(s) + 1);
	if (!substr)
		return (NULL);
	return (subfunc(s, substr, start, len));
}