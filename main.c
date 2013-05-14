#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "affichage.h"

int main()
{
    char carte[HAUTEUR][LARGEUR];

    recupererCarte(carte);
    afficherCarte(carte);

    return EXIT_SUCCESS;
}
