/**
 * File: ruleta-ukraniana.c
 * Author: xAthaz <xathaz@protonmail.com>
 * Date: 15/06/2022 @ 19:04:05
 * Last Modified Date: 15/06/2022 @ 19:27:52
 * Last Modified By: xAthaz <xathaz@protonmail.com>
 */

#include <stdio.h>

int main(){
    int x, y, z, cont = 0;
    time_t t;

    srand((unsigned) time(&t));
    do{
	printf("Welcome a la ruleta ukraniana.\n");
	printf("Para participar pon un numero del 1 al 6. Para salir pon un 0.\n");
	scanf("%d", &x);
	y = (rand() % 6) + 1;
	if(x == 0)
	    break;
	else if (x >= 1 && x <= 6){
	    for(z=1;z<=6;z++){
			printf("%d.", z);
			if(z == y){
		    	printf(" Bang!\n");
		    	z = 8;
		    	sleep(2);
		    }
			else{
		    	printf("*click*\n");
				sleep(2);
	    		}
	    	}
		if(x == y){
	    	printf("Has perdido!\n Buena suerte en tu proxima partida\n");
	    	cont = 0;
			}
		else{
	    	printf("Has pasado esta ronda.\n");
	    	cont++;
	    	printf("Llevas una racha de %d rondas.\n", cont);
			}
		printf("----------------------------------------------\n");
		printf("----------------------------------------------\n");
	}
    }while(x != 0);
    printf("Chao frend!");
    return 0;
}
