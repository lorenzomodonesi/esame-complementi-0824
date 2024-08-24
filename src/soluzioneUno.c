#include <stdio.h>
#include "../headers/oggetto.h"
#include "../headers/soluzioneUno.h"
#include "../headers/aspettaEnter.h"
#include "../headers/ordinaOggettiPerRapporto.h"

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
    aspettaEnter();
}
