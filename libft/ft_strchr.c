/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccolin <ccolin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 17:40:48 by ccolin            #+#    #+#             */
/*   Updated: 2024/05/04 11:17:36 by ccolin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i] && s[i] != (char)c)
		i++;
	if (s[i] == (char)c)
		return ((char *)&s[i]);
	return ((void *)0);
}

//#include <stdio.h>

//int main() {
//    // Test case
//    const char str[] = "01234a6789";
//    int search_char = 'a';
//    // Search for the character
//    char *result = ft_strchr(str, search_char);
//    // Print the result
//    if (result != NULL)
//        printf("'%c' found at position: %ld\n", search_char, result - str);
//    else
//        printf("'%c' not found.\n", search_char);
//    return 0;
//}