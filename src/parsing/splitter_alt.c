/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pre_interpret.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vboivin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/23 04:06:33 by vboivin           #+#    #+#             */
/*   Updated: 2018/02/05 17:40:30 by videsvau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/header.h"

static int			quotes_count(char *inp)
{
	int				i;
	int				count;

	i = -1;
	count = 0;
	while (inp[++i])
	{
		if (inp[i] == '\\' && inp[i + 1] != 0)
			i++;
		else if (inp[i] == '"')
			count++;
		if (!inp[i])
			break ;
	}
	return (count);
}

static void			get_quoted_wd(char* inp, char *outp,
						int i_inp[], int io_inp[])
{
	int				i;
	int				io;

	i = *i_inp;
	io = *io_inp;
	outp[io++] = inp[i];
	while (inp[++i] != '"')
	{
		if (inp[i] == '\\')
			i++;
		outp[io++] = inp[i];
	}
	outp[io++] = inp[i];
	*i_inp = i;
	*io_inp = io;
}

static char			*create_wd(char *inp, int qty)
{
	char			*outp;
	int				i;
	int				io;

	outp = ft_strnew(qty + 1);
	i = 0;
	io = 0;
	while (inp[i] && inp[i] > 32)
	{
		if (inp[i] == '"' && (i == 0 || inp[i - 1] != '\\'))
			get_quoted_wd(inp, outp, &i, &io);
		else
			outp[io++] = inp[i];
		i++;
	}
	return (outp);
}

static int			get_wd(char *inp, char **to_set)
{
	int				i;

	i = -1;
	while (inp[++i])
	{
		if (inp[i] == '\\')
			i += 2;
		else if (inp[i] == '"')
		{
			i++;
			while (inp[i] != '"')
			{
				if (inp[i] == '\\')
					i++;
				i++;
			}
		}
		if (inp[i] <= 32)
			break ;
	}
	if (i > 0)
		*to_set = create_wd(inp, i + 2);
	return (i);
}

char				**splitter_alt(char *inp)
{
	int				i;
	int				io;
	char			**outp;

	i = 0;
	io = 0;
	if (!(outp = malloc(sizeof(char *) * 6)))
		return (NULL);
	ft_bzero(outp, sizeof(char *) * 6);
	if ((quotes_count(inp) % 2))
	{
		ft_putstr("Invalid amout of quotes.\n");
		return (NULL);
	}
	while (inp[i])
	{
		while (inp[i] && inp[i] <= 32)
			i++;
		i += get_wd(inp + i, &(outp[io++]));
		if (!(i % 5) && i != 0)
			outp = ft_realloc(outp, sizeof(char *) * (i + 6));
	}
	outp[io] = NULL;
	return (outp);
}
