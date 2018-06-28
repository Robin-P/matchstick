/*
** get_next_line.c for  in /home/robin/CPE_2016_stumper5
** 
** Made by Robin Pronnier
** Login   <robin@epitech.net>
** 
** Started on  Thu May 18 14:32:23 2017 Robin Pronnier
** Last update Mon Jun 12 21:08:15 2017 Robin Pronnier
*/

#include <stdlib.h>
#include <unistd.h>
#include "get_next_line.h"

char		get_char(int fd)
{
  static char	buffer[READ_SIZE + 1];
  static int	nb_letter;
  static int	count;
  char		letter;

  if (nb_letter == 0)
    {
      if ((nb_letter = read(fd, buffer, READ_SIZE)) == -1)
	return ('\0');
      count = 0;
    }
  if (nb_letter == 0)
    return ('\0');
  letter = buffer[count];
  count++;
  nb_letter--;
  return (letter);
}

char		*my_realloc(char *s)
{
  char		*new;
  int		i;

  i = 0;
  new = NULL;
  while (s[i] != '\0')
    ++i;
  if ((new = malloc(sizeof(char) * (i + READ_SIZE + 1))) == NULL)
    return (NULL);
  i = -1;
  while (s[++i] != '\0')
    new[i] = s[i];
  new[i] = '\0';
  free(s);
  return (new);
}

char		*free_s(char *s)
{
  free(s);
  return (NULL);
}

char		*get_next_line(int fd)
{
  char		*s;
  char		letter;
  int		count;

  count = 0;
  if ((s = malloc(sizeof(char) * (READ_SIZE + 1))) == NULL)
    return (NULL);
  s[0] = '\0';
  letter = get_char(fd);
  while (letter != '\0' && letter != '\n')
    {
      if (count == READ_SIZE)
	if ((s = my_realloc(s)) == NULL)
	  return (NULL);
      s[count] = letter;
      letter = get_char(fd);
      count++;
    }
  if (s[0] == '\0' && letter == '\0')
    return (free_s(s));
  s[count] = '\0';
  return (s);
}
