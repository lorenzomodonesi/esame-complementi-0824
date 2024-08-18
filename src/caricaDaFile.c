#include <stdio.h>
#include <string.h>
#include "../headers/oggetto.h"

void caricaDaFile(struct oggetto lista_oggetti[], int *n_oggetti, int *capac) {
    char filename[50];
    FILE *file;

    printf("Inserisci il nome del file: ");
    scanf("%s", filename);
    file = fopen(filename, "r");

    if (file == NULL) {
        printf("Errore nell'apertura del file.\n");
        return;
    }

    fscanf(file, "%d %d", n_oggetti, capac);
    for (int i = 0; i < *n_oggetti; i++) {
        fscanf(file, "%s %d %d", lista_oggetti[i].id, &lista_oggetti[i].costo, &lista_oggetti[i].valore);
        lista_oggetti[i].rapporto = 0;
    }

    fclose(file);
    printf("Dati caricati con successo.\n");
}
