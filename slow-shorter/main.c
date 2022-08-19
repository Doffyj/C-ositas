/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonsanch <jonsanch@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/18 05:35:29 by jonsanch          #+#    #+#             */
/*   Updated: 2022/08/19 20:09:48 by jonsanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

int	ft_longest_arg(int	a, char **c)
{
	int	i;
	int	j;
	int	max;

	i = 1;
	max = 0;
	while (i <= a)
	{
		j = 0;
		while (c[i][j] != '\0')
			j++;
		if (j > max)
			max = j;
		i++;
	}
	return (max);
}

int	main(int argc, char **argv)
{
	int		i;
	int		j;
	int		temp;
	int		args;
	int		*arr;

	i = 0;
	j = 1;
	args = argc - 1;
	printf("# of numbers to arrange = %d\n", args);
	arr = malloc(ft_longest_arg(args, argv) * sizeof(int));
	printf("Original string: ");
	while (i < args)
	{
		printf("%c", argv[j][0]);
		if (j < args)
			printf(" ");
		arr[i] = atoi(argv[j]);
		i++;
		j++;
	}
	j = 1;
	while (j <= i - 1)
	{
		if (arr[j - 1] > arr[j])
		{
			temp = arr[j];
			arr[j] = arr[j - 1];
			arr[j - 1] = temp;
			j = 1;
		}
		else
			j++;		
	}
	j = 0;
	printf("\nResult: ");
	while (j < args)
	{
		printf("%d", arr[j]);
		if (j + 1 < args)
			printf(" ");
		j++;
	}
	printf("\n");
	return (0);
}