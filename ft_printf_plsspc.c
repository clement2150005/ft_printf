/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plusspace.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccolin <ccolin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 13:33:08 by ccolin            #+#    #+#             */
/*   Updated: 2024/06/11 13:51:01 by ccolin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_pls_spc(char *str, t_opts *opts)
{
	int		i;
	int		j;
	char	*result;

	i = 0;
	j = 0;
	if (opts->fmt != 'd' && opts->fmt != 'i')
		return (str);
	result = ft_calloc((ft_strlen(str) + 2), sizeof(char));
	if (!result)
		return (NULL);
	if (str[0] != '-')
		if (opts->plssgn != 0)
			result[j++] = '+';
	if (opts->spc != 0 && opts->plssgn == 0 && str[0] != '-')
		result[j++] = ' ';
	while (str[i])
		result[j++] = str[i++];
	result[j] = '\0';
	free(str);
	return (result);
}
