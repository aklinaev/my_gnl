/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apenrose <apenrose@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/29 19:39:24 by apenrose          #+#    #+#             */
/*   Updated: 2020/12/07 19:25:29 by apenrose         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1000
# endif
# include<fcntl.h>
# include<stdlib.h>
# include<unistd.h>

int     get_next_line(int fd, char **line);
char	*ft_substr(char const *s, unsigned int start, size_t len);
int		ft_strchr(const char *s, int c);
char	*ft_strdup(const char *s1);
size_t	ft_strlenn(const char *s);
size_t	ft_strlen(const char *s);
char	*part_two(char const *s1, char const *s2, char *uni);
char	*ft_strjoin(char const *s1, char const *s2);

#endif
