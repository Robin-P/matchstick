/*
** my_strlen.c for  in /home/robin/delivery/CPool_Day04
** 
** Made by Robin Pronnier
** Login   <robin@epitech.net>
** 
** Started on  Thu Oct  6 19:13:55 2016 Robin Pronnier
** Last update Fri Jun  9 19:39:00 2017 Robin Pronnier
*/

#include "my.h"

int	my_strlen(char *str)
{
  int	i;

  i = 0;
  while (str[i] != '\0')
    {
      i = i + 1;
    }
  return (i);
}

int	my_strlen1(va_list ap)
{
  my_strlen(va_arg(ap, char *));
  return (0);
}
