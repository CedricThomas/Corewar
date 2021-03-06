/*
** st.c for corewar-vm in /home/nicolaspolomack/cpe/2/CPE_2016_corewar/corewar
** 
** Made by Nicolas Polomack
** Login   <nicolas.polomack@epitech.eu>
** 
** Started on  Thu Mar 23 17:02:39 2017 Nicolas Polomack
** Last update Sat Apr  1 20:36:16 2017 Nicolas Polomack
*/

#include "corewar.h"
#include "my.h"
#include "op.h"

void	st(t_game *g, t_heads *h, t_ins *in)
{
  int	val;
  int	pos;

  val = h->reg[in->val[0] - 1];
  if (in->type[1] == 1)
    {
      h->reg[in->val[1] - 1] = val;
      return ;
    }
  pos = h->pos + in->val[1];
  pos %= MEM_SIZE;
  while (pos < 0)
    pos += MEM_SIZE;
  swap_endian(&val, sizeof(int));
  my_strncpy((char *)g->arena + pos, (char *)&val, sizeof(int));
}
