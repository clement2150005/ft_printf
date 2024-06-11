/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccolin <ccolin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 13:17:57 by ccolin            #+#    #+#             */
/*   Updated: 2024/05/06 19:29:51 by ccolin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;
	char	*str;

	if (len == 0 && haystack == NULL)
		return (0);
	str = (char *)haystack;
	i = 0;
	if (*needle == '\0' || needle == NULL)
		return (str);
	while (str[i] && i < len)
	{
		j = 0;
		while (str[i + j] == needle[j] && i + j < len)
		{
			if (needle[j + 1] == '\0')
				return (&str[i]);
			j++;
		}
		i++;
	}
	return (NULL);
}

//#include <string.h>
//#include <stdio.h>

//int main(void) {
//    const char *haystack = "abc";
//    const char *needle = "abcdef";
//    size_t len = 3;

//    // Call ft_strnstr
//    char *ft_result = ft_strnstr(haystack, needle, len);

//    // Call strnstr for comparison
//    char *orig_result = strnstr(haystack, needle, len);

//    printf("ft_strnstr return value: %s\n", ft_result);
//    printf("strnstr return value  : %s\n", orig_result);

//    return 0;
//}