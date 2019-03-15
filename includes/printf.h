/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achavez <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/04 20:37:50 by achavez           #+#    #+#             */
/*   Updated: 2019/03/15 16:25:05 by achavez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_H
# define PRINTF_H
# include <stdarg.h>
# include "libft.h"

typedef enum	e_len
{
	hh = 0, h = 1, l = 2, ll = 3, j = 4, z = 5
}				t_len;

/*
** flags: 0 = [0], 1 = [#], 2 = [+], 3 = [-], 4 = [ ]
*/

typedef struct 		s_data
{
	// important and must be stored in struct
	va_list 		arg;
	char			*traverse;
	char			flags[5];
	short			width;
	short			precision;
	int				length;

	//just used to hold data from va_arg()
	char			*str;
	unsigned int	i;
	int				p;
	double			f;
	void			*v;
}					t_data;

int		printf(const char * restrict format, ...);
int		make_printf(t_data *p);
void	parse_format(t_data *p);
void	find_conversions(t_data *p);
void	parse_flags(t_data *p);
void	determine_specifier(t_data *p);
void	print_o(t_data *p);
void	print_x(t_data *p);
void	print_f(t_data *p);

#endif
