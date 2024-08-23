#include <stdio.h>
#include <stdlib.h>
#include "../headers/oggetto.h"
#include "../headers/aspettaEnter.h"

void soluzioneDue(struct oggetto lista_oggetti[], int n_oggetti, int capac, int max_oggetti) {
    struct oggetto oggetti_selezionati[max_oggetti];
    int capac_usata = 0;
    int num_oggetti_selezionati = 0;

    for (int n = 1; n <= n_oggetti; n++) {
        int capac_temp = 0;
        int temp_selezionati[max_oggetti];

        for (int k = 0; k < max_oggetti; k++) {
            temp_selezionati[k] = -1;
        }

        for (int i = 0; i < n; i++) {
            int indice_casuale = rand() % n_oggetti;
            capac_temp += lista_oggetti[indice_casuale].costo;

            if (capac_temp > capac) {
                break;
            }

            temp_selezionati[i] = indice_casuale;
        }

        if (capac_temp <= capac && capac_temp > capac_usata) {
            capac_usata = capac_temp;
            num_oggetti_selezionati = n;

            for (int i = 0; i < n; i++) {
                if (temp_selezionati[i] != -1) {
                    oggetti_selezionati[i] = lista_oggetti[temp_selezionati[i]];
                }
            }
        }
    }

    printf("Oggetti selezionati:\n");
    for (int i = 0; i < num_oggetti_selezionati; i++) {
        printf("ID: %s, Costo: %d, Valore: %d\n",
               oggetti_selezionati[i].id,
               oggetti_selezionati[i].costo,
               oggetti_selezionati[i].valore);
    }

    if (capac_usata == 0) {
        printf("Nessun oggetto selezionato.\n");
    }

    aspettaEnter();
}
