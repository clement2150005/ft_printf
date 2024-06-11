/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccolin <ccolin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 11:21:58 by ccolin            #+#    #+#             */
/*   Updated: 2024/04/21 11:12:07 by ccolin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	size_t			i;
	unsigned char	*ptr;

	ptr = (unsigned char *)s;
	i = 0;
	while (i < n)
		ptr[i++] = 0;
}

//#include <stdio.h>
//#include <string.h>

//int	main(void)
//{
//	char str[] = "123567890";

//	printf("Before bzero: %s\n", str);
//	ft_bzero(str, strlen(str));
//	printf("After bzero: %s\n", str);
//	return (0);
//}