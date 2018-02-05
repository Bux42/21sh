/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whats_going_on.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: videsvau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/07 17:55:43 by videsvau          #+#    #+#             */
/*   Updated: 2018/02/05 17:42:33 by videsvau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/header.h"

void		exec_cli_lst(char *inp, t_sh *sh)
{
	t_tok	*tmp;
	char	**split_alt;

	tmp = NULL;
	split_alt = splitter_alt(inp);
	ft_putstr(inp);
	sh->posy = sh->posy;
}

void		lexer_parser(t_inp **inp, t_sh *sh)
{
	t_inp	*cp;
	int		len;
	char	*conv;

	len = 0;
	if ((cp = (*inp)))
	{
		while (cp)
		{
			len++;
			cp = cp->next;
		}
		if (!(conv = (char*)malloc(sizeof(char) * (len + 1))))
			return ;
		conv[len] = '\0';
		cp = *inp;
		len = 0;
		while (cp)
		{
			conv[len++] = cp->c;
			cp = cp->next;
		}
		exec_cli_lst(conv, sh);
		free(conv);
	}
}
