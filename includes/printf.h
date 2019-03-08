/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achavez <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/04 20:37:50 by achavez           #+#    #+#             */
/*   Updated: 2019/03/07 21:30:01 by achavez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_H
# define PRINTF_H
# include <stdarg.h>
# include "libft.h"

typedef struct 		s_data
{
	va_list 		arg;
	char			*traverse;
	char			*str;
	unsigned int	i;
	int				p;
	double			f;
	void			*v;
}					t_data;

int		printf(const char * restrict format, ...);
int		make_printf(t_data *p);

#endif
