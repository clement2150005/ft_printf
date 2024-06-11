/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccolin <ccolin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 13:34:54 by ccolin            #+#    #+#             */
/*   Updated: 2024/06/11 13:41:53 by ccolin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_count_putstr(char *str, t_opts *opts)
{
	int	i;
	int	count;

	count = 0;
	i = 0;
	if (str[0] == 0 && opts->fmt == 'd')
		return (0);
	if (str[0] == 0 && opts->prec == -1)
		count += ft_count_putchar(str[0]);
	while (str[i])
		count += ft_count_putchar(str[i++]);
	if (opts->chrnll == 1 && opts->rjust != 0 && opts->fmt != '%')
		count += ft_count_putchar('\0');
	return (count);
}

int	ft_count_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}
