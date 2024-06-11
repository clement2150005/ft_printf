/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccolin <ccolin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 12:14:47 by ccolin            #+#    #+#             */
/*   Updated: 2024/06/11 13:58:59 by ccolin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include "libft.h"

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

int		ft_count_putchar(char c);
int		ft_hexlen(unsigned long n);
int		ft_is_fmt_nbr(t_opts *opts);
int		ft_printf(const char *str, ...);
int		ft_cpyhex_0(int nbr, t_opts *opts);
int		ft_print(t_opts *opts, va_list ap);
int		ft_readnbr(const char *str, int *i);
int		ft_count_putstr(char *str, t_opts *opts);
int		ft_charljust(char *result, t_opts *opts);
int		ft_initialize(int **i, t_opts **opts, int *count);
int		ft_rjust_init(char *str, int *width, int *length, t_opts *opts);

void	ft_setflags(const char *str, int *i, t_opts *opts);
void	ft_set_opts(const char *str, int *i, t_opts *opts);
void	ft_freeall(int **i, t_opts **opts);
void	ft_reset_opts(t_opts *opts);
void	ft_setwidth(t_opts *opts);

char	*ft_strrev(char *s);
char	*ft_strupper(char *str);
char	*ft_uitoa(unsigned int n);
char	*ft_moveminus(char *result);
char	*ft_prependminus(char *str);
char	*ft_cpyptr(uintptr_t ptr, int i);
char	*ft_prec(char *str, t_opts *opts);
char	*ft_strdup_printf(const char *s1);
char	*ft_charcpy(char c, t_opts *opts);
char	*ft_hxpfx(char *str, t_opts *opts);
char	*ft_rjust(char *str, t_opts *opts);
char	*ft_ljust(char *str, t_opts *opts);
char	*ft_flags(char *str, t_opts *opts);
char	*ft_setstr(t_opts *opts, va_list ap);
char	*prec_prepend0(char *str, int width);
char	*ft_pls_spc(char *str, t_opts *opts);
char	*ft_zpad(char *str, int width, t_opts *opts);
char	*ft_cpyhex(unsigned int nbr, t_opts *opts, int i);

#endif
