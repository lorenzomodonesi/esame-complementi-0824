#include <stdio.h>
#include "../headers/oggetto.h"
#include "../headers/trovaEstremi.h"

void trovaEstremi(struct oggetto lista_oggetti[], int n_oggetti) {
    int min_costo = lista_oggetti[0].costo, max_costo = lista_oggetti[0].costo;
    int min_valore = lista_oggetti[0].valore, max_valore = lista_oggetti[0].valore;

    for (int i = 1; i < n_oggetti; i++) {
        if (lista_oggetti[i].costo < min_costo) min_costo = lista_oggetti[i].costo;
        if (lista_oggetti[i].costo > max_costo) max_costo = lista_oggetti[i].costo;
        if (lista_oggetti[i].valore < min_valore) min_valore = lista_oggetti[i].valore;
        if (lista_oggetti[i].valore > max_valore) max_valore = lista_oggetti[i].valore;
    }

    printf("Oggetti con costo minimo (%d):\n", min_costo);
    for (int i = 0; i < n_oggetti; i++) {
        if (lista_oggetti[i].costo == min_costo) {
            printf("ID: %s, Costo: %d, Valore: %d\n", lista_oggetti[i].id, lista_oggetti[i].costo, lista_oggetti[i].valore);
        }
    }

    printf("Oggetti con costo massimo (%d):\n", max_costo);
    for (int i = 0; i < n_oggetti; i++) {
        if (lista_oggetti[i].costo == max_costo) {
            printf("ID: %s, Costo: %d, Valore: %d\n", lista_oggetti[i].id, lista_oggetti[i].costo, lista_oggetti[i].valore);
        }
    }

    printf("Oggetti con valore minimo (%d):\n", min_valore);
    for (int i = 0; i < n_oggetti; i++) {
        if (lista_oggetti[i].valore == min_valore) {
            printf("ID: %s, Costo: %d, Valore: %d\n", lista_oggetti[i].id, lista_oggetti[i].costo, lista_oggetti[i].valore);
        }
    }

    printf("Oggetti con valore massimo (%d):\n", max_valore);
    for (int i = 0; i < n_oggetti; i++) {
        if (lista_oggetti[i].valore == max_valore) {
            printf("ID: %s, Costo: %d, Valore: %d\n", lista_oggetti[i].id, lista_oggetti[i].costo, lista_oggetti[i].valore);
        }
    }
}
