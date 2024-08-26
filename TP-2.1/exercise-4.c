#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define MAX 10
#define SIZE 50

// --------------- funcion para calcular la moda -----------------
int calc_mode(int vector[], int size, int max){
    int frequency[max];
    int mode=0;
    int max_count=0;

    // Contar la frecuencia de cada número
    for (int i = 0; i < size; i++) {
        frequency[vector[i]]++;
    }

    // Encontrar el número con la mayor frecuencia
    for (int i = 0; i <= max; i++) {
        if (frequency[i] > max_count) {
            max_count = frequency[i];
            mode = i;
        }
    }

    return mode;
}

// ------------- funcion para calcular la media -------------
double calc_average(int vector[], int size){
    double add=0.0;

    for(int i=0; i<size; i++){
        add += vector[i];
    }
    // printf("\nsuma total: %.2f", add);
    return add/size;
}

// ------------- funcion para calcular la desviacion estandar -------------
double calc_deviation(int vector[], int size, double avg){
    double add_sqrs=0.0; //suma de los cuadrados de las diferencias entre cada valor y la media
    double sqr_root=0.5;
    double result=0.0;
    
    for(int i=0; i<size; i++){
        add_sqrs += pow((vector[i]-avg), 2);
    }
    
    // muestra de la suma total de los cuadrados
    // printf("\nsuma total de cuadrados: %.2f\n", add_sqrs);
    
    result = pow((add_sqrs/(size-1)), sqr_root);

    return result;
}

int main(){
    int vector[SIZE];
    int mode; // moda
    double avg; // media
    double stdr_dvn; // desviacion estandar

     // inicializador de semilla del generador
    srand(time(NULL));

    // almacenar números aleatorios en array
    for(int i=0; i<SIZE; i++){
        int num = rand()%MAX;
        vector[i] = num;
    }

    // mostrar vector con 50 elementos
    // for(int num=0; num<SIZE; num++){
    //      printf("[%d] %d \n", num, vector[num]);
    // }
   
    mode = calc_mode(vector, SIZE, MAX);
    avg = calc_average(vector, SIZE);
    stdr_dvn = calc_deviation(vector, SIZE, avg);

    printf("\n");
    printf("Moda: %d\n", mode);
    printf("\n");
    printf("Media: %.2f\n", avg);
    printf("\n");
    printf("Desviación estándar: %.2f\n", stdr_dvn);
    
    return 0;
}