/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buf_gnl.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apenrose <apenrose@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/07 18:52:00 by apenrose          #+#    #+#             */
/*   Updated: 2020/12/07 21:15:21 by apenrose         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "get_next_line.h"
#include <stdio.h>


int		get_next_line(int fd, char **str)
{
	char	buffer[BUFFER_SIZE + 1];
	int		x;
	int		new_line;
	int		i;
	int ost;
	static char *ostatok;
	static int y;

	i = 0;
	x = 0;
	new_line = 0;
	*str = ft_strdup("");
	
	printf("ostatok NACHALO = %s\n", ostatok);
	
	if (y == 0)
	{
		ostatok = ft_strdup("");
		y++;
	}

/*
	if (ostatok[0] != '\0')
	{
		ost = ft_strchr(ostatok, '\n');
		buffer = ft_substr(ostatok, ost, (ft_strlen(ostatok) - ost));
		buffer[ost] = '\0';
		*str = ft_strjoin(*str, buffer);
		return (2);
		
		
		ft_strlcpy(buffer, ostatok, (ft_strlen(ostatok) + 1));
		ostatok = ft_strchr(buffer, '\n');
		printf("ostatokNULL = %s\n", ostatok);
		
	}
*/
	x = read(fd, buffer, BUFFER_SIZE);
	buffer[x] = '\0';
	printf("buffer = %s\n", buffer);
	ost = ft_strchr(buffer, '\n');
	ostatok = ft_substr(buffer, ost, (ft_strlen(buffer) - ost));
	printf("OSTATOK = %s\n", ostatok);
	//ostatok = ft_strchr(buffer, '\n');
	
	while (ostatok[0] == '\0')
	{
		*str = ft_strjoin(*str, buffer);
		x = read(fd, buffer, BUFFER_SIZE);
		buffer[x] = '\0';
		printf("buffer = %s\n", buffer);
		ost = ft_strchr(buffer, '\n');
		ostatok = ft_substr(buffer, ost, (ft_strlen(buffer) - ost));
	}
	printf("ostatok = %s\n", ostatok);
	*str = ft_strjoin(*str, buffer);
	
	return (1);
}

/*
int			get_next_line(int fd, char **line)
{
	
	char	*buffer[10 + 1];
	int		x;
	int		new_line;
	int		i;

	i = 0;
	x = 0;
	new_line = 0;
	printf("999");

	x = read(fd, buffer, 10);
	printf("x = %d", x);
	*buffer[10] = '\0';
	while (*buffer[new_line] != '\n' && *buffer[new_line] != '\0')
	{
		(*line)[i] = *buffer[new_line];
		i++;
		new_line++;
	}
	return (0);
}
*/


---------------------------------------------------------------------------------------------


#include "get_next_line.h"
#include <stdio.h>


/*
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	count;

	count = 0;
	if (!dst || !src)
		return (0);
	if (dstsize == 0)
		return (ft_strlen(src));
	while (count < (dstsize - 1) && src[count])
	{
		dst[count] = src[count];
		count++;
	}
	dst[count] = '\0';
	return (ft_strlen(src));
}
*/

char		*ft_strchr(const char *s, int c)
{
	while (*s && *s != (char)c)
	{
		//printf(" strchr = %s . ", s);
		s++;
	}
	if (*s == (char)c)
		return ((char *)s);
	return (NULL);
}


char		*ft_strdup(const char *s1)
{
	char	*s2;
	size_t	i;
	size_t	count_s1;

	s2 = NULL;
	i = 0;
	count_s1 = 0;
	while (s1[count_s1])
	{
		count_s1++;
	}
	if (!(s2 = (char*)malloc(sizeof(char) * (count_s1 + 1))))
		return (NULL);
	while (i < count_s1)
	{
		s2[i] = s1[i];
		i++;
	}
	s2[i] = '\0';
	return (s2);
}

size_t			ft_strlenn(const char *s)
{
	size_t	len;

	len = 0;
	while (s[len] != '\n')
		len++;
	return (len);
}

size_t			ft_strlen(const char *s)
{
	size_t	len;

	len = 0;
	while (s[len])
		len++;
	return (len);
}

char		*part_two(char const *s1, char const *s2, char *uni)
{
	int		g;
	int		i;

	i = 0;
	g = 0;
	while (s1[i])
	{
		uni[g] = s1[i];
		i++;
		g++;
	}
	i = 0;
	while (s2[i] != '\n' && s2[i])
	{
		uni[g] = s2[i];
		i++;
		g++;
	}
	uni[g] = '\0';
	return (uni);
}

char		*ft_strjoin(char const *s1, char const *s2)
{
	char	*uni;
	int		sum;
	int		g;
	int		i;

	i = 0;
	g = 0;
	sum = 0;
	if (!(s1) || !(s2))
		return (NULL);
	sum = ft_strlen(s1) + ft_strlen(s2);
	if (!(uni = ((char *)malloc(sum + 1))))
		return (NULL);
	return ((char *)part_two(s1, s2, uni));
}

int		get_next_line(int fd, char **str)
{
	char	buffer[BUFFER_SIZE + 1];
	int		x;
	int		new_line;
	int		i;
	static char *ostatok;
	static int y;

	y = 0;
	i = 0;
	x = 0;
	new_line = 0;
	*str = ft_strdup("");
	
	if (y == 0)
	{
		ostatok = ft_strdup("");
		y++;
	}
	
	/*
	if (!(ostatok[0] == '\0'))
	{
		ft_strlcpy(buffer, ostatok, (ft_strlen(ostatok) + 1));
		ostatok = ft_strchr(buffer, '\n');
		printf("ostatokNULL = %s\n", ostatok);
	}
	*/
	x = read(fd, buffer, BUFFER_SIZE);
	buffer[x] = '\0';
	printf("buffer = %s\n", buffer);
	ostatok = ft_strchr(buffer, '\n');
	
	while (ostatok == NULL)
	{
		*str = ft_strjoin(*str, buffer);
		x = read(fd, buffer, BUFFER_SIZE);
		buffer[x] = '\0';
		printf("buffer = %s\n", buffer);
		ostatok = ft_strchr(buffer, '\n');
	}
	printf("ostatok = %s\n", ostatok);
	*str = ft_strjoin(*str, buffer);
	
	/*
	printf("buffer = %s\n", buffer);
	
	buffer[x] = '\0';	
	printf("b[x] = %c\n", buffer[x]);
	
	ostatok = ft_strchr(buffer, '\n');
	printf("ostatok = %s\n", ostatok);
	*str = ft_strjoin(*str, buffer);
	*/
	return (0);
}

/*
int			get_next_line(int fd, char **line)
{
	
	char	*buffer[10 + 1];
	int		x;
	int		new_line;
	int		i;

	i = 0;
	x = 0;
	new_line = 0;
	printf("999");

	x = read(fd, buffer, 10);
	printf("x = %d", x);
	*buffer[10] = '\0';
	while (*buffer[new_line] != '\n' && *buffer[new_line] != '\0')
	{
		(*line)[i] = *buffer[new_line];
		i++;
		new_line++;
	}
	return (0);
}
*/