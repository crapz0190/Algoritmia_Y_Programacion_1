#include <stdio.h>

int main(){
    char* arr_char[10] = {"h","o","l","a"," ","m","u","n","d","o"};
    
    // arreglo de cadenas al derecho
    printf("\nArreglo al derecho:\n");
    for (int i = 0; i < 10; i++) {
        printf("%s", arr_char[i]);
    }

    printf("\n");

    // arreglo de cadenas al revés
    printf("\nArreglo al revés:\n");
    for (int i = 9; i >= 0; i--) {
        printf("%s", arr_char[i]);
    }

    printf("\n");
    return 0;
}