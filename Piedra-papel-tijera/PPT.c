#include <stdio.h>

int ft_actualgame(int x, int y){
    if (x == y)
        printf("Hemos empatado\n");
    else if (y == x + 1 || y == x - 2)
        printf("Has perdido\n");
    else
        printf("Has ganado\n");
    return 0;
}

int ft_printop(int x, int o){
    if (o == 2)
        printf("Tu eliges ");
    else if (o == 1)
        printf("Yo elijo ");

    if (x == 1)
        printf("piedra.\n");
    else if (x == 2)
        printf("papel.\n");
    else
        printf("tijera.\n");
    return 0;
}


int main(){
    int x, y;
    time_t t;

    srand((unsigned) time(&t));

    do{
        printf("Que quieres jugar? 1-Piedra 2-Papel 3-Tijera 4-Salir\n");
        scanf("%d", &x);
        y = (rand() % 3) + 1;
        if (x != 0 && x >= 1 && x <= 3){
            ft_printop(x,2);
            ft_printop(y,1);
            ft_actualgame(x, y);
        }
    }while(x != 0);
    return 0;
}
