#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "config.h"

#ifdef GRAPHIQUE
    #include "graphique.h"
#endif

#ifdef WINDOWS && GRAPHIQUE
    #include <windows.h>
#endif

#include "initialisations.h"
#include "affichage.h"
#include "deplacement.h"

int main()
{
    int carte[HAUTEUR][LARGEUR];
    Robot bot;
    int continuer = 1;

    // Initialisations
    recupererCarte(carte);
    initialiserRobot(&bot, carte);

    #ifdef GRAPHIQUE
        Contexte contexteGraphique;

        initialiserGraphique(&contexteGraphique);
    #endif

    // Boucle principale
    while(continuer)
    {
        // mise à jour
        deplacerRobot(&bot, carte);

        #ifndef GRAPHIQUE
            afficher(carte, &bot);

            #if defined(WINDOWS)
                    Sleep(1);
                    system("cls");
            #else
                    sleep(1);
                    system("clear");
            #endif

            continuer = !bot.estSorti;
        #else
            continuer = bouclePrincipaleGraphique(&contexteGraphique);
        #endif
    }

    #ifndef GRAPHIQUE
        printf("Nombre de deplacements : %d\n", bot.nbActions);

        #ifdef WINDOWS
            system("pause");
        #endif
    #else
        liberationGraphique(&contexteGraphique);
    #endif

    return EXIT_SUCCESS;
}
