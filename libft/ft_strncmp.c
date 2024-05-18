/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccolin <ccolin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 12:14:26 by ccolin            #+#    #+#             */
/*   Updated: 2024/05/06 10:12:52 by ccolin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	if (n == 0)
		return (0);
	if (s1[i] == '\0' || s2[i] == '\0')
		return ((const unsigned char)s1[i] - (const unsigned char)s2 [i]);
	while (i < n && s1[i] && s2[i] == s1[i])
		i++;
	if (i == n || (s1[i] == '\0' && s2[i] == '\0'))
		return (0);
	return ((const unsigned char)s1[i] - (const unsigned char)s2 [i]);
}

//#include <stdio.h>
//#include <string.h>

//int main() {
//    // Test case
//    const char str1[] = "Hello";
//    const char str2[] = "Hello";
//    size_t n = 5;
//    // Perform strncmp
//    int result_ft = ft_strncmp(str1, str2, n);
//    // Perform original strncmp
//    int result_std = strncmp(str1, str2, n);
//    // Print the results
//    printf("Result of ft_strncmp: %d\n", result_ft);
//    printf("Result of strncmp: %d\n", result_std);
//    // Compare the results
//    if (result_ft == result_std)
//        printf("Both functions produced the same result.\n");
//    else
//        printf("The functions produced different results.\n");
//    return 0;
//}