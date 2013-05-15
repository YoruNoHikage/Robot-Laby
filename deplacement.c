#include <math.h>

#include "config.h"
#include "deplacement.h"
#include "affichage.h"

void deplacerRobot(Robot *bot, int carte[][LARGEUR])
{
    int x = bot->x + (int)cos(bot->angle);
    int y = bot->y - (int)sin(bot->angle); // - parce que le y est inversé

    switch(carte[y][x])
    {
        case VIDE:
            if(bot->nbChangementDirection != 0)
            {
                bot->angle += M_PI / 2;
                bot->nbChangementDirection += 1;
                bot->nbActions++;
            }

            bot->x = x;
            bot->y = y;
            bot->nbActions++;
            break;
        case MUR:
            bot->angle -= M_PI / 2;
            bot->nbChangementDirection -= 1;
            break;
        case SORTIE:
            bot->x = x;
            bot->y = y;
            bot->nbActions++;

            bot->estSorti = 1;
            break;
    }
}
