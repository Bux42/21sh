/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_delete_letter.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: videsvau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/12 06:31:34 by videsvau          #+#    #+#             */
/*   Updated: 2018/02/04 19:52:51 by videsvau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/header.h"

void		overwrite_remaining(t_sh *sh, t_inp **inp)
{
	t_inp	*cp;
	int		nb;
	int		i;
	char	buff[sh->width];

	nb = 0;
	i = -1;
	ft_bzero(buff, sh->width);
	if ((cp = get_to_pos(inp)))
	{
		while (cp->next && (nb++ > -1))
		{
			buff[++i] = cp->next->c;
			if (sh->posy == sh->width)
			{
				ft_putstr(buff);
				ft_bzero(buff, sh->width);
				i = -1;
				ft_putchar(' ');
				ft_putstr(tgetstr("le", NULL));
				sh->posy = 1;
			}
			else
				sh->posy++;
			cp = cp->next;
		}
		ft_putstr(buff);
		sh->diff = nb;
		while (nb > sh->width)
		{
			nb -= sh->width;
			sh->posy -= sh->width;
			ft_putstr(tgetstr("up", NULL));
		}
		while (nb--)
			custom_left(sh);
	}
}

void		overwrite_deleted(t_sh *sh, t_inp **inp)
{
	t_inp	*cp;
	int		dec;

	dec = 0;
	if ((cp = get_to_pos(inp)))
	{
		if (cp->pos == 2 && (dec++ > -1))
			custom_right(sh);
		while (cp->next && (dec++ > -1))
		{
			ft_putchar(cp->next->c);
			check_endline(sh);
			cp = cp->next;
		}
	}
	ft_putchar(' ');
	check_endline(sh);
	custom_left(sh);
	while (dec--)
		custom_left(sh);
}

void		delete_beginning(t_inp **inp, t_inp *cp)
{
	if (cp->next)
	{
		(*inp) = (*inp)->next;
		(*inp)->previous = NULL;
		(*inp)->pos = 2;
		free(cp);
	}
	else
	{
		free((*inp));
		(*inp) = NULL;
	}
}

void		delete_letter(t_sh *sh, t_inp **inp)
{
	t_inp	*cp;

	if ((cp = get_to_pos(inp)))
	{
		if (cp->pos == 1)
		{
			custom_left(sh);
			if (cp->previous)
			{
				cp->previous->next = cp->next;
				cp->previous->pos = 1;
				if (cp->next)
					cp->next->previous = cp->previous;
				free(cp);
			}
			else
				delete_beginning(inp, cp);
			overwrite_deleted(sh, inp);
		}
	}
}

void		add_delete_letter(t_sh *sh)
{
	if (sh->buff[0] != 127)
	{
		ft_putchar(sh->buff[0]);
		check_endline(sh);
		inp_insert_posat(&sh->inpl->inp, sh->buff[0]);
		overwrite_remaining(sh, &sh->inpl->inp);
	}
	else
		delete_letter(sh, &sh->inpl->inp);
}
