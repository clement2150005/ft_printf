/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccolin <ccolin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 10:50:57 by ccolin            #+#    #+#             */
/*   Updated: 2024/04/29 18:03:49 by ccolin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*substr;

	i = 0;
	if (start >= (unsigned int)ft_strlen(s) || len <= 0)
		return (ft_strdup(""));
	if (len > ft_strlen(s) - start)
		len = ft_strlen(s) - start;
	substr = malloc(sizeof(char) * len + 1);
	if (substr == NULL)
		return (NULL);
	while (i < len)
		substr[i++] = s[start++];
	substr[i] = '\0';
	return (substr);
}
//#include <stdio.h>

//int main()
//{
//    // Test string
//    char str[] = "This is a test string.";

//    // Test parameters
//    unsigned int start = 5;
//    size_t len = 7;

//    // Call ft_substr
//    char *result = ft_substr(str, start, len);

//    // Check if result is NULL
//    if (result == NULL)
//    {
//        printf("ft_substr returned NULL\n");
//        return 1;
//    }

//    // Print the result
//    printf("Substring: %s\n", result);

//    // Free memory
//    free(result);

//    return 0;
//}