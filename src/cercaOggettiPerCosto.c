#include <stdio.h>
#include "../headers/oggetto.h"
#include "../headers/cercaOggettiPerCosto.h"
#include "../headers/aspettaEnter.h"

void cercaOggettiPerCosto(struct oggetto lista_oggetti[], int n_oggetti) {
    int p;
    printf("Inserisci il valore massimo per il costo: ");
    scanf("%d", &p);

    int found = 0;
    for (int i = 0; i < n_oggetti; i++) {
        if (lista_oggetti[i].costo < p) {
            printf("ID: %s, Costo: %d\n", lista_oggetti[i].id, lista_oggetti[i].costo);
            found = 1;
        }
    }
    if (!found) {
        printf("Nessun oggetto trovato con costo minore di %d.\n", p);
    }
    aspettaEnter();
}
