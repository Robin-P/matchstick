/*
** functions.c for  in /home/robin/delivery/CPE/CPE_2016_matchstick/src
** 
** Made by Robin Pronnier
** Login   <robin@epitech.net>
** 
** Started on  Fri Jun  9 19:49:20 2017 Robin Pronnier
** Last update Sat Jun 10 21:18:29 2017 Robin Pronnier
*/

#include <stdlib.h>
#include <unistd.h>
#include "my.h"

int	my_puterr(char *str, int x)
{
  write(1, str, my_strlen(str));
  return (x);
}

int	my_getnbr(char *str)
{
  int	x;
  int	y;
  int	z;

  x = 1;
  y = 0;
  z = 214748364;
  while (*str == 45 || *str == 43)
    {
      if (*str == 45)
	x = x * (-1);
      str = str + 1;
    }
  while (*str != '\0' && *str >= 48 && *str <= 57)
    {
      if (y > z || (y == z && *str > 7 && x == 1)
	  || (y == z && *str > 0 && x == -1))
	return (0);
      y = y * 10 + *str - 48;
      str = str + 1;
    }
  if (x == -1)
    y = y * -1;
  return (y);
}

void	my_show_tab(char **av)
{
  int	i;

  i = 0;
  while (av[i] != '\0')
    {
      my_printf("%s\n", av[i]);
      ++i;
    }
}

int	free_tab(char **av)
{
  int	i;

  i = 0;
  while (av[i])
    {
      free(av[i]);
      ++i;
    }
  free(av);
  return (0);
}
