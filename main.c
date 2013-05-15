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
        Sleep(1);
        system("cls");
#else
        sleep(1);
        system("clear");
#endif
    }

    printf("Nombre de deplacements : %d\n", bot.nbActions);

#if defined(WINDOWS)
    system("pause");
#endif

    return EXIT_SUCCESS;
}
