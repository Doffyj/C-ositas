/**
 * File: Download-calculator.c
 * Author: xAthaz <xathaz@protonmail.com>
 * Date: 22/06/2022 @ 22:53:48
 * Last Modified Date: 22/06/2022 @ 23:54:16
 * Last Modified By: xAthaz <xathaz@protonmail.com>
 */
#include <stdio.h>
#ifdef _WIN32
#include <Windows.h> 	//Para sleep en windows
#else
#include <unistd.h> 	//Para UNIX basados
#endif

int	ft_download_calc(float i, float j){
    float x, y;

    x = ((i * 1000) / j) / 60;
    y = x / 60;
    printf("La duracion estimada de la descarga es de %.1f minutos\nLo que equivale a %.1f horas.\n", x, y);
    return 0;
}

int	main(){
    float i, j; // pedir datos
    int k;	// para el loop
    printf("Bienvenido a la calculadora de descargas.\n");
    do{
	printf("Cual es el tamanyo del item que vas a descargar? (en GB)\n");
	scanf("%f", &i);
	printf("Cual es la velocidad de descarga? (en MB)\n");
	scanf("%f", &j);
	ft_download_calc(i, j);
	printf("Quieres calcular otra cosa?// 1-Si 2-No\n");
	scanf("%d", &k);
    }while(k==1);
    printf("Echale un ojo al info.txt, todos los dias se aprende algo nuevo (?)");
    Sleep(3000);
    return 0;
}
