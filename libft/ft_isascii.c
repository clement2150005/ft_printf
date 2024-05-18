/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccolin <ccolin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 16:07:38 by ccolin            #+#    #+#             */
/*   Updated: 2024/04/21 11:16:02 by ccolin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isascii(int c)
{
	if (c >= 0 && c <= 127)
		return (1);
	return (0);
}

//#include <stdio.h>

//int main() {
//    // Test cases
//    size_t test_cases[] = {65, 97, 128, -1, 48, 127};
//    // Test each character
//    for (size_t i = 0; i < sizeof(test_cases) / sizeof(test_cases[0]); i++) {
//        int c = test_cases[i];
//        if (ft_isascii(c))
//            printf("%d is an ASCII character.\n", c);
//        else
//            printf("%d is not an ASCII character.\n", c);
//    }
//    return 0;
//}