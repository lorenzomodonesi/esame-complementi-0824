#include <stdio.h>
#include <string.h>
#include "../headers/oggetto.h"
#include "../headers/cercaOggettoPerID.h"
#include "../headers/aspettaEnter.h"

void cercaOggettoPerID(struct oggetto lista_oggetti[], int n_oggetti) {
    char id[10];
    printf("Inserisci l'ID dell'oggetto da cercare: ");
    scanf("%s", id);

    for (int i = 0; i < n_oggetti; i++) {
        if (strcmp(lista_oggetti[i].id, id) == 0) {
            printf("Oggetto trovato - Costo: %d, Valore: %d\n", lista_oggetti[i].costo, lista_oggetti[i].valore);
            return;
        }
    }
    printf("Oggetto non trovato.\n");
    aspettaEnter();
}
