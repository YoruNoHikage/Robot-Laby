#ifndef GRAPHIQUE_H
#define GRAPHIQUE_H

#include "SFML/Graphics.h"

struct Contexte
{
    sfRenderWindow *window;
    sfEvent event;
};
typedef struct Contexte Contexte;

void initialiserGraphique(Contexte *contexte);
int bouclePrincipaleGraphique(Contexte *contexte);
void liberationGraphique(Contexte *contexte);

#endif // GRAPHIQUE_H
