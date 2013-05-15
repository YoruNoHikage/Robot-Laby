#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define WINDOWS
#if defined(WINDOWS)
    #include <windows.h>
#endif

#include "initialisations.h"
#include "affichage.h"

int main()
{
    char carte[HAUTEUR][LARGEUR];
    Robot bot;

    // Initialisations
    recupererCarte(carte);
    initialiserRobot(&bot, carte);

    // Boucle principale
    while(1)
    {
        // mise à jour
        bot.x++; // test
        bot.y++; // test

        // affichage
#if defined(WINDOWS)
        system("cls");
#else
        system("clear");
#endif
        afficher(carte, &bot);

#if defined(WINDOWS)
        Sleep(1);
#else
        sleep(1);
#endif

        if(bot.x > LARGEUR || bot.y > HAUTEUR)
            break;
    }

    return EXIT_SUCCESS;
}
