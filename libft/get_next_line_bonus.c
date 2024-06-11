/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccolin <ccolin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 10:18:52 by ccolin            #+#    #+#             */
/*   Updated: 2024/05/21 11:35:46 by ccolin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*get_next_line(int fd)
{
	static char	*leftover[OPEN_MAX];
	char		*next_line;
	char		*temp;

	if (BUFFER_SIZE <= 0 || fd < 0)
		return (NULL);
	leftover[fd] = ft_read_from_file(fd, leftover[fd]);
	if (!leftover[fd])
	{
		free(leftover[fd]);
		return (NULL);
	}
	next_line = ft_find_line(leftover[fd]);
	temp = leftover[fd];
	leftover[fd] = ft_find_leftover(leftover[fd]);
	if (leftover[fd] == NULL)
		free(leftover[fd]);
	free(temp);
	return (next_line);
}

char	*ft_read_from_file(int fd, char *leftover)
{
	char		*buffer;
	long long	bytes_read;

	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	ft_gnl_memset(buffer, 0, BUFFER_SIZE);
	while (!ft_gnl_strchr(buffer, '\n'))
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read == -1)
		{
			free(leftover);
			free(buffer);
			return (NULL);
		}
		else if (bytes_read == 0)
			break ;
		else
			buffer[bytes_read] = '\0';
		leftover = ft_gnl_strjoin(leftover, buffer);
	}
	free(buffer);
	return (leftover);
}

char	*ft_find_line(char *leftover)
{
	char	*str;
	int		i;
	int		j;

	j = 0;
	i = 0;
	while (leftover[i] != '\n' && leftover[i])
		i++;
	str = malloc(sizeof(char) * (i + 2));
	while (i > j)
	{
		str[j] = leftover[j];
		j++;
	}
	if (leftover[j] == '\n')
	{
		str[j] = leftover[j];
		j++;
	}
	str[j] = '\0';
	return (str);
}

char	*ft_find_leftover(char *leftover)
{
	while (*leftover && *leftover != '\n')
		leftover++;
	if (*leftover == '\n')
		leftover++;
	if (*leftover == '\0')
		return (NULL);
	return (ft_gnl_strdup(leftover));
}
