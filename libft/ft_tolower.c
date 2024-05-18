/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccolin <ccolin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 17:30:22 by ccolin            #+#    #+#             */
/*   Updated: 2024/04/21 11:59:35 by ccolin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_tolower(int c)
{
	if (c >= 'A' && c <= 'Z')
		c = c + 32;
	return (c);
}

//#include <stdio.h>
//#include <ctype.h>

//int main() {
//    // Test case
//    int c = 'A';
//    // Perform ft_tolower
//    int result_ft = ft_tolower(c);
//    // Perform original tolower
//    int result_std = tolower(c);
//    // Print the results as letters
//    printf("Result of ft_tolower: %c\n", result_ft);
//    printf("Result of tolower: %c\n", result_std);
//    // Compare the results
//    if (result_ft == result_std)
//        printf("Both functions produced the same result.\n");
//    else
//        printf("The functions produced different results.\n");
//    return 0;
//}