#include <stdlib.h>

#include "config.h"
#include "graphique.h"

void initialiserGraphique(Contexte *contexte)
{
    sfVideoMode mode = {800, 600, 32};

    contexte->window = sfRenderWindow_create(mode, "RobotLaby", sfClose, NULL);
    if(!contexte->window)
        exit(EXIT_FAILURE);
}

int bouclePrincipaleGraphique(Contexte *contexte)
{
    sfEvent event = contexte->event;
    while (sfRenderWindow_pollEvent(contexte->window, &event))
    {
        if(event.type == sfEvtClosed)
            sfRenderWindow_close(contexte->window);

        sfRenderWindow_clear(contexte->window, sfBlack);

        sfRenderWindow_display(contexte->window);
    }

    return sfRenderWindow_isOpen(contexte->window);
}

void liberationGraphique(Contexte *contexte)
{
    sfRenderWindow_destroy(contexte->window);
}
