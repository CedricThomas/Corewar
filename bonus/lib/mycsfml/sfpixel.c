/*
** sfpixel.c for sfpixel in /home/nicolaspolomack/mylibcsfml/
**
** Made by Nicolas Polomack
** Login   <nicolas.polomack@epitech.eu>
**
** Started on  Fri Nov 18 19:24:57 2016 Nicolas Polomack
** Last update Sun Apr  2 03:07:21 2017 Nicolas Polomack
*/

#include <stdlib.h>
#include <SFML/Graphics.h>
#include <SFML/System.h>
#include <math.h>
#include "sfcaster.h"

void	put_pixel(t_my_framebuffer *buffer, int x,
		  int y, sfColor color)
{
  int	i;

  if (x >= 0 && x < buffer->width && y >= 0 && y < buffer->height)
    {
      i = ((buffer->width * y) + x) * 4;
      buffer->pixels[i] = color.r;
      buffer->pixels[i + 1] = color.g;
      buffer->pixels[i + 2] = color.b;
      buffer->pixels[i + 3] = color.a;
    }
}

void	draw_square(t_my_framebuffer *buffer, sfVector2i pos,
		    sfVector2i sizes, sfColor color)
{
  int	startY;
  int	startX;

  startY = pos.y;
  startX = pos.x;
  while (pos.x - startX <= sizes.x)
    {
      pos.y = startY;
      while (pos.y - startY <= sizes.y)
	put_pixel(buffer, pos.x, pos.y++, color);
      pos.x += 1;
    }
}

void		draw_line(t_my_framebuffer *buffer,
			  sfVector2f *from, sfVector2f *to,
			  sfColor color)
{
  sfVector2f	unit;
  float		norme;
  float		i;

  i = 0;
  unit.x = to->x - from->x;
  unit.y = to->y - from->y;
  norme = ceilf(sqrt(pow(unit.x, 2) + pow(unit.y, 2)));
  unit.x /= norme;
  unit.y /= norme;
  while (i <= norme)
    {
      put_pixel(buffer, from->x + unit.x * i,
		from->y + unit.y * i, color);
      i += 1;
    }
  free(from);
  free(to);
}
