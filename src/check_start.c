/*
** check_start.c for  in /home/robin/delivery/CPE/CPE_2016_matchstick
** 
** Made by Robin Pronnier
** Login   <robin@epitech.net>
** 
** Started on  Fri Jun  9 19:56:54 2017 Robin Pronnier
** Last update Fri Jun  9 22:39:43 2017 Robin Pronnier
*/

#include "my.h"

int	check_sec_arg(char *str)
{
  int	i;

  i = 0;
  while (str[i] != '\0')
    {
      if ((str[i] != '-') & (str[i] < '0' || str[i] > '9'))
	return (-1);
      i = i + 1;
    }
  return (my_getnbr(str));
}

int	check_first_arg(char *str)
{
  int	i;

  i = 0;
  if (my_getnbr(str) <= 0 || my_getnbr(str) > 100)
    return (1);
  while (str[i] != '\0')
    {
      if (str[i] < '0' || str[i] > '9')
	return (1);
      i = i + 1;
    }
  return (0);
}
