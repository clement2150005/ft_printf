/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccolin <ccolin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 11:13:44 by ccolin            #+#    #+#             */
/*   Updated: 2024/04/25 15:31:36 by ccolin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

//#include <stdio.h>
//#include <string.h>

//int main() {
//    // Test case
//    const char str[] = "Hello, world!";
//    // Perform ft_strlen
//    int result_ft = ft_strlen(str);
//    // Perform original strlen
//    int result_std = strlen(str);
//    // Print the results
//    printf("Length of string (ft_strlen): %d\n", result_ft);
//    printf("Length of string (strlen): %d\n", result_std);
//    // Compare the results
//    if (result_ft == result_std)
//        printf("Both functions produced the same result.\n");
//    else
//        printf("The functions produced different results.\n");
//    return 0;
//}