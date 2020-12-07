/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aklinaev <aklinaev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/29 19:36:57 by apenrose          #+#    #+#             */
/*   Updated: 2020/12/08 02:11:33 by aklinaev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

void	my_free(char *ostatok, char *buffer)
{
	free(buffer);
	free(ostatok);
}

char	*copy_ostatok(char *ostatok)
{
	int		i;
	char	*buffer;

	i = ft_strchr(ostatok, '\n');
	buffer = ft_substr(ostatok, 0, ft_strlen(ostatok));
	if (i != 0)
		buffer[i] = '\0';
	else
		buffer[ft_strlen(ostatok)] = '\0';
	return (buffer);
}

int		get_next_line(int fd, char **str)
{
	char		*buffer;
	int			x;
	int			ost = 0;
	static char *ostatok;
	static int 	y;

	x = 1;
	*str = ft_strdup("");
	if (y == 0)
	{
		*str = ft_strdup("");
		ostatok = ft_strdup("");
		y++;
	}
	if (ostatok[0] != '\0')
	{	
		buffer = copy_ostatok(ostatok);
		*str = ft_strjoin(*str, buffer);
		free(buffer);
	}
	if (!(buffer = (malloc(sizeof(char) * (BUFFER_SIZE + 1)))))
		return (-1);
	while (ost == 0 && x > 0)
	{
		x = read(fd, buffer, BUFFER_SIZE);
		printf("x = %d", x);
		if (x == 0)
			return (-1);
		buffer[x] = '\0';
		ost = ft_strchr(buffer, '\n');
		if (ost > 0)
			ostatok = ft_substr(buffer, ost, (ft_strlen(buffer) - ost));
		else
			ostatok = ft_substr(buffer, ost, 0);
		*str = ft_strjoin(*str, buffer);
		if (x < BUFFER_SIZE)
		{
			my_free(ostatok, buffer);
			return (-1);
		}
	}
	free(buffer);
	return (1);
}
