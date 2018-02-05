/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whats_going_on.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: videsvau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/07 17:55:43 by videsvau          #+#    #+#             */
/*   Updated: 2018/02/05 17:21:32 by videsvau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/header.h"

void		lexer_parser(t_inp **inp, t_sh *sh)
{
	t_inp	*cp;
	t_tok	*tokens;

	tokens = NULL;
	sh->posy = sh->posy;
	if ((cp = (*inp)))
	{
		while (cp)
		{
			ft_putchar(cp->c);
			cp = cp->next;
		}
	}
}
