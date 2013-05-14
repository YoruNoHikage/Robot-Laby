#include "config.h"
#include "affichage.h"

void afficherCarte(const char carte[][LARGEUR])
{
    int i, j;
    for(i = 0 ; i < HAUTEUR ; i++)
    {
        for(j = 0 ; j < LARGEUR ; j++)
            printf("%c", carte[i][j]);
        printf("\n");
    }
}
