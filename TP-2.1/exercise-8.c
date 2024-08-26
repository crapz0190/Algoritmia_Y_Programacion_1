#include <stdio.h>
#include <string.h>

// Función para comparar dos fechas en formato "YYYY-MM-DD"
int compare_dates(const char *date1, const char *date2) {
    return strcmp(date1, date2);
}

int main() {
    // Arreglo de fechas representadas como cadenas de caracteres
    const char *dates[] = {
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
    
    // tamaño del array (elementos totales)
    int num_dates = sizeof(dates) / sizeof(dates[0]);

    // Inicializar las fechas mayor y menor
    const char *higher_date = dates[0];
    const char *minor_date = dates[0];

    // Encontrar la fecha mayor y menor
    for (int i = 1; i < num_dates; i++) {
        if (compare_dates(dates[i], higher_date) > 0) {
            higher_date = dates[i];
        }
        if (compare_dates(dates[i], minor_date) < 0) {
            minor_date = dates[i];
        }
    }

    // fechas mayor y menor
    printf("Fecha mayor: %s\n", higher_date);
    printf("Fecha menor: %s\n", minor_date);

    return 0;
}

//  Los punteros permiten trabajar con referencias a datos en lugar de trabajar directamente con los datos, facilitando la comparación, la manipulación y la gestión de memoria.
