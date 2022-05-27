/**
 * File: 3x+1.c
 * Author: xAthaz <xathaz@protonmail.com>
 * Date: 27/05/2022 @ 02:34:26
 * Last Modified Date: 27/05/2022 @ 02:48:35
 * Last Modified By: xAthaz <xathaz@protonmail.com>
 */

#include <stdio.h>

int	ft_calculador(int x)
{
    int y;
    int cont;
    int max;

    max = 0;
    y = x;
    cont = 0;
    if(x == 1)
    {
	printf("Maximo: 1, Hailstones: 1\n");
	return (0);
    }
    else
    {
	printf("%d", y);
	do{
	    if(y % 2 == 0)
		y = y/2;
	    else
		y = (3*y)+1;
	printf(", %d", y);
	if (y > max)
	    max = y;
	cont++;
	}while(y != 1);
    }
    printf("\nMaximo: %d, Hailstones: %d\n", max, cont);
    return (0);
}

int	main()
{
	int	hel;
    int	input;
    
    printf("Bienvenido al calculador 3x+1 \nPara salir introduce 0\n");
    input = -1;
    do{
	printf("Introduce un numero para comenzar la diversion: ");
	scanf("%d", &input);
	hel = input;
	if(input > 0)
	    ft_calculador(hel);
	else
	    printf("Los numeros negativos no entran en el problema");
    }while(input != 0);
    return 0;
}
