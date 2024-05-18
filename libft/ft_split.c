/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccolin <ccolin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 11:01:36 by ccolin            #+#    #+#             */
/*   Updated: 2024/05/06 10:38:02 by ccolin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_countstrings(char const *s, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	if (!*s)
		return (0);
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (s[i])
			count++;
		while (s[i] != c && s[i])
			i++;
	}
	return (count);
}

static int	ft_findend(char const *s, char c, int i)
{
	while (s[i] && s[i] != c)
		i++;
	return (i);
}

static char	*ft_substring(char const *s, int start, int end)
{
	int		i;
	char	*substr;

	i = 0;
	if (end < start || start < 0 || end < 0)
		return (NULL);
	substr = malloc(sizeof(char) * (end - start + 1));
	if (substr == NULL)
		return (NULL);
	while (start < end)
		substr[i++] = s[start++];
	substr[i] = '\0';
	return (substr);
}

char	**ft_split(char const *s, char c)
{
	int		i;
	int		j;
	int		count;
	char	**array;

	count = ft_countstrings(s, c);
	array = (char **)malloc(sizeof(char *) * (count + 1));
	if (!array || !s)
		return (0);
	i = 0;
	j = 0;
	while (j < count)
	{
		while (s[i] == c)
			i++;
		if (s[i])
		{
			array[j] = ft_substring(s, i, ft_findend(s, c, i));
			i = ft_findend(s, c, i) + 1;
			j++;
		}
	}
	array[j] = NULL;
	return (array);
}
