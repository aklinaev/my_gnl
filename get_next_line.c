/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apenrose <apenrose@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/29 19:36:57 by apenrose          #+#    #+#             */
/*   Updated: 2020/12/10 23:54:11 by apenrose         ###   ########.fr       */
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

int		n_chr(const char *s, int c)
{	
	int i;
	i = 0;
	if (!s)
		return (0);
	while (s[i] && s[i] != (char)c)
	{
		//printf(" strchr = %s . ", s);
		i++;
	}
	if (s[i] == (char)c)
		return (i + 1);
	return (0);
}

char		*part_twoo(char *s1, char *s2, char *uni)
{
	int		g;
	int		i;

	i = 0;
	g = 0;
	//s1 = ft_strdup("");
	while (s1[i])
	{
		uni[g] = s1[i];
		i++;
		g++;
	}
	i = 0;
	while (s2[i] != '\0' && s2[i])
	{
		uni[g] = s2[i];
		i++;
		g++;
	}
	uni[g] = '\0';
	free(s1);
	return (uni);
}

char		*strjoin_ft(char *s1, char *s2)
{
	char	*uni;
	int		sum;
	int		g;
	int		i;

	i = 0;
	g = 0;
	sum = 0;
	if (!(s2))
		return (NULL);
	sum = ft_strlen(s1) + ft_strlen(s2);
	// printf("sum = %d\n", sum);
	if (!(uni = ((char *)malloc(sum + 1))))
		return (NULL);
	return ((char *)part_twoo(s1, s2, uni));
}

int		get_next_line(int fd, char **str)
{
	static char *ostatok;
	char		*buffer;
	int			i_rd;
	int			i_n;
	static int  y = 1;

	if (fd < 0 || !str || BUFFER_SIZE <= 0)
        return (-1);
	if (!(buffer = (malloc(sizeof(char) * (BUFFER_SIZE + 1)))))
		return (-1);
	*str = ft_strdup("");
	if (y++ < 2)
        ostatok = ft_strdup("");
	while (!(i_n = n_chr(ostatok, '\n')) && (((i_rd = read(fd, buffer, BUFFER_SIZE)) > 0)))
	{
		if (i_rd < 0)
		{
			free (buffer);
			free (ostatok);
			return (-1);
		}
		buffer[i_rd] = '\0';
		ostatok = strjoin_ft(ostatok, buffer);
	}
	free (buffer);
	i_n = n_chr(ostatok, '\n');
	*str = ft_strjoin(*str, ostatok);
	if ((i_rd == 0) && (i_n == 0))
	    ostatok = ft_substr(ostatok, i_n, 0);
	else
        ostatok = ft_substr(ostatok, i_n, (ft_strlen(ostatok) - i_n));
	return (((i_rd == 0) && (i_n == 0)) ? 0 : 1);
}

// int		get_next_line(int fd, char **str)
// {
// 	static char *ostatok;
// 	char		*buffer = NULL;
// 	//int			i;
// 	int			i_n;

// 	*str = ft_strdup("");
//     ostatok = read_to_ost(ostatok, buffer, str, fd);
// 	if (ostatok)
// 		copy_to_buf_str(ostatok, buffer, str);
// 	free (buffer);
// 	i_n = ft_strchr(ostatok, '\n');
// 	printf("i_n = %d\n",i_n);
// 	if (i_n > 0)
// 		ostatok = ft_substr(ostatok, i_n, (ft_strlen(ostatok) - i_n));
// 	else
// 		ostatok = ft_substr(buffer, i_n, 0);
// 	if (!(ostatok))
// 		return (1);
// 	else
// 		ostatok = read_to_ost(ostatok, buffer, str, fd);
// 	return (0);
// }


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
