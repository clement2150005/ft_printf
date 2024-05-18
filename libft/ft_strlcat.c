/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccolin <ccolin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 14:40:30 by ccolin            #+#    #+#             */
/*   Updated: 2024/04/29 17:13:20 by ccolin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

unsigned int	ft_strlcat(char *dst, const char *src, unsigned int dstsize)
{
	unsigned int	i;
	unsigned int	j;

	i = 0;
	j = 0;
	while (i < dstsize && dst[i])
		i++;
	while (i + j + 1 < dstsize && src[j])
	{
		dst[i + j] = src[j];
		j++;
	}
	if (i != dstsize)
		dst[i + j] = '\0';
	return (i + ft_strlen(src));
}

// #include <stdio.h>
// #include <string.h>

// int main() {
//    // Test cases
//    char dst[20] = "Hello ";
//    const char src[] = "world!";
//    // Perform strlcat
//    unsigned int result = ft_strlcat(dst, src, sizeof(dst));
//    // Print the result
//    printf("Concatenated string: %s\n", dst);
//    printf("Result: %u\n", result);
//    return 0;
// }