#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define WINDOWS
#if defined(WINDOWS)
    #include <windows.h>
#endif

#include "initialisations.h"
#include "affichage.h"
#include "deplacement.h"

int main()
{
    int carte[HAUTEUR][LARGEUR], i = 0;
    Robot bot;

    // Initialisations
    recupererCarte(carte);
    initialiserRobot(&bot, carte);

    // Boucle principale
    while(!bot.estSorti)
    {
        // mise à jour
        deplacerRobot(&bot, carte);

        afficher(carte, &bot);

        // affichage
#if defined(WINDOWS)
        system("cls");
        Sleep(1);
#else
        system("clear");
        sleep(1);
#endif

        if(bot.x > LARGEUR || bot.y > HAUTEUR)
            break;

        i++;
    }

    system("pause");

    return EXIT_SUCCESS;
}
