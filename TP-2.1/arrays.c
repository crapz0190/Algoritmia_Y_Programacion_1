#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 10
#define SIZE 10

int verify_num(int num_rand[], int index, int num){
    for(int i=0; i < index; i++) {
        if(num_rand[i] == num){
            return 1;
        }
    }
    return 0;
}

int main(){
    // count --> posicion en el array (index)
    int num_rand[SIZE];
    int count=0;
    
    // inicializador de semilla del generador
    srand(time(NULL));

    // arreglo con números no repetidos
    while(count < SIZE){
        int num = rand()%(MAX+1);

        if(!verify_num(num_rand, count, num)){
            num_rand[count] = num;
            count++;
        }
    }

    printf("\nNúmeros enteros aleatorios no repetidos entre 0 y 10:\n");

    for(int i=0; i < SIZE; i++){
        printf("posicion[%i]: %d\n", i, num_rand[i]);
    }

    return 0;
}