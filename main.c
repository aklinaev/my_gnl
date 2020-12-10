/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apenrose <apenrose@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/03 23:47:54 by apenrose          #+#    #+#             */
/*   Updated: 2020/12/10 21:21:55 by apenrose         ###   ########.fr       */
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

  //fd = open("our_text.text", O_RDONLY);
  fd = open("/Users/apenrose/my_gnl/our_text.text", O_RDONLY);
  while (i < 10)
     {
             n = get_next_line(fd, &str);
             i++;
             //printf("gnl = %d\n", n);
             printf(">>>>>>>>%s || n = %d\n", str, n);
             free(str);
     }
//     sleep(100);
    return (0);
}
