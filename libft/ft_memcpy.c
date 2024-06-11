/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccolin <ccolin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 11:21:58 by ccolin            #+#    #+#             */
/*   Updated: 2024/04/25 18:09:51 by ccolin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t				i;
	unsigned char		*ptr;
	const unsigned char	*ptr2;

	if (!dst && !src)
		return (dst);
	ptr = (unsigned char *)dst;
	ptr2 = (unsigned char *)src;
	i = 0;
	while (i < n)
	{
		ptr[i] = ptr2[i];
		i++;
	}
	return (dst);
}

//#include <stdio.h>

//int main() {
//    // Test cases
//    char src[] = "This is the source string.";
//    char dst[50];
//    // Print original destination string
//    printf("Before memcpy: %s\n", dst);
//    // Apply memcpy
//    ft_memcpy(dst, src, sizeof(src));
//    // Print modified destination string
//    printf("After memcpy: %s\n", dst);
//    return 0;
//}