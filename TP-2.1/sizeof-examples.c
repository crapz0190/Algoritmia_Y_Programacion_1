#include <stdio.h>

int main() {
    printf("Tamaño de int: %zu bytes\n", sizeof(int));
    printf("Tamaño de double: %zu bytes\n", sizeof(double));
    return 0;
}


int main() {
    int x = 10;
    printf("Tamaño de x: %zu bytes\n", sizeof(x));
    return 0;
}

int main() {
    int arreglo[10];
    printf("Tamaño del arreglo en bytes: %zu\n", sizeof(arreglo));
    printf("Tamaño de un elemento del arreglo en bytes: %zu\n", sizeof(arreglo[0]));
    printf("Número de elementos en el arreglo: %zu\n", sizeof(arreglo) / sizeof(arreglo[0]));
    return 0;
}



// ---------------------- times ------------------------ 
// ---------------------- times ------------------------ 
// ---------------------- times ------------------------ 



#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NUM_FECHAS 10

// Estructura para representar una fecha
typedef struct {
    int anio;
    int mes;
    int dia;
} Fecha;

// Función para convertir una cadena de caracteres en una estructura Fecha
Fecha convertirFecha(const char *cadena) {
    Fecha fecha;
    sscanf(cadena, "%4d-%2d-%2d", &fecha.anio, &fecha.mes, &fecha.dia);
    return fecha;
}

// Función para comparar dos fechas
int compararFechas(Fecha f1, Fecha f2) {
    if (f1.anio != f2.anio) return f1.anio - f2.anio;
    if (f1.mes != f2.mes) return f1.mes - f2.mes;
    return f1.dia - f2.dia;
}

int main() {
    // Arreglo de fechas representadas como cadenas de caracteres
    char *fechas[NUM_FECHAS] = {
        "2024-08-01",
        "2023-12-25",
        "2022-06-15",
        "2023-01-01",
        "2024-02-29",
        "2023-07-30",
        "2024-03-10",
        "2022-11-05",
        "2023-04-20",
        "2024-07-25"
    };

    // Inicializar las fechas mayor y menor
    Fecha fechaMayor = convertirFecha(fechas[0]);
    Fecha fechaMenor = convertirFecha(fechas[0]);

    // Encontrar la fecha mayor y menor
    for (int i = 1; i < NUM_FECHAS; i++) {
        Fecha fechaActual = convertirFecha(fechas[i]);
        if (compararFechas(fechaActual, fechaMayor) > 0) {
            fechaMayor = fechaActual;
        }
        if (compararFechas(fechaActual, fechaMenor) < 0) {
            fechaMenor = fechaActual;
        }
    }

    // Imprimir las fechas mayor y menor
    printf("Fecha más reciente: %04d-%02d-%02d\n", fechaMayor.anio, fechaMayor.mes, fechaMayor.dia);
    printf("Fecha más antigua: %04d-%02d-%02d\n", fechaMenor.anio, fechaMenor.mes, fechaMenor.dia);

    return 0;
}


// ---------------------ejercicio 9 -------------------
// ---------------------ejercicio 9 -------------------
// ---------------------ejercicio 9 -------------------

#include <stdio.h>
#include <string.h>

#define MAX_SIZE 10
#define MAX_LENGTH 21  // 20 caracteres + 1 para el terminador nulo

void imprimir_arreglo(char arreglo[MAX_SIZE][MAX_LENGTH], int size) {
    printf("Contenido actual del arreglo:\n");
    for (int i = 0; i < size; i++) {
        printf("%s\n", arreglo[i]);
    }
}

void insertar_en_orden(char arreglo[MAX_SIZE][MAX_LENGTH], int *size, char nueva_cadena[MAX_LENGTH]) {
    int i, j;

    // Si el arreglo está lleno
    if (*size >= MAX_SIZE) {
        // Verificar si la nueva cadena es la última en orden alfabético
        if (strcmp(nueva_cadena, arreglo[MAX_SIZE - 1]) > 0) {
            printf("La nueva cadena es mayor que la última cadena en el arreglo. No se inserta.\n");
            return;
        }

        // Desplazar las cadenas para hacer lugar
        for (i = MAX_SIZE - 1; i > 0; i--) {
            strcpy(arreglo[i], arreglo[i - 1]);
        }
        *size = MAX_SIZE - 1; // Reducir el tamaño del arreglo
    }

    // Encontrar la posición correcta para insertar la nueva cadena
    for (i = 0; i < *size; i++) {
        if (strcmp(nueva_cadena, arreglo[i]) < 0) {
            break;
        }
    }

    // Desplazar las cadenas para hacer lugar
    for (j = *size; j > i; j--) {
        strcpy(arreglo[j], arreglo[j - 1]);
    }
    strcpy(arreglo[i], nueva_cadena);
    (*size)++;
}

int main() {
    char arreglo[MAX_SIZE][MAX_LENGTH];
    int size = 0;
    char nueva_cadena[MAX_LENGTH];
    int opcion;

    // Inicializar el arreglo
    for (int i = 0; i < MAX_SIZE; i++) {
        strcpy(arreglo[i], "");
    }

    do {
        printf("\nMenu:\n");
        printf("1. Insertar una nueva cadena\n");
        printf("2. Imprimir el arreglo\n");
        printf("3. Terminar el programa\n");
        printf("Seleccione una opción (1-3): ");
        scanf("%d", &opcion);
        getchar(); // Para consumir el salto de línea después de scanf

        switch (opcion) {
            case 1:
                printf("Ingrese una cadena (o 'fin' para terminar): ");
                fgets(nueva_cadena, MAX_LENGTH, stdin);
                
                // Eliminar el salto de línea de la cadena leída
                nueva_cadena[strcspn(nueva_cadena, "\n")] = '\0';
                
                // Verificar si se debe terminar
                if (strcmp(nueva_cadena, "fin") == 0) {
                    printf("La cadena 'fin' no se insertará. Vuelve al menú.\n");
                    break;
                }

                insertar_en_orden(arreglo, &size, nueva_cadena);
                break;

            case 2:
                imprimir_arreglo(arreglo, size);
                break;

            case 3:
                printf("Terminando el programa.\n");
                break;

            default:
                printf("Opción no válida. Por favor, elija entre 1 y 3.\n");
        }
    } while (opcion != 3);

    return 0;
}
