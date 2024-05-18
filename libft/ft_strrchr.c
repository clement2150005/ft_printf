/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccolin <ccolin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 12:10:35 by ccolin            #+#    #+#             */
/*   Updated: 2024/05/04 11:19:07 by ccolin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strrchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	while (i != 0 && s[i] != (char)c)
		i--;
	if (s[i] == (char)c)
		return ((char *)&s[i]);
	return ((void *)0);
}

//#include <stdio.h>
//#include <string.h>

//int main() {
//    // Test case
//    const char str[] = "Hello, world!";
//    int search_char = 'o';
//    // Perform ft_strrchr
//    char *result_ft = ft_strrchr(str, search_char);
//    int position_ft = result_ft ? (result_ft - str) : -1;
//    // Perform original strrchr
//    char *result_std = strrchr(str, search_char);
//    int position_std = result_std ? (result_std - str) : -1;
//    // Print the results
//	printf("'%c' found in %d position ", search_char, position_ft);
//	printf("(ft_strrchr).\n");
//	printf("'%c' found in %d position ", search_char, position_std);
//	printf("(strrchr).\n");
//    // Compare the results
//    if (position_ft == position_std)
//        printf("Both functions produced the same result.\n");
//    else
//        printf("The functions produced different results.\n");
//    return 0;
//}