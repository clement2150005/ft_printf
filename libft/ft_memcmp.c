/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccolin <ccolin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 13:02:27 by ccolin            #+#    #+#             */
/*   Updated: 2024/04/30 09:42:49 by ccolin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t				i;
	const unsigned char	*str1;
	const unsigned char	*str2;

	i = 0;
	str1 = (const unsigned char *)s1;
	str2 = (const unsigned char *)s2;
	if (n == 0)
		return (0);
	while (str2[i] == str1[i] & i < n - 1)
		i++;
	return (str1[i] - str2[i]);
}
//#include <stdio.h>
//#include <string.h>

//int main() {
//    // Test case
//    const char str1[] = "123";
//    const char str2[] = "124";
//    size_t n = 3;

//    // Testing ft_memcmp
//    int result_ft = ft_memcmp(str1, str2, n);
//    printf("Result of ft_memcmp: %d\n", result_ft);

//    // Testing original memcmp
//    int result_std = memcmp(str1, str2, n);
//    printf("Result of memcmp: %d\n", result_std);

//    return 0;
//}