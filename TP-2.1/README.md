¿Qué es un Puntero?
Un puntero es una variable que almacena una dirección de memoria. En lugar de contener un valor directo (como un número o un carácter), un puntero contiene la dirección de la ubicación en memoria donde se encuentra el valor real.

El el código (exercise-8), fechas es un arreglo de punteros a cadenas de caracteres (es decir, const char *). Cada elemento del arreglo fechas es un puntero que apunta a una cadena de caracteres constante.

Aquí, fechas es un arreglo de punteros. Cada elemento en fechas es un puntero a un literal de cadena. Por ejemplo, fechas[0] es un puntero que apunta a la cadena "2024-08-01", fechas[1] apunta a "2023-12-25", y así sucesivamente.