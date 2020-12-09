/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apenrose <apenrose@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/29 19:36:57 by apenrose          #+#    #+#             */
/*   Updated: 2020/12/09 22:24:51 by apenrose         ###   ########.fr       */
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

char	*copy_to_buf_str(char *ostatok, char *buffer, char **str)
{
	buffer = copy_ostatok(ostatok);
	*str = ft_strjoin(*str, buffer);
	free (buffer);
	return (ostatok);
}

char	*read_to_ost(char *ostatok, char *buffer, char **str, int fd)
{
	int		x = 1;
	if (!(ostatok = (malloc(sizeof(char) * (BUFFER_SIZE + 1)))))
		return (NULL);
	while (x > 0)
	{
		x = read(fd, ostatok, BUFFER_SIZE);
		ostatok[x] = '\0';
		ostatok = copy_to_buf_str(ostatok, buffer, str);
	}
	free (buffer);
	return (ostatok);
}

int		get_next_line(int fd, char **str)
{
	static char *ostatok;
	char		*buffer = NULL;
	//int			i;
	int			i_n;

	*str = ft_strdup("");
    ostatok = read_to_ost(ostatok, buffer, str, fd);
	if (ostatok)
		copy_to_buf_str(ostatok, buffer, str);
	free (buffer);
	i_n = ft_strchr(ostatok, '\n');
	printf("i_n = %d\n",i_n);
	if (i_n > 0)
		ostatok = ft_substr(ostatok, i_n, (ft_strlen(ostatok) - i_n));
	else
		ostatok = ft_substr(buffer, i_n, 0);
	if (!(ostatok))
		return (1);
	else
		ostatok = read_to_ost(ostatok, buffer, str, fd);
	return (0);
}


// int		get_next_line(int fd, char **str)
// {
// 	char		*buffer;
// 	int			x;
// 	int			ost = 0;
// 	static char *ostatok;
// 	char        *tmp;

// 	x = 1;
// 	*str = ft_strdup("");
// 	if (ostatok)
// 	{	
// 		buffer = copy_ostatok(ostatok);
// 		ost = ft_strchr(ostatok, '\n');
// 		if (ost > 0)
//         {
//             tmp = ostatok;
//             ostatok = ft_substr(ostatok, ost, (ft_strlen(ostatok) - ost));
//             free(tmp);
//         }
// 		else
//         {
//             tmp = ostatok;
//             ostatok = ft_substr(buffer, ost, 0);
//             free(tmp);
//         }
// 		*str = ft_strjoin(*str, buffer);
// 		free(buffer);
// 		if (ostatok[0] != '\0')
// 			return (12);
// 	}
// 	if (!(buffer = (malloc(sizeof(char) * (BUFFER_SIZE + 1)))))
// 		return (-1);
	
// 	while (ost == 0 && x > 0)
// 	{
// 		x = read(fd, buffer, BUFFER_SIZE);
// 		if (x == 0)
// 			return (-1);
// 		buffer[x] = '\0';
// 		ost = ft_strchr(buffer, '\n');
// 		//printf("ost = %d\n", ost);
// 		//printf("buffer_end = %s\n", buffer);
// 		if (ost > 0)
//         {
// 		    tmp = ostatok;
// 			ostatok = ft_substr(buffer, ost, (ft_strlen(buffer) - ost));
//             free(tmp);
//         }
// 		else
//         {
//             tmp = ostatok;
//             ostatok = ft_substr(buffer, ost, 0);
//             free(tmp);
//         }
// 		//printf("ostatok! = %s\n", ostatok);
// 		*str = ft_strjoin(*str, buffer);
// 		if (x < BUFFER_SIZE && buffer == ostatok)
// 		{
// 			my_free(ostatok, buffer);
// 			return (-1);
// 		}
// 	}
// 	free(buffer);
// 	return (11);
// }
