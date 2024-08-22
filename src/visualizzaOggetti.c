#include <stdio.h>
#include "../headers/oggetto.h"
#include "../headers/visualizzaOggetti.h"
#include "../headers/aspettaEnter.h"

void visualizzaOggetti(struct oggetto lista_oggetti[], int n_oggetti) {
    for (int i = 0; i < n_oggetti; i++) {
        printf("ID: %s, Costo: %d, Valore: %d, Rapporto: %.2f\n",
               lista_oggetti[i].id, lista_oggetti[i].costo,
               lista_oggetti[i].valore, lista_oggetti[i].rapporto);
    }
    aspettaEnter();
}
