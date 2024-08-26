#include <stdio.h>

// ----------------------- 4 ------------------------
// int main() {
//     int edad;

//     printf("Ingrese su edad: ");
//     scanf("%d", &edad);

//     if (edad >= 18) {
//         printf("Eres mayor de edad");
//     }
//     else {
//         printf("No eres mayor de edad");
//     }
    
//     return 0;
// }

// ----------------------- 5 ------------------------

// int main(){
//     int i = 1;
//     int num;

//     printf("Ingrese un número natural (N): ");
//     scanf("%d", &num);


//     while (i <= num){
//         printf("%d\n", i);
//         i++;
//     }
    
//     return 0;
// }

// ----------------------- 6 ------------------------

// int main(){
//     int i = 1;
//     int num;

//     printf("Ingrese un número natural (N): ");
//     scanf("%d", &num);

//     do {
//         printf("%d\n", i);
//         i++;
//     } while (i <= num);
    
//     return 0;
// }

// ----------------------- 7 ------------------------

// int main(){
//     int num;

//     printf("Ingrese un número natural (N): ");
//     scanf("%d", &num);

//     for (int i = 1; i <= num; i++){
//         printf("%d\n", i);
//     }
    
   
//     return 0;
// }

// ----------------------- 8 y 9 ------------------------

// int calculoEdadExacta(int diaNac, int mesNac,int anioNac,int diaAct,int mesAct,int anioAct){
//     int edad = anioAct - anioNac;

//     if(mesAct < mesNac || (mesAct == mesNac && diaAct < diaNac)) {
//         edad--;
//     }

//     return edad;
// }

// const char* determinarEstacion(int diaNac, int mesNac) {
//     if ((mesNac == 12 && diaNac >= 21) || (mesNac >= 1 && mesNac < 3) || (mesNac == 3 && diaNac <= 20)) {
//         return "Verano";
//     } else if ((mesNac == 3 && diaNac >= 21) || (mesNac >= 4 && mesNac < 6) || (mesNac == 6 && diaNac <= 20)) {
//         return "Otoño";
//     } else if ((mesNac == 6 && diaNac >= 21) || (mesNac >= 7 && mesNac < 9) || (mesNac == 9 && diaNac <= 20)) {
//         return "Invierno";
//     } else {
//         return "Primavera";
//     }
// }

// int main(){
//     int diaNac, mesNac, anioNac;
//     int diaAct, mesAct, anioAct;
//     int edadExacta;
//     const char* ESTACION;
    
//     printf("Ingrese su fecha de nacimiento (DD MM AAAA): ");
//     scanf("%d %d %d", &diaNac, &mesNac, &anioNac);

//     printf("Ingrese su fecha actual (DD MM AAAA): ");
//     scanf("%d %d %d", &diaAct, &mesAct, &anioAct);
    
//     edadExacta = calculoEdadExacta(diaNac, mesNac, anioNac, diaAct, mesAct, anioAct);
//     printf("\nTú edad exacta es: %d años\n", edadExacta);
   
//     ESTACION = determinarEstacion(diaNac, mesNac);
//     printf("\nCumples años en la estación de: %s\n", ESTACION);

//     return 0;
// }


// ----------------------- 10 ------------------------

// unsigned long long factorial(int n) {
//     unsigned long long resultado = 1;
//     for (int i = 1; i <= n; i++) {
//         resultado *= i;
//     }
//     return resultado;
// }

// int main(){
//     int N;
    
//     printf("Ingrese un número natural (N): ");
//     scanf("%d", &N);

//     if (N < 0) {
//         printf("El número debe ser natural (no negativo).\n");
//         return 1;
//     }

//     unsigned long long fact = factorial(N);
//     printf("El factorial de %d es: %llu\n", N, fact);

//     return 0;
// }


// ----------------------- 11 ------------------------

int esPrimo(int numero) {
    // if (numero <= 1) return 0;  // No es primo
    if (numero == 2) return 1;  // El 2 es primo
    if (numero % 2 == 0) return 0; // Los números pares mayores que 2 no son primos

    // Verificar divisores desde 3 hasta la raíz cuadrada de numero
    // for (int i = 3; i * i <= numero; i += 2) {
    //     if (numero % i == 0) return 0;
    // }
    // return 1;
}

int main() {
    int N;
    
    printf("Ingrese un número natural (N): ");
    scanf("%d", &N);

    if (N < 0) {
        printf("El número debe ser natural (no negativo).\n");
        return 1;
    }

    printf("\nNúmeros primos menores o iguales a %d:\n", N);
    printf("\n");

    // Imprimir números primos menores o iguales a N
    for (int i = 2; i <= N; i++) {
        if (esPrimo(i)) {
            printf("%d ", i);
        }
    }
    printf("\n");
    

    return 0;
}