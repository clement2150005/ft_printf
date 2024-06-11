/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccolin <ccolin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 13:12:06 by ccolin            #+#    #+#             */
/*   Updated: 2024/05/04 17:49:32 by ccolin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_minus(char *s, int *n)
{
	if (*n < 0 || *n == -2147483648)
	{
		s[0] = '-';
		*n = *n * -1;
	}
}

static int	ft_intlen(int n)
{
	int		i;

	i = 1;
	if (n == -2147483648)
		return (10);
	if (n < 0)
	{
		n = n * -1;
		i++;
	}
	while (n > 9)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	int				len;
	int				i;
	char			*s;
	unsigned int	nbr;

	len = ft_intlen(n);
	i = len;
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	if (n < 0)
		nbr = -n;
	if (n >= 0)
		nbr = n;
	s = malloc(sizeof(char) * len + 1);
	if (s == NULL)
		return (NULL);
	s[i--] = '\0';
	ft_minus(s, &n);
	while (nbr > 9)
	{
		s[i--] = nbr % 10 + '0';
		nbr = nbr / 10;
	}
	s[i] = nbr % 10 + '0';
	return (s);
}
//#include <stdio.h>

//int main() {
//    // Test cases
//    int numbers[] = {12345, -6789, 0};

//    // Test the function with each number
//    for (int i = 0; i < sizeof(numbers) / sizeof(numbers[0]); i++) {
//        int number = numbers[i];
//        char *result = ft_itoa(number);
//        printf("Number: %d, Result: %s\n", number, result);
//        free(result); // Free the memory allocated by ft_itoa
//    }

//    return 0;
//}