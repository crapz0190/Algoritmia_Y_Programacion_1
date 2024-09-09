// #include <stdio.h>

// int main() {
//     char buffer[100];
    
//     printf("Introduce una línea de texto: ");
//     if (fgets(buffer, sizeof(buffer), stdin) != NULL) {
//         printf("Leíste: %s", buffer);
//     } else {
//         printf("Error al leer la línea.\n");
//     }

//     return 0;
// }


// #include <stdio.h>

// int main() {
//     char buffer[100];
    
//     printf("Introduce una palabra: ");
//     scanf("%99s", buffer); // Lee hasta el primer espacio en blanco

//     printf("Leíste: %s\n", buffer);

//     return 0;
// }

// #include <stdio.h>
// #include <string.h>

// #define MAX_CADENAS 10
// #define LONGITUD_MAX 21

// void imprimirArreglo(char arreglo[MAX_CADENAS][LONGITUD_MAX], int num_cadenas) {
//     printf("Estado actual del arreglo:\n");
//     for (int i = 0; i < num_cadenas; i++) {
//         printf("%s\n", arreglo[i]);
//     }
//     printf("\n");
// }

// void insertarCadena(char arreglo[MAX_CADENAS][LONGITUD_MAX], int *num_cadenas, char nueva_cadena[LONGITUD_MAX]) {
//     int i, j;

//     if (*num_cadenas < MAX_CADENAS) {
//         // Espacio disponible, insertar en orden
//         for (i = 0; i < *num_cadenas; i++) {
//             if (strcmp(nueva_cadena, arreglo[i]) < 0) {
//                 // Desplazar cadenas hacia la derecha
//                 for (j = *num_cadenas; j > i; j--) {
//                     strcpy(arreglo[j], arreglo[j - 1]);
//                 }
//                 // Insertar la nueva cadena
//                 strcpy(arreglo[i], nueva_cadena);
//                 (*num_cadenas)++;
//                 return;
//             }
//         }
//         // Insertar al final si es mayor que todas las cadenas actuales
//         strcpy(arreglo[*num_cadenas], nueva_cadena);
//         (*num_cadenas)++;
//     } else {
//         // Arreglo lleno
//         if (strcmp(nueva_cadena, arreglo[MAX_CADENAS - 1]) > 0) {
//             // La nueva cadena es mayor que la última cadena en el arreglo
//             return;
//         } else {
//             // Desplazar cadenas hacia la derecha y encontrar lugar para la nueva cadena
//             for (i = MAX_CADENAS - 2; i >= 0; i--) {
//                 if (strcmp(nueva_cadena, arreglo[i]) < 0) {
//                     strcpy(arreglo[i + 1], arreglo[i]);
//                 } else {
//                     break;
//                 }
//             }
//             strcpy(arreglo[i + 1], nueva_cadena);
//         }
//     }
// }

// int main() {
//     char arreglo[MAX_CADENAS][LONGITUD_MAX] = { "" };
//     int num_cadenas = 0;
//     char nueva_cadena[LONGITUD_MAX];

//     while (1) {
//         printf("Ingrese una cadena (o 'fin' para terminar): ");
//         fgets(nueva_cadena, sizeof(nueva_cadena), stdin);
//         // Eliminar el salto de línea al final de la cadena si está presente
//         nueva_cadena[strcspn(nueva_cadena, "\n")] = '\0';

//         if (strcmp(nueva_cadena, "fin") == 0) {
//             break;
//         }

//         insertarCadena(arreglo, &num_cadenas, nueva_cadena);
//         imprimirArreglo(arreglo, num_cadenas);
//     }

//     return 0;
// }

#include <stdio.h>
#include <string.h>
#include <stdlib.h>  // Para strtol

#define MAX_CADENAS 10
#define LONGITUD_MAX 21

void imprimirArreglo(char arreglo[MAX_CADENAS][LONGITUD_MAX], int num_cadenas) {
    printf("Estado actual del arreglo:\n");
    for (int i = 0; i < num_cadenas; i++) {
        printf("%s\n", arreglo[i]);
    }
    printf("\n");
}

void insertarCadena(char arreglo[MAX_CADENAS][LONGITUD_MAX], int *num_cadenas, char nueva_cadena[LONGITUD_MAX]) {
    int i, j;

    if (*num_cadenas < MAX_CADENAS) {
        // Espacio disponible, insertar en orden
        for (i = 0; i < *num_cadenas; i++) {
            if (strcmp(nueva_cadena, arreglo[i]) < 0) {
                // Desplazar cadenas hacia la derecha
                for (j = *num_cadenas; j > i; j--) {
                    strcpy(arreglo[j], arreglo[j - 1]);
                }
                // Insertar la nueva cadena
                strcpy(arreglo[i], nueva_cadena);
                (*num_cadenas)++;
                return;
            }
        }
        // Insertar al final si es mayor que todas las cadenas actuales
        strcpy(arreglo[*num_cadenas], nueva_cadena);
        (*num_cadenas)++;
    } else {
        // Arreglo lleno
        if (strcmp(nueva_cadena, arreglo[MAX_CADENAS - 1]) > 0) {
            // La nueva cadena es mayor que la última cadena en el arreglo
            return;
        } else {
            // Desplazar cadenas hacia la derecha y encontrar lugar para la nueva cadena
            for (i = MAX_CADENAS - 2; i >= 0; i--) {
                if (strcmp(nueva_cadena, arreglo[i]) < 0) {
                    strcpy(arreglo[i + 1], arreglo[i]);
                } else {
                    break;
                }
            }
            strcpy(arreglo[i + 1], nueva_cadena);
        }
    }
}

int main() {
    char arreglo[MAX_CADENAS][LONGITUD_MAX] = { "" };
    int num_cadenas = 0;
    char entrada[LONGITUD_MAX];
    char *endptr;
    long opcion;

    do {
        printf("Ingrese una opción:\n");
        printf("1. Insertar cadena\n");
        printf("2. Mostrar estado del arreglo\n");
        printf("3. Salir\n");
        printf("Opción: ");
        fgets(entrada, sizeof(entrada), stdin);
        
        // Convertir la entrada a un número entero usando strtol
        opcion = strtol(entrada, &endptr, 10);

        // Verificar si la conversión fue exitosa
        if (*endptr != '\0' && *endptr != '\n') {
            printf("Opción inválida. Por favor, intente de nuevo.\n");
            opcion = 0; // Forzar reingreso de opción
        }

        switch(opcion) {
            case 1: {
                printf("Ingrese una cadena: ");
                fgets(entrada, sizeof(entrada), stdin);
                // Eliminar el salto de línea al final de la cadena si está presente, si se planea usar la cadena para comparaciones o inserciones
                entrada[strcspn(entrada, "\n")] = '\0';

                if (strcmp(entrada, "fin") != 0) {
                    insertarCadena(arreglo, &num_cadenas, entrada);
                    // imprimirArreglo(arreglo, num_cadenas);
                } else {
                    printf("Se ingresó 'fin'. Terminando el programa.\n");
                    opcion = 3; // Cambiar a opción de salida para terminar el programa
                }
                break;
            }
            case 2:
                imprimirArreglo(arreglo, num_cadenas);
                break;
            case 3:
                printf("Saliendo del programa...\n");
                break;
            default:
                if (opcion != 0) { // Solo mostrar mensaje de error si la opción no es 0 (opción inválida)
                    printf("Opción inválida. Por favor, intente de nuevo.\n");
                }
        }
    } while (opcion != 3);

    return 0;
}
