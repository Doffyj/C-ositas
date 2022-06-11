#include <stdio.h>

int main(){
    int x, y;
    time_t t;

    srand((unsigned) time(&t));
    do{
        printf("Quieres tirar una moneda? 1-Si 2-No\n");
        scanf("%d", &x);
        y = (rand() % 2) + 1;
        if(x == 1){
            if(y == 1)
                printf("Cara.\n");
            else
                printf("Cruz.\n");
        }
        else
            break;
    }while(x == 1);
    return 0;
}
