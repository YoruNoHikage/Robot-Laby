#include "config.h"
#include "affichage.h"

void afficher(int carte[][LARGEUR], Robot *bot)
{
    int i, j;
    for(i = 0 ; i < HAUTEUR ; i++)
    {
        for(j = 0 ; j < LARGEUR ; j++)
        {
            if(i == bot->y && j == bot->x)
                printf("R");
            else
            {
                switch(carte[i][j])
                {
                    case MUR:
                        printf("x");
                        break;
                    case SORTIE:
                        printf("S");
                        break;
                    default:
                        printf(" ");
                        break;
                }
            }
        }
        printf("\n");
    }
}
