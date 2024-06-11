/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccolin <ccolin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 13:17:22 by ccolin            #+#    #+#             */
/*   Updated: 2024/04/28 16:24:14 by ccolin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*ptr;
	unsigned char	*ptr2;
	size_t			i;

	if (dst == NULL && src == NULL)
		return (dst);
	i = len;
	ptr = (unsigned char *)dst;
	ptr2 = (unsigned char *)src;
	if (ptr2 < ptr)
		while (len-- > 0)
			ptr[len] = ptr2[len];
	else
	{
		i = 0;
		while (i < len)
		{
			ptr[i] = ptr2[i];
			i++;
		}
	}
	return (dst);
}

//#include <stdio.h>

//int main() {
//    // Test cases
//    char src[] = "This is the source string.";
//    char dst[50];
//    // Print original destination string
//    printf("Before memmove: %s\n", dst);
//    // Apply memmove
//    ft_memmove(dst, src, sizeof(src));
//    // Print modified destination string
//    printf("After memmove: %s\n", dst);
//    return 0;
//}