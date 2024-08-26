#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 20
#define MAX 10

void eliminar_duplicados(int arr[], int *size){
    int temp_arr[SIZE]; // array temporal con tamaño de 20
    int temp_size=0; // tamaño temporal inicializado en cero, pero que contendra el tamaño real del nuevo array

    // Un puntero a un entero 'int* size' que se usa para pasar la dirección de la variable size. Se usa un puntero 'int* size' para actualizar el tamaño del array después de eliminar duplicados.

    for(int i=0; i<*size; i++){
        int is_duplicate=0; // booleano FALSO

        for(int k=0; k<temp_size; k++){
            if(arr[i]==temp_arr[k]){
                is_duplicate=1; // booleano VERDADERO
                break;
            }
        }

        if(!is_duplicate){
            temp_arr[temp_size++]=arr[i];
        }
    }

    for(int i=0; i<temp_size; i++){
        arr[i]=temp_arr[i];
    }
    
    *size=temp_size;
    
    // *size se usa para acceder al valor original de new_size.
    // *size = tempSize; actualiza el valor de new_size con el nuevo tamaño del array después de eliminar los duplicados.z
}

int main(){
    int num_rand[SIZE]; // almacena los 20 valores definidos aleatoriamente
    int index=0;
    int new_arr[index]; // almacena los valores sin duplicaciones
    int count=0;

    srand(time(NULL));

    while(count < SIZE){
        int random = rand()%MAX;
        num_rand[count] = random;
        count++;
    }

    // mostrar valores de arreglo ORIGINAL
    printf("Array original:\n\n");
    for(int i=0; i<SIZE; i++){
        printf("[%d]: %d\n", i, num_rand[i]);
    }

    // Eliminar duplicados
    int new_size = SIZE;
    eliminar_duplicados(num_rand, &new_size);
    // '&new_size' obtiene la dirección de la variable 'new_size' en memoria y pasa esa dirección a la función eliminar_duplicados.

    // Mostrar valores después de eliminar duplicados
    printf("\nArray sin duplicados:\n\n");
    for (int i = 0; i < new_size; i++) {
        printf("[%d]: %d\n", i, num_rand[i]);
    }
    
    return 0;
}