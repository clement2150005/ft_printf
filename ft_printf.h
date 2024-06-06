/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccolin <ccolin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 12:14:47 by ccolin            #+#    #+#             */
/*   Updated: 2024/06/06 14:59:41 by ccolin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# include <limits.h>

# define TEST "%0+10d, %0+10d, %0+10d, %0+10d, %0+10d, %0+10d, %0+10d, %0+10d", 0, 5, -1, -10, 100, -1862, INT_MIN, INT_MAX

typedef struct opts
{
	int		ljust;
	int		rjust;
	int		zpad;
	int		prec;
	int		hxpfx;
	int		plssgn;
	int		spc;
	int		chrnll;
	char	fmt;
}		t_opts;

// Function prototypes
int	ft_printf(const char *fmt, ...);

#endif
