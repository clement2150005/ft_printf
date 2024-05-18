/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccolin <ccolin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 11:21:58 by ccolin            #+#    #+#             */
/*   Updated: 2024/04/21 11:34:20 by ccolin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	size_t			i;
	unsigned char	*ptr;

	ptr = (unsigned char *)b;
	i = 0;
	while (i < len)
		ptr[i++] = c;
	return (b);
}

//#include <stdio.h>

//int main() {
//    // Test case
//    char str[50];

//    // Print original string
//    printf("Before memset: %s\n", str);
//    // Apply memset
//    ft_memset(str, '*', 10);
//    // Print modified string
//    printf("After memset: %s\n", str);
//    return 0;
//}