#include <stdio.h>
#include <stdlib.h>

void main(){
    int x, i;
    srand(time(NULL));
    for(i=0; i<5;i++){
    	printf("Numero aleatorio %d.\n", rand());
    	x = rand() % 5;
    	printf("%d eh os valores de X.\n", x);
	}
}
