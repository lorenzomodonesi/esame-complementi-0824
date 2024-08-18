#include <stdio.h>
#include <string.h>
#include "../headers/inserisciOggetto.h"
#include "../headers/oggetto.h"

struct oggetto inserisciOggetto(struct oggetto lista_oggetti[], int n_oggetti) {
    struct oggetto obj;
    int id_unique = 0;

    // Garantiamo l'unicità dell'ID
    while (!id_unique) {
        printf("Inserisci l'id dell'oggetto: ");
        scanf("%s", obj.id);
        id_unique = 1;

        for (int i = 0; i < n_oggetti; i++) {
            if (strcmp(lista_oggetti[i].id, obj.id) == 0) {
                id_unique = 0;
                printf("ID già utilizzato, riprova.\n");
                break;
            }
        }
    }

    printf("Inserisci il costo dell'oggetto: ");
    scanf("%d", &obj.costo);
    printf("Inserisci il valore dell'oggetto: ");
    scanf("%d", &obj.valore);
    obj.rapporto = 0;

    return obj;
}
