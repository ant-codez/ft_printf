/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achavez <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/06 15:02:06 by achavez           #+#    #+#             */
/*   Updated: 2019/06/21 22:00:44 by achavez          ###   ########.fr       */
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
	int			num = -1221;
	float f = 123.42;


	printf("%f\n", f);

	ft_printf("%f\n", f);
	return 0;
}
