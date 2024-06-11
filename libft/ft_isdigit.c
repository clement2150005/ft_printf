/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccolin <ccolin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 16:07:38 by ccolin            #+#    #+#             */
/*   Updated: 2024/04/21 11:21:40 by ccolin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

//#include <stdio.h>

//int main() {
//    // Test cases
//    char test_cases[] = {'A', 'B', 'c', '9', '%', '\n'};

//    // Test each character
//    for (size_t i = 0; i < sizeof(test_cases) / sizeof(test_cases[0]); i++) {
//        int c = test_cases[i];
//        if (ft_isdigit(c))
//            printf("%c is a digit.\n", c);
//        else
//            printf("%c is not a digit.\n", c);
//    }

//    return 0;
//}