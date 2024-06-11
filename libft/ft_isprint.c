/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccolin <ccolin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 16:07:38 by ccolin            #+#    #+#             */
/*   Updated: 2024/04/21 11:25:04 by ccolin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isprint(int c)
{
	if (c >= 32 && c <= 126)
		return (1);
	return (0);
}

//#include <stdio.h>

//int main() {
//    // Test cases
//    int test_cases[] = {' ', 'A', '~', '\x7F', '\x1F'};
//    // Test each character
//    for (size_t i = 0; i < sizeof(test_cases) / sizeof(test_cases[0]); i++) {
//        char c = test_cases[i];
//        if (ft_isprint(c))
//            printf("'%c' is a printable character.\n", c);
//        else
//            printf("'%c' is not a printable character.\n", c);
//    }
//    return 0;
//}