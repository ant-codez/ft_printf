/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achavez <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/06 15:02:06 by achavez           #+#    #+#             */
/*   Updated: 2019/04/24 16:11:51 by achavez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "printf.h"

int main()
{
	char 	*str = "Hello";
	char 	*col = "Blakkk";
	char	c = 'F';
	unsigned int	u = -1;
	int			num = 2195;
	float flo = 1233;


	ft_printf("My     o[%u]\n", u);

	printf("printf o[%u]\n", u);
	return 0;
}
