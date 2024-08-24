#include <stdio.h>
#include <string.h>
#include "../headers/oggetto.h"
#include "../headers/ordinaOggettiPerRapporto.h"
#include "../headers/soluzioneTre.h"
#include "../headers/aspettaEnter.h"

void soluzioneTre(struct oggetto lista_oggetti[], int n_oggetti, int capac) {
    char id[10];
    int capac_residua = capac;
    int oggetti_selezionati = 0;
    struct oggetto oggetti_selezionati_lista[n_oggetti];

    printf("Inserisci gli ID degli oggetti da includere (termina con 'STOP'):\n");

    while (1) {
        scanf("%s", id);
        if (strcmp(id, "STOP") == 0) break;

        int found = 0;
        for (int i = 0; i < n_oggetti; i++) {
            if (strcmp(lista_oggetti[i].id, id) == 0) {
                if (lista_oggetti[i].costo <= capac_residua) {
                    printf("ID: %s, Costo: %d, Valore: %d\n", lista_oggetti[i].id, lista_oggetti[i].costo, lista_oggetti[i].valore);
                    oggetti_selezionati_lista[oggetti_selezionati] = lista_oggetti[i];
                    capac_residua -= lista_oggetti[i].costo;
                    oggetti_selezionati++;
                    found = 1;
                    break;
                } else {
                    printf("Oggetto %s supera la capacità residua.\n", id);
                    return;
                }
            }
        }
        if (!found) {
            printf("Oggetto %s non trovato.\n", id);
        }
    }

    ordinaOggettiPerRapporto(lista_oggetti, n_oggetti);

    for (int i = 0; i < n_oggetti; i++) {
        if (lista_oggetti[i].costo <= capac_residua) {
            oggetti_selezionati_lista[oggetti_selezionati] = lista_oggetti[i];
            capac_residua -= lista_oggetti[i].costo;
            oggetti_selezionati++;
        }
    }

    printf("Oggetti selezionati:\n");
    for (int i = 0; i < oggetti_selezionati; i++) {
        printf("ID: %s, Costo: %d, Valore: %d\n",
               oggetti_selezionati_lista[i].id,
               oggetti_selezionati_lista[i].costo,
               oggetti_selezionati_lista[i].valore);
    }

    if (oggetti_selezionati == 0) {
        printf("Nessun oggetto selezionato.\n");
    }

    aspettaEnter();
}
