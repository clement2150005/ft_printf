/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccolin <ccolin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 16:07:38 by ccolin            #+#    #+#             */
/*   Updated: 2024/04/21 11:18:28 by ccolin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isalnum(int c)
{
	if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z')
		|| (c >= '0' && c <= '9'))
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
//        if (ft_isalnum(c))
//            printf("%c is an alphanumeric character.\n", c);
//        else
//            printf("%c is not an alphanumeric character.\n", c);
//    }
//    return 0;
//}