#include "../headers/oggetto.h"

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
