/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_backquotes.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: videsvau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/01 07:30:31 by videsvau          #+#    #+#             */
/*   Updated: 2018/02/05 17:19:56 by videsvau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/header.h"

void		concat_inp(t_inp **inp, t_inp **ret, t_inpl *inpl)
{
	t_inp	*cp;

	if ((cp = (*inp)))
	{
		while (cp)
		{
			if (cp->c == '\\' && !cp->next && inpl->next)
				;
			else
				inp_insert_posat(ret, cp->c);
			if (!cp->next)
				if (inpl->next)
					if (cp->c != '\\')
						inp_insert_posat(ret, '\n');
			cp = cp->next;
		}
	}
}

t_inp		*concat_inpl(t_inpl **inpl, t_sh *sh)
{
	t_inpl	*cp;
	t_inp	*ret;

	ret = NULL;
	sh->posy = sh->posy;
	if ((cp = (*inpl)))
	{
		while (cp)
		{
			concat_inp(&cp->inp, &ret, cp);
			cp = cp->next;
		}
	}
	return (ret);
}

int			empty_inp(t_inp **inp)
{
	t_inp	*cp;
	int		i;

	i = 0;
	if ((cp = (*inp)))
	{
		while (cp)
		{
			if (!is_space(cp->c))
				i++;
			cp = cp->next;
		}
	}
	return (i);
}

void		parse(t_sh *sh)
{
	t_inp	*clean;

	clean = concat_inpl(&sh->inpl, sh);
	history_push_front(&sh->history, clean, sh);
	if (empty_inp(&clean))
	{
		lexer_parser(&clean, sh);
		custom_return();
	}
	free_list_from_beginning(&clean);
}
