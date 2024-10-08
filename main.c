#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "headers/oggetto.h"
#include "headers/caricaDaFile.h"
#include "headers/inserisciOggetto.h"
#include "headers/visualizzaOggetti.h"
#include "headers/trovaEstremi.h"
#include "headers/cercaOggettoPerID.h"
#include "headers/cercaOggettiPerCosto.h"
#include "headers/soluzioneUno.h"
#include "headers/soluzioneDue.h"
#include "headers/soluzioneTre.h"

#define MAX_OGGETTI 100

// Allochiamo lo spazio per MAX_OGGETTI struct oggetto
struct oggetto lista_oggetti[MAX_OGGETTI];

int n_oggetti = 0;
int capac = 0;
int oggetti_caricati = 0;

void menu() {
    int scelta;
    do {
        printf("\nMenu:\n");
        printf("1. Inserisci oggetti da tastiera\n");
        printf("2. Carica oggetti da file\n");
        if(oggetti_caricati) {
            printf("3. Visualizza oggetti\n");
            printf("4. Trova oggetti con valore/costo massimo o minimo\n");
            printf("5. Cerca oggetto per ID\n");
            printf("6. Cerca oggetti con costo minore di un certo valore\n");
            printf("7. Soluzione Uno\n");
            printf("8. Soluzione Due\n");
            printf("9. Soluzione Tre\n");
        }
        printf("0. Esci\n");
        printf("Scegli un'opzione: ");
        scanf("%d", &scelta);

        switch (scelta) {
            case 1:
                 if (n_oggetti < MAX_OGGETTI) {
                    lista_oggetti[n_oggetti++] = inserisciOggetto(lista_oggetti, n_oggetti);
                    oggetti_caricati = 1;
                } else {
                    printf("Numero massimo di oggetti raggiunto.\n");
                }
                break;
            case 2:
                oggetti_caricati = caricaDaFile(lista_oggetti, &n_oggetti, &capac);
                break;
            case 3:
                visualizzaOggetti(lista_oggetti, n_oggetti);
                break;
            case 4:
                trovaEstremi(lista_oggetti, n_oggetti);
                break;
            case 5:
                cercaOggettoPerID(lista_oggetti, n_oggetti);
                break;
            case 6:
                cercaOggettiPerCosto(lista_oggetti, n_oggetti);
                break;
            case 7:
                soluzioneUno(lista_oggetti, n_oggetti, capac);
                break;
            case 8:
                soluzioneDue(lista_oggetti, n_oggetti, capac, MAX_OGGETTI);
                break;
            case 9:
                soluzioneTre(lista_oggetti, n_oggetti, capac);
                break;
            case 0:
                break;
            default:
                printf("Opzione non valida.\n");
        }
    } while (scelta != 0);
}

int main() {
    menu();
    return 0;
}
