/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccolin <ccolin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 17:30:22 by ccolin            #+#    #+#             */
/*   Updated: 2024/04/21 12:00:15 by ccolin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_toupper(int c)
{
	if (c >= 'a' && c <= 'z')
		c = c - 32;
	return (c);
}

//#include <stdio.h>
//#include <ctype.h>

//int main() {
//    // Test case
//    int c = 'a';
//    // Perform ft_toupper
//    int result_ft = ft_toupper(c);
//    // Perform original toupper
//    int result_std = toupper(c);
//    // Print the results as letters
//    printf("Result of ft_toupper: %c\n", result_ft);
//    printf("Result of toupper: %c\n", result_std);
//    // Compare the results
//    if (result_ft == result_std)
//        printf("Both functions produced the same result.\n");
//    else
//        printf("The functions produced different results.\n");
//    return 0;
//}