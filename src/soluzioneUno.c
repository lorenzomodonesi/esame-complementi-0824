#include <stdio.h>
#include "../headers/oggetto.h"
#include "../headers/soluzioneUno.h"

// Funzione per ordinare gli oggetti per rapporto valore/costo
void ordinaOggettiPerRapporto(struct oggetto lista_oggetti[], int n_oggetti) {
    for (int i = 0; i < n_oggetti; i++) {
        lista_oggetti[i].rapporto = (float) lista_oggetti[i].valore / lista_oggetti[i].costo;
    }

    for (int i = 0; i < n_oggetti - 1; i++) {
        for (int j = i + 1; j < n_oggetti; j++) {
            if (lista_oggetti[i].rapporto < lista_oggetti[j].rapporto) {
                struct oggetto temp = lista_oggetti[i];
                lista_oggetti[i] = lista_oggetti[j];
                lista_oggetti[j] = temp;
            }
        }
    }
}

// Funzione per calcolare la soluzione con metodo 1
void soluzioneUno(struct oggetto lista_oggetti[], int n_oggetti, int capac) {
    ordinaOggettiPerRapporto(lista_oggetti, n_oggetti);

    int capac_residua = capac;
    printf("Oggetti selezionati:\n");

    for (int i = 0; i < n_oggetti; i++) {
        if (lista_oggetti[i].costo <= capac_residua) {
            printf("ID: %s, Costo: %d, Valore: %d\n", lista_oggetti[i].id, lista_oggetti[i].costo, lista_oggetti[i].valore);
            capac_residua -= lista_oggetti[i].costo;
        }
    }

    if (capac_residua == capac) {
        printf("Nessun oggetto selezionato.\n");
    }
}
