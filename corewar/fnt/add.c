/*
** add.c for corewar-vm in /home/nicolaspolomack/cpe/2/CPE_2016_corewar/corewar
** 
** Made by Nicolas Polomack
** Login   <nicolas.polomack@epitech.eu>
** 
** Started on  Thu Mar 23 18:11:31 2017 Nicolas Polomack
** Last update Fri Mar 24 18:27:17 2017 Arthur Knoepflin
*/

#include "corewar.h"
#include "my.h"

void	add(t_game *g, t_heads *h, t_ins *in)
{
  h->reg[in->val[2] - 1] = h->reg[in->val[0] - 1] + h->reg[in->val[1] - 1];
}

