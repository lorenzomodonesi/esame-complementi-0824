#include <stdio.h>

void aspettaEnter() {
    printf("\nPremi Enter per tornare al menu principale...");
    while (getchar() != '\n');
    getchar();
}
