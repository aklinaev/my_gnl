/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apenrose <apenrose@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/03 20:35:30 by apenrose          #+#    #+#             */
/*   Updated: 2020/12/10 23:44:07 by apenrose         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>


char		*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*ss;
	unsigned int	i;

	i = 0;
	if (!(s))
		return (NULL);
	if (!(ss = ((char *)malloc(len + 1))))
		return (NULL);
	if (start >= (unsigned int)ft_strlen(s))
	{
		ss[0] = '\0';
		return (ss);
	}
	while (s && (i < len))
	{
		ss[i] = s[start];
		i++;
		start++;
	}
	ss[i] = '\0';
	return (ss);
}

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

int		ft_strchr(const char *s, int c)
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
    {
	    free (s2);
        return (NULL);
    }
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

int			ft_strlen(const char *s)
{
	int	len;

	len = 0;
	if (!s)
	    return (0);
	while (s[len])
		len++;
	return (len);
}

char		*part_two(char *s1, char *s2, char *uni)
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
	free(s1);
	return (uni);
}

char		*ft_strjoin(char *s1, char *s2)
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