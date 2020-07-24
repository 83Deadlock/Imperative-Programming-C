#include <stdio.h>

void strrev (char s[]) {
    int i,j;
    char t[100];
    for (i = 0;s[i] != '\0';i++) t[i]=s[i]; // Usa-se um segundo array para armazenar os valores de s.
    for (j = 0;i >= 0;j++){ // Ao longo deste ciclo, os valores de t são colocados de volta no array s, no sentido inverso ao original.
        s[j] = t[i-1];      
        i--;
    }
    s[j] = '\0'; // No final da inversão do array, terminamos a string com o char '\0'.
    return;
}
