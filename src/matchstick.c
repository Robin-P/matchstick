/*
** matchstick.c for  in /home/robin/delivery/CPE/CPE_2016_matchstick
** 
** Made by Robin Pronnier
** Login   <robin@epitech.net>
** 
** Started on  Fri Jun  9 17:52:23 2017 Robin Pronnier
** Last update Sun Jun 11 19:06:00 2017 Robin Pronnier
*/

#include <stdlib.h>
#include <unistd.h>
#include "my.h"

static int		check_col_atk2(char **map, int lin_stick,
				       int nb_stick, int max_stick)
{
  if (nb_stick <= 0)
    return (my_puterr("Error: you have to remove at least one match\n", 1));
  else if (nb_stick > max_stick)
    {
      my_printf("Error: you cannot remove more than %d ", max_stick);
      return (my_puterr("matches per turn\n", 1));
    }
  else if (nb_stick > strlenstick(map[lin_stick]))
    return (my_puterr("Error: not enough matches on this line\n", 1));
  else
    {
      my_printf("Player removed %d match(es)", nb_stick);
      my_printf(" from line %d\n", lin_stick);
      map = remove_sticks(map, lin_stick, nb_stick);
    }
  return (0);
}

static int		check_col_atk(char **map, int lin_stick, int max_stick)
{
  char			*str;
  int			nb_stick;

  my_putstr("Matches: ");
  if ((str = get_next_line(0)) == NULL)
    return (-1);
  if (str[0] == '\0' || ((nb_stick = check_sec_arg(str)) == -1))
    {
      free(str);
      my_putstr("Error: invalid input ");
      return (my_puterr("(positive number expected)\n", 1));
    }
  free(str);
  return (check_col_atk2(map, lin_stick, nb_stick, max_stick));
}

int			check_lin_atk(char **map, int nb_lin, int max_stick)
{
  int			lin;
  char			*str;

  my_putstr("Line: ");
  if (((str = get_next_line(0)) == NULL))
    return (-1);
  if (str[0] == '\0' || ((lin = check_sec_arg(str)) == -1))
    {
      free(str);
      my_putstr("Error: invalid input ");
      return (my_puterr("(positive number expected)\n", 1));
    }
  free(str);
  if ((lin <= 0) || (lin > nb_lin))
    return (my_puterr("Error: this line is out of range\n", 1));
  else
    return (check_col_atk(map, lin, max_stick));
}

int			turn_based(char **map, int nb_lin, int max_stick)
{
  int			turn;
  int			ret;

  turn = -1;
  if ((map = malloc_map(map, nb_lin)) == NULL)
    return (84);
  while (end(map) != 0)
    {
      ret = 0;
      if (++turn % 2 == 0)
	{
	  my_putstr("\nYour turn:\n");
	  while ((ret = check_lin_atk(map, nb_lin, max_stick)) == 1);
	}
      else
	{
	  my_putstr("\nAI's turn...\n");
	  bot(map, max_stick, nb_lin);
	}
      if (ret == -1)
	return (free_tab(map));
      my_show_tab(map);
    }
  free_tab(map);
  return (returns(turn + 1));
}
