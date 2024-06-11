/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccolin <ccolin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 10:47:53 by ccolin            #+#    #+#             */
/*   Updated: 2024/04/30 10:47:42 by ccolin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_isset(const char *set, char c)
{
	int	i;

	i = 0;
	while (set[i])
		if (set[i++] == c)
			return (1);
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		i;
	int		start;
	int		end;
	char	*trimmed;

	i = 0;
	while (ft_isset(set, s1[i]))
		i++;
	start = i;
	while (s1[i])
		i++;
	i = i - 1;
	while (ft_isset(set, s1[i]) && i > 0)
		i--;
	end = i;
	if (start > end)
		return (ft_strdup(""));
	i = 0;
	trimmed = malloc(sizeof(char) * (end - start) + 2);
	if (trimmed == NULL)
		return (NULL);
	while (start <= end)
		trimmed[i++] = s1[start++];
	trimmed[i] = '\0';
	return (trimmed);
}
