/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccolin <ccolin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 14:22:43 by ccolin            #+#    #+#             */
/*   Updated: 2024/05/06 18:37:38 by ccolin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static void	ft_skip(char **temp)
{
	char	*ptr;

	ptr = *temp;
	while (ptr[0] == '\t' || ptr[0] == '\n' || ptr[0] == '\v'
		|| ptr[0] == '\f' || ptr[0] == ' ' || ptr[0] == '\r')
		ptr++;
	*temp = ptr;
}

static int	ft_sign(char **temp)
{
	int		sign;
	char	*ptr;

	ptr = *temp;
	sign = 1;
	if (ptr[0] == '-' || ptr[0] == '+')
	{
		if (ptr[0] == '-')
			sign = -1;
		ptr++;
	}
	*temp = ptr;
	return (sign);
}

int	ft_atoi(const char *str)
{
	char				*ptr;
	unsigned long long	nbr;
	int					sign;
	int					i;

	ptr = (char *)str;
	ft_skip(&ptr);
	sign = ft_sign(&ptr);
	while (ptr[0] == '0')
		ptr++;
	i = 0;
	nbr = 0;
	while (ptr[i] && ptr[i] >= '0' && ptr[i] <= '9')
		nbr = nbr * 10 + ptr[i++] - '0';
	if (i > 19 || nbr >= 9223372036854775808ULL)
	{
		if (sign == 1)
			return (-1);
		if (sign == -1)
			return (0);
	}
	return (nbr * sign);
}

// int	main(void)
// {
// 	ft_atoi("+1");
// 	return (0);
// }