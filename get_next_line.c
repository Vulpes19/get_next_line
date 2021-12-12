/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaioumy <abaioumy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 18:14:09 by abaioumy          #+#    #+#             */
/*   Updated: 2021/12/12 22:07:35 by abaioumy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char *findnewline(char **str)
{
	int counter;
	char *line;
	char *temp;
	counter = 0;
	if (**str == '\0')
	{	
		free(*str);
		*str = NULL;
		return (NULL);
	}
	while((*str)[counter] && (*str)[counter] != '\n')
		counter++;
	line = ft_substr(*str, 0 , counter + 1);
	temp = ft_substr(*str, counter + 1, 1000);
	free(*str);
	*str = temp;
	return (line);
}
char	*get_next_line(int fd)
{

	int		i;
	char	*str = NULL;
	char *line = NULL;
	static char	*saved;
	if(saved == NULL)
		saved = ft_strdup("");
	
	if (check_nl(saved))
		{
			line = findnewline(&saved);
			return (line);
		}
	str = malloc(sizeof(char) * BUFFER_SIZE + 1);
	i = 1;
	while (i > 0)
	{
		i = read(fd, str, BUFFER_SIZE);
		str[i] = '\0';
		saved = ft_strjoin(saved, str);
		
		if (check_nl(saved))
		{
			line = findnewline(&saved);		
			break;
		}
	}
	if (i < 0)
	{
		free (str);
		return (NULL);
	}
	return (line);
}