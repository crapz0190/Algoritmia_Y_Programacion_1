#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 10
#define SIZE 10

int main(){
    // count --> posicion en el array (index)
    int num_rand[SIZE];
    int frequency[SIZE] = {0};
    
    // inicializador de semilla del generador
    srand(time(NULL));

    for(int i=0; i<SIZE; i++){
        int index=0;
        // arreglo con números aleatorios
        while(index < SIZE){
            int num = rand()%MAX;

            num_rand[index] = num;
            index++;
        }

        printf("\n");
        // por cada iteracion, cuenta la cantidad de veces que cada numero del 0 al 9 se repiten, almacenando la cantidad total de repeticiones en un nuevo array
        for(int k=0; k < SIZE; k++){
            printf("%d ", num_rand[k]);
            frequency[num_rand[k]]++;
        }
    }

    printf("\n\n");
    for(int i = 0; i < SIZE; i++){
        printf("[%d]: %d\n", i, frequency[i]);

    }

    return 0;
}
