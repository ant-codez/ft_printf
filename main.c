/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achavez <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/06 15:02:06 by achavez           #+#    #+#             */
/*   Updated: 2019/08/12 19:16:26 by achavez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "printf.h"

int main()
{
	char 	*str = "Hello";
	char 	*col = "Blakkk";
	char	c = 'F';
	unsigned int	u = 3410000000;
	int			num = 124221;
	float		f = 42.42;
	long double ld = 12334234234.4134135412;


	printf("%7i\n", -14);

	ft_printf("%7i\n", -14);
	return 0;
}
