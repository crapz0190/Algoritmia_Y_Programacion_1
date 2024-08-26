#include <stdio.h>
#define SIZE 5

int main(){

    int vector_1[] = {66,15,43,32,65};
    int vector_2[] = {23,16,34,45,18};
    int add[SIZE];

    for(int i=0; i<SIZE; i++){
        add[i] = vector_1[i] + vector_2[i];
    }

    printf("\nNuevo array con las sumas de los dos vectores anteriores:\n\n");
    for (int j = 0; j < SIZE; j++){
        printf("%d ", add[j]);
    }
    
    printf("\n");

    return 0;
}