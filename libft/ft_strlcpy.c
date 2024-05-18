/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccolin <ccolin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 14:40:30 by ccolin            #+#    #+#             */
/*   Updated: 2024/04/26 11:50:10 by ccolin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

unsigned int	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;

	if (dstsize == 0)
		return (ft_strlen(src));
	i = 0;
	while (i != dstsize - 1 && src[i])
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (ft_strlen(src));
}

//#include <stdio.h>
//#include <string.h>

//int main() {
//    // Test cases
//    char dst1[20], dst2[20];
//    const char src[] = "Hello, world!";
//    // Perform ft_strlcpy
//    size_t result_ft = ft_strlcpy(dst1, src, sizeof(dst1));
//    // Perform strlcpy
//    size_t result_std = strlcpy(dst2, src, sizeof(dst2));
//    // Print the results
//    printf("Copied string (ft_strlcpy): %s\n", dst1);
//    printf("Result (ft_strlcpy): %zu\n", result_ft);
//    printf("Copied string (strlcpy): %s\n", dst2);
//    printf("Result (strlcpy): %zu\n", result_std);
//    // Compare the results
//    if (result_ft == result_std && strcmp(dst1, dst2) == 0)
//        printf("Both functions produced the same result.\n");
//    else
//        printf("The functions produced different results.\n");
//    return 0;
//}