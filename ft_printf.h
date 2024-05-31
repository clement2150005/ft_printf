/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccolin <ccolin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 12:14:47 by ccolin            #+#    #+#             */
/*   Updated: 2024/05/31 16:16:20 by ccolin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# include <limits.h>

typedef struct settings
{
	int		left_justify;
	int		zero_padding;
	int		precision;
	int		hex_prefix;
	int		plus_sign;
	int		space;
	char	format;
}		t_settings;

// Function prototypes
int	ft_printf(const char *format, ...);

#endif
