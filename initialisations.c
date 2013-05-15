#include <string.h>
#include <math.h>

#include "appart.h"

#include "config.h"
#include "initialisations.h"

void recupererCarte(int carte[][LARGEUR])
{
    int i, j, k = 0;
    for(i = 0 ; i < HAUTEUR ; i++)
        for(j = 0 ; j < LARGEUR ; j++)
        {
            switch(appart[k])
            {
                case 'x':
                    carte[i][j] = MUR;
                    break;
                case 'S':
                    carte[i][j] = SORTIE;
                    break;
                case 'R':
                    carte[i][j] = ROBOT;
                    break;
                case ' ':
                    carte[i][j] = VIDE;
                    break;
            }
            k++;
        }
}

void initialiserRobot(Robot *bot, int carte[][LARGEUR])
{
    int i, j;
    for(i = 0 ; i < HAUTEUR ; i++)
        for(j = 0 ; j < LARGEUR ; j++)
            if(carte[i][j] == ROBOT)
            {
                bot->y = i;
                bot->x = j;
                carte[i][j] = VIDE; // On enlève le robot car on laisse cela à l'affichage
                break;
            }

    bot->nbChangementDirection = 0;
    bot->nbActions = 0;
    bot->angle = M_PI / 2; // on initialise le robot pour qu'il aille vers le haut
    bot->estSorti = 0;
}
