/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aklinaev <aklinaev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/03 23:47:54 by apenrose          #+#    #+#             */
/*   Updated: 2020/12/08 02:06:29 by aklinaev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stdio.h>
#include<fcntl.h>
#include<stdlib.h>
#include "get_next_line.h"

int main(void)
{
  int n;
  n = 1;
  int fd;
  char *str;
  int i = 0;

  fd = open("alphabet.txt", O_RDONLY);
  
  while (i < 85)
     {
             n = get_next_line(fd, &str);
             i++;
             //printf("gnl = %d\n", n);
             printf("%s\n", str);
     } 
    return (0);
}
