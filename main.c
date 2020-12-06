/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apenrose <apenrose@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/03 23:47:54 by apenrose          #+#    #+#             */
/*   Updated: 2020/12/05 21:11:54 by apenrose         ###   ########.fr       */
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
  fd = open("our_text.text", O_RDONLY);
  
    n = get_next_line(fd, &str);
    printf("ITOG === %s\n", str);
  /*
  while (n > 0)
  {
    n = get_next_line(fd, &str);
    printf("%s\n", str);
    free(str);
  }
  */
 return (0);
}

/*
int main(void)
{   
    int fd = open("our_text.txt", O_RDONLY);
    char *stroka;
    int i = 1; 
    printf("88");
    while (get_next_line(fd, &stroka) >= 0)
    {
        printf("#%d ===> %s\n", i, stroka);
    }
    return (0);
}
*/