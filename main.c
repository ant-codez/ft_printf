/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achavez <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/06 15:02:06 by achavez           #+#    #+#             */
/*   Updated: 2019/04/22 20:46:39 by achavez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "printf.h"

int main()
{
	char 	*str = "Hello";
	char 	*col = "Blakkk";
	char	c = 'F';
	unsigned int	u = 42949672;
	int			num = 2322;
	float flo = 1233;


	ft_printf("My     p[%15p]\n", (void*)str);

	printf("printf p[%15p]\n", (void*)str);
	return 0;
}
