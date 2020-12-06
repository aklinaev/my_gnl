/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apenrose <apenrose@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/29 19:36:57 by apenrose          #+#    #+#             */
/*   Updated: 2020/12/06 19:02:17 by apenrose         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>


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
	char	buffer[BUFFER_SIZE];
	int		x;
	int		new_line;
	int		i;
	static char *ostatok;

	i = 0;
	x = 0;
	new_line = 0;
	*str = ft_strdup("");
	ostatok = ft_strdup("");
	x = read(fd, buffer, BUFFER_SIZE);
	printf("buffer = %s\n", buffer);
	buffer[x] = '\0';	
	printf("b[x] = %c\n", buffer[x]);
	
	ostatok = ft_strchr(buffer, '\n');
	printf("ostatok = %s\n", ostatok);
	*str = ft_strjoin(*str, buffer);


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