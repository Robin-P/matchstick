/*
** matchstick2.c for  in /home/robin/delivery/CPE/CPE_2016_matchstick
** 
** Made by Robin Pronnier
** Login   <robin@epitech.net>
** 
** Started on  Fri Jun  9 18:38:12 2017 Robin Pronnier
** Last update Sat Jun 10 22:06:20 2017 Robin Pronnier
*/

#include <stdlib.h>
#include <unistd.h>
#include "my.h"

int	end(char **map)
{
  int	i;
  int	j;

  i = 1;
  while (map[i + 1] != NULL)
    {
      j = 0;
      while (map[i][j] != '\0')
	if (map[i][j++] == '|')
	  return (-1);
      ++i;
    }
  return (0);
}

int	returns(int i)
{
  if (i % 2 == 1)
    {
      my_putstr("You lost, too bad...\n");
      return (2);
    }
  else
    {
      my_putstr("I lost... snif... but I'll get you next time!!\n");
      return (1);
    }
}

char	**remove_sticks(char **map, int line, int nb_matches)
{
  int	i;

  i = my_strlen(map[line]);
  while (map[line][i] != '|')
    --i;
  while (nb_matches != 0)
    {
      map[line][i--] = ' ';
      --nb_matches;
    }
  return (map);
}

int	strlenstick(char *str)
{
  int	i;
  int	nb_sticks;

  i = 1;
  nb_sticks = 0;
  while (str[i] != '\0' && str[i] != '*')
    {
      if (str[i] == '|')
	++nb_sticks;
      ++i;
    }
  return (nb_sticks);
}
