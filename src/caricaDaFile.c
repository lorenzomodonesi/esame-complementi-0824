#include <stdio.h>
#include <string.h>
#include <stdbool.h> 
#include "../headers/oggetto.h"
#include "../headers/aspettaEnter.h"

int caricaDaFile(struct oggetto lista_oggetti[], int *n_oggetti, int *capac) {
    char filename[50];
    FILE *file;

    printf("Inserisci il nome del file: ");
    scanf("%s", filename);
    file = fopen(filename, "r");

    if (file == NULL) {
        printf("Errore nell'apertura del file.\n");
        return 0;
    }

    fscanf(file, "%d %d", n_oggetti, capac);
    for (int i = 0; i < *n_oggetti; i++) {
        fscanf(file, "%s %d %d", lista_oggetti[i].id, &lista_oggetti[i].costo, &lista_oggetti[i].valore);
        lista_oggetti[i].rapporto = 0;
    }

    fclose(file);
    printf("Dati caricati con successo.\n");
    
    aspettaEnter();

    if (*n_oggetti > 0) {
        return 1;
    } else {
        return 0;
    }
}
