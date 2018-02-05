/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: videsvau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/05 17:38:52 by videsvau          #+#    #+#             */
/*   Updated: 2018/02/05 17:39:02 by videsvau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/libft.h"

void			*ft_realloc(void *inp_o, int qty)
{
	int			i;
	char		*inp;
	char		*outp;

	inp = (char *)inp_o;
	if (!(outp = ft_strnew(qty)))
		return (NULL);
	i = -1;
	while (++i < qty)
		outp[i] = inp[i];
	free(inp);
	return (outp);
}
