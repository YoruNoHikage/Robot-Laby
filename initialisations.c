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

void initialiserRobot(Robot *bot, char carte[][LARGEUR])
{
    int i, j;
    for(i = 0 ; i < HAUTEUR ; i++)
        for(j = 0 ; j < LARGEUR ; j++)
            if(carte[i][j] == 'R')
            {
                bot->y = j;
                bot->x = i;
                carte[i][j] = ' '; // On enlève le robot car on laisse cela à l'affichage
                break;
            }

    bot->nbChangementDirection = 0;
    bot->angle = 0;
}
