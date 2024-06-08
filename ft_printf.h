/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccolin <ccolin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 12:14:47 by ccolin            #+#    #+#             */
/*   Updated: 2024/06/08 13:21:57 by ccolin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# include <limits.h>

# define TEST "!%61lc!", (char)167

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
	int		width;
	char	fmt;
}		t_opts;

// Function prototypes
int	ft_printf(const char *fmt, ...);

#endif
