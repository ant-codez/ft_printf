/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achavez <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/04 20:37:50 by achavez           #+#    #+#             */
/*   Updated: 2019/06/29 15:23:55 by achavez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_H
# define PRINTF_H
# include <stdarg.h>
# include "libft.h"

typedef enum	e_len
{
	none = 0, h = 1, l = 2, ll = 3, j = 4, z = 5, hh = 6, L = 7
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
	int				width;
	int				precision;
	int				length;
	char			*buffer;
	int				reee;

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
void	reset_struct(t_data *p);
void	print_o(t_data *p);
void	print_u(t_data *p);
void	print_x(t_data *p);
void	print_f(t_data *p);
void	print_c(t_data *p, int b00l);
void	print_p(t_data *p);
void	print_di(t_data *p);
void	print_s(t_data *p);
void	print_percent(t_data *p);
void	print_str(char *s, t_data *p);
char	*handle_precision(int pre, char *s);
char	*handle_precision_int(t_data *p, char *str);
char	*handle_width(char *str, t_data *p);
char	*handle_width_int(char *str, t_data *p);
char	*handle_swap(char *str, t_data *p);
intmax_t		di_length(t_data *p);
uintmax_t		oux_length(t_data *p);
long double		f_length(t_data *p);

#endif
