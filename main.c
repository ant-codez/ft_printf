/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achavez <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/06 15:02:06 by achavez           #+#    #+#             */
/*   Updated: 2019/03/07 21:54:30 by achavez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "printf.h"

int main()
{
	char 	*str = "Hello world!";
	char 	*col = "Blakkk";
	char	c = 'F';
	unsigned int	u = 42949672;
	int		num = 42;


	ft_printf("My x[%x]\nMy u[%u]\n\n", col, str);

	printf("printf p[%p]\nprintf #lx[%#lx]\n", col, col);
	return 0;
}
