#ifndef OGGETTO_H
#define OGGETTO_H

struct oggetto {
    char id[10];     // Identificativo univoco
    int costo;       // Costo dell'oggetto
    int valore;      // Valore dell'oggetto
    float rapporto;  // Rapporto valore/costo
};

#endif
