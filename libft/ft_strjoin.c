/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccolin <ccolin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 10:56:20 by ccolin            #+#    #+#             */
/*   Updated: 2024/04/25 10:59:37 by ccolin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static size_t	ft_len(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	j = 0;
	str = malloc((ft_len(s1) + ft_len(s2) + 1) * sizeof(char));
	if (str == NULL)
		return (NULL);
	while (s1[i])
	{
		str[j++] = s1[i++];
	}
	i = 0;
	while (s2[i])
	{
		str[j++] = s2[i++];
	}
	str[j] = '\0';
	return (str);
}

//#include <stdio.h> // For printf

//int main() {
//    // Input strings
//    char const *s1 = "Hello";
//    char const *s2 = " world!";

//    // Call ft_strjoin and store the result
//    char *result = ft_strjoin(s1, s2);

//    // Check if memory allocation failed
//    if (result == NULL) {
//        printf("\033[0;31mMemory allocation failed. Unable"
//	" to concatenate strings.\033[0m\n");
//        return 1;
//    }

//    // Print the input strings and the concatenated string
//    printf("\033[0;36mInput string 1: %s\033[0m\n", s1);
//    printf("\033[0;36mInput string 2: %s\033[0m\n", s2);
//    printf("\033[0;32mConcatenated string: %s\033[0m\n", result);

//    // Free allocated memory
//    free(result);

//    return 0;
//}