#include <stdlib.h>

#include "config.h"
#include "deplacement.h"
#include "graphique.h"

void initialiserGraphique(Contexte *contexte, int carte[][LARGEUR])
{
    sfVideoMode mode = {600, 600, 32}; // Taille de la fenêtre
    sfFloatRect rects = {0, 0, 800, 800}; // Taille du monde 2D

    sfIntRect robotRects = {0, 32, 16, 48};

    contexte->window = sfRenderWindow_create(mode, "RobotLaby", sfClose, NULL);
    if(!contexte->window)
        exit(EXIT_FAILURE);

    contexte->view = sfView_createFromRect(rects);
    sfRenderWindow_setView(contexte->window, contexte->view); // On set une vue pour redimensionner dynamiquement

    contexte->tileset = sfTexture_createFromFile("tileset.png", NULL);
    if(!contexte->tileset)
        exit(EXIT_FAILURE);

    // On charge le tableau de vertex pour créer un monde de tile
    if(!loadTileMap(contexte, carte))
        exit(EXIT_FAILURE);

    // Chargement du sprite du robot à partir du tileset
    contexte->robot = sfSprite_create();
    sfSprite_setTexture(contexte->robot, contexte->tileset, sfTrue);
    sfSprite_setTextureRect(contexte->robot, robotRects);

    contexte->clock = sfClock_create();
}

int loadTileMap(Contexte *contexte, int carte[][LARGEUR])
{
    int i, j;

    contexte->vertices = sfVertexArray_create();

    // On redimensionne le tableau pour contenir le monde
    sfVertexArray_setPrimitiveType(contexte->vertices, sfQuads);
    sfVertexArray_resize(contexte->vertices, HAUTEUR * LARGEUR * 4);

    for(i = 0 ; i < HAUTEUR ; i++)
    {
        for(j = 0 ; j < LARGEUR ; j++)
        {
            int numeroTile = carte[j][i];
            // TMP
            sfColor color1, color2;

            int tx = 0, ty;
            switch(numeroTile)
            {
                case MUR:
                    ty = 16;
                    color1 = sfColor_fromRGB(0, 0, 0);
                    color2 = sfColor_fromRGB(0, 0, 0);
                    break;
                case SORTIE: // image à changer
                    ty = 0; // à changer
                    break;
                default:
                    color1 = sfColor_fromRGB(0, 200, 0);
                    color2 = sfColor_fromRGB(0, 200, 0);
                    ty = 0;
                    break;
            }

            sfVertex *quad = sfVertexArray_getVertex(contexte->vertices, (i + j * HAUTEUR) * 4);

            sfVector2f position = {i * 16, j * 16};
            quad[0].position = position; // position haut gauche
            position.x += 16;
            quad[1].position = position;
            position.y += 16;
            quad[2].position = position;
            position.x -= 16;
            quad[3].position = position;

            /*sfVector2f coord = {tx * 16, ty * 16};
            quad[0].texCoords = coord;
            coord.x += 16;
            quad[1].texCoords = coord;
            coord.y += 16;
            quad[2].texCoords = coord;
            coord.x -= 16;
            quad[3].texCoords = coord;*/

            quad[0].color = color1;
            quad[1].color = color2;
            quad[2].color = color1;
            quad[3].color = color2;
        }
    }

    return 1;
}

int bouclePrincipaleGraphique(Contexte *contexte, Robot *bot, int carte[][LARGEUR])
{
    sfEvent event = contexte->event;
    while (sfRenderWindow_pollEvent(contexte->window, &event))
    {
        if(event.type == sfEvtClosed)
            sfRenderWindow_close(contexte->window);
    }

    // Mise à jour
    contexte->tempsEcoule.microseconds += sfClock_restart(contexte->clock).microseconds;
    if(sfTime_asMilliseconds(contexte->tempsEcoule) > 20)
    {
        contexte->tempsEcoule = sfTime_Zero;
        deplacerRobot(bot, carte);
    }

    sfVector2f position = {bot->x * 16, bot->y * 16};
    sfSprite_setPosition(contexte->robot, position);

    // Affichage
    sfRenderWindow_clear(contexte->window, sfBlack);

    sfRenderWindow_drawVertexArray(contexte->window, contexte->vertices, NULL);
    sfRenderWindow_drawSprite(contexte->window, contexte->robot, NULL);

    sfRenderWindow_display(contexte->window);

    return sfRenderWindow_isOpen(contexte->window);
}

void liberationGraphique(Contexte *contexte)
{
    sfVertexArray_destroy(contexte->vertices);
    sfSprite_destroy(contexte->robot);
    sfTexture_destroy(contexte->tileset);
    sfRenderWindow_destroy(contexte->window);
}
