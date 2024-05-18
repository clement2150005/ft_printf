/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccolin <ccolin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 12:10:35 by ccolin            #+#    #+#             */
/*   Updated: 2024/05/04 11:37:32 by ccolin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*str;
	unsigned char	ch;

	str = (unsigned char *)s;
	ch = (unsigned char)c;
	i = 0;
	while (i < n)
	{
		if (str[i] == ch)
			return ((void *)&str[i]);
		i++;
	}
	return ((void *)0);
}

// #include <stdio.h>
// #include <string.h>

// int main() {
// 	const char *str;
//    str = ft_memchr("bonjourno", 'n', 2);
// 		if (!str)
// 			ft_print_result("NULL");
// 		else
// 			ft_print_result(str);
// }