#include "config.h"
#include "affichage.h"

void afficher(char carte[][LARGEUR], Robot *bot)
{
    int i, j;
    for(i = 0 ; i < HAUTEUR ; i++)
    {
        for(j = 0 ; j < LARGEUR ; j++)
        {
            if(i == bot->x && j == bot->y)
                printf("R");
            else
                printf("%c", carte[i][j]);
        }
        printf("\n");
    }
}
