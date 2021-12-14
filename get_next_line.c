/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaioumy <abaioumy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 18:14:09 by abaioumy          #+#    #+#             */
/*   Updated: 2021/12/14 13:56:59 by abaioumy         ###   ########.fr       */
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
		return (NULL);
	while((*str)[counter] && (*str)[counter] != '\n')
		counter++;
	line = ft_substr(*str, 0 , counter + 1);
	if ((*str)[counter])
		temp = ft_substr(*str, counter + 1, 1000);
	else
		temp = ft_strdup("");
    free(*str);	
	*str = temp;
	return (line);
}
char	*get_next_line(int fd)
{

	char 		*line = NULL;
	char		*str = NULL;
	static char	*saved;
	int			i;
	
	if (fd < 0 || BUFFER_SIZE <= 0)
		return(NULL);
	// if(saved == NULL)
	// 	saved = ft_strdup("");
	str = malloc(sizeof(char) * BUFFER_SIZE + 1);
	i = 1;
	while (i > 0 && !check_nl(saved))
	{
		i = read(fd, str, BUFFER_SIZE);
		if (i < 0)
		{
			free_pointer(&str);
			free_pointer(&saved);
	 		return (NULL);
		}
		str[i] = '\0';
		saved = ft_strjoin(&saved, str);
	}
	line = findnewline(&saved);
	free_pointer(&str);
	if (*saved == 0)
		free_pointer(&saved);
	return (line);
}