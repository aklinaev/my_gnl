/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apenrose <apenrose@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/29 19:36:57 by apenrose          #+#    #+#             */
/*   Updated: 2020/12/07 23:55:01 by apenrose         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

char	*copy_ostatok(char *ostatok)
{
	int		i;
	char	*buffer;

	i = ft_strchr(ostatok, '\n');
	buffer = ft_substr(ostatok, 0, ft_strlen(ostatok));
	buffer[i] = '\0';
	return (buffer);
}

int		get_next_line(int fd, char **str)
{
	char	*buffer;
	int		x;
	int		new_line;
	int		i;
	int ost = 0;
	static char *ostatok;
	static int y;
	//char *pyst = NULL;

	i = 0;
	x = 1;
	new_line = 0;
	printf("ostatok NACHALO = %s\n", ostatok);
	*str = ft_strdup("");
	printf("strdup_str = %s\n", *str);
	if (y == 0)
	{
		*str = ft_strdup("");
		ostatok = ft_strdup("");
		y++;
	}

	if (ostatok[0] != '\0')
	{	
		buffer = copy_ostatok(ostatok);
		printf("ostatoc_if = %s\n", buffer);
		*str = ft_strjoin(*str, buffer);
		printf("ostatoc_if_str = %s\n", *str);
		free(buffer);
	}

	if (!(buffer = (malloc(sizeof(char) * (BUFFER_SIZE + 1)))))
		return (-1);
	/*
	x = read(fd, buffer, BUFFER_SIZE);
	buffer[x] = '\0';
	printf("buffer = %s\n", buffer);
	ost = ft_strchr(buffer, '\n');
	ostatok = ft_substr(buffer, ost, (ft_strlen(buffer) - ost));
	printf("OSTATOK = %s\n", ostatok);
	*str = ft_strjoin(*str, buffer);
	printf("STR_pered while = %s\n", *str);
	*/

	while (ost == 0 && x > 0)
	{
		x = read(fd, buffer, BUFFER_SIZE);
		buffer[x] = '\0';
		printf("buffer_while = %s\n", buffer);
		ost = ft_strchr(buffer, '\n');
		if (ost > 0)
			ostatok = ft_substr(buffer, ost, (ft_strlen(buffer) - ost));
		else
			ostatok = ft_substr(buffer, ost, 0);
		*str = ft_strjoin(*str, buffer);
	}
	printf("ostatok = %s\n", ostatok);
	//*str = ft_strjoin(*str, buffer);
	
	free(buffer);
	
	return (1);
}
