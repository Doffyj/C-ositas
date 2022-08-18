/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonsanch <jonsanch@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/18 05:35:29 by jonsanch          #+#    #+#             */
/*   Updated: 2022/08/18 07:10:58 by jonsanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

int	main(int argc, char **argv)
{
	int		i;
	int		j;
	int		temp;
	char	arr[50];
	int		args;

	i = 0;
	j = 1;
	args = argc - 1;
	printf("# of numbers to arrange = %d\n", args);
	//arr = malloc((argc + 1) * sizeof(char));
	printf("Original string: ");
	while (i < args)
	{
		printf("%c", argv[j][0]);
		if (j < args)
			printf(" ");
		arr[i] = argv[j][0] - '0';
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