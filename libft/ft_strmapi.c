/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccolin <ccolin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 14:53:29 by ccolin            #+#    #+#             */
/*   Updated: 2024/04/25 15:51:33 by ccolin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_len(const char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	int		i;
	char	*result;

	i = 0;
	result = malloc(sizeof(char) * ft_len((char *)s) + 1);
	if (result == NULL)
		return (NULL);
	while (s[i])
	{
		result[i] = f(i, s[i]);
		i++;
	}
	result[i] = '\0';
	return (result);
}
//#include <stdio.h>
//#include <stdlib.h>

//char capitalize(unsigned int index, char c)
//{
//    // Just voiding the index parameter to remove the compiler warning
//    (void)index;

//    // Only capitalize if the character is a lowercase letter
//    if (c >= 'a' && c <= 'z')
//        return c - 32; // Convert to uppercase
//    else
//        return c; // Return unchanged
//}

//int main()
//{
//    char *test_string = "hello world";
//    char *capitalized_string = ft_strmapi(test_string, &capitalize);

//    if (capitalized_string == NULL)
//    {
//        printf("Memory allocation failed.\n");
//        return 1;
//    }

//    printf("Original string: %s\n", test_string);
//    printf("Capitalized string: %s\n", capitalized_string);

//    // Don't forget to free the allocated memory
//    free(capitalized_string);

//    return 0;
//}