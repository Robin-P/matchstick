/*
** my_map.c for  in /home/robin/delivery/CPE/CPE_2016_matchstick
** 
** Made by Robin Pronnier
** Login   <robin@epitech.net>
** 
** Started on  Fri Jun  9 18:03:30 2017 Robin Pronnier
** Last update Sun Jun 11 12:31:22 2017 Robin Pronnier
*/

#include <stdlib.h>
#include "my.h"

static char	**put_stick(char **map, int nb_lin)
{
  int		i;
  int		line;
  int		sticks;
  int		tour;

  tour = 0;
  sticks = 1;
  i = 0;
  line = nb_lin * 2 - 1;
  while (map[i] != NULL)
    ++i;
  i = i - 2;
  while (line > 0)
    {
      while (sticks < (line + 1))
	map[i][sticks++] = '|';
      ++tour;
      sticks = 1 + tour;
      --line;
      --i;
    }
  return (map);
}

static char	*put_stars(char *str, int nb_lin)
{
  int		i;

  i = 0;
  while (i != nb_lin * 2 + 1)
    str[i++] = '*';
  str[i] = '\0';
  return (str);
}

static char	**create_map(char **map, int nb_lin)
{
  int		i;
  int		j;

  i = 0;
  while (++i != (nb_lin + 1))
    {
      j = 0;
      map[i][j] = '*';
      while (j != nb_lin * 2)
	map[i][++j] = ' ';
      map[i][j] = '*';
      map[i][j + 1] = '\0';
    }
  map[i + 1] = NULL;
  put_stick(map, nb_lin);
  return (map);
}

char		**malloc_map(char **map, int nb_lin)
{
  int		i;

  i = 0;
  if ((map = malloc(sizeof(char *) * (nb_lin + 2 + 1))) == NULL)
    return (NULL);
  while (i < (nb_lin + 2))
    {
      if ((map[i] = malloc(sizeof(char) * (nb_lin * 2 + 2))) == NULL)
	return (NULL);
      if ((i == 0) || (i == nb_lin + 1))
	map[i] = put_stars(map[i], nb_lin);
      ++i;
    }
  map[i] = NULL;
  map = create_map(map, nb_lin);
  my_show_tab(map);
  return (map);
}
