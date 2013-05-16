#ifndef GRAPHIQUE_H
#define GRAPHIQUE_H

#include "SFML/Graphics.h"

struct Contexte
{
    sfRenderWindow *window;
    sfEvent event;
    sfView *view;
    sfClock *clock;
    sfTime tempsEcoule;


    sfTexture *tileset;
    sfSprite *robot;
    sfVertexArray *vertices;
};
typedef struct Contexte Contexte;

void initialiserGraphique(Contexte *contexte, int carte[][LARGEUR]);
int bouclePrincipaleGraphique(Contexte *contexte, Robot *bot, int carte[][LARGEUR]);
void liberationGraphique(Contexte *contexte);

int loadTileMap(Contexte *contexte, int carte[][LARGEUR]);

#endif // GRAPHIQUE_H
