/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   runtime.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonsanch <jonsanch@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 16:04:52 by jonsanch          #+#    #+#             */
/*   Updated: 2022/08/16 16:04:52 by jonsanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <time.h>
#include <stdio.h>

void	ft_placeholder()
{
	int	a;

	while (a < 1000000000)
		a++;
}
//reempalzar ft_placehodler y ft_placeholder en main para calcular el runtime de otra función
int	main(void)
{
	clock_t	init = clock();
	ft_placeholder();
	clock_t	fini = clock();
	printf("Total de tiempo usado: %f segundos\n", (double)(fini - init) / CLOCKS_PER_SEC);
	return (0);
}