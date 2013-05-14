#include <string.h>

#include "appart.h"

#include "config.h"
#include "initialisations.h"

void recupererCarte(char carte[][LARGEUR])
{
    int i = 0;

    for(i = 0 ; i < HAUTEUR ; i++)
        strncpy(carte[i], appart + i * LARGEUR, LARGEUR);
}
