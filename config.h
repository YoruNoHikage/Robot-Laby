#ifndef CONFIG_H
#define CONFIG_H

// defini le système d'exploitation
#define WINDOWS

// défini que l'on veut l'interface graphique
#define GRAPHIQUE

#define LARGEUR 50
#define HAUTEUR 50

struct Robot
{
    int x, y;
    double angle;
    int nbChangementDirection; // -1 pour la droite, +1 pour la gauche
    int nbActions;
    int estSorti;
};

enum {MUR, VIDE, SORTIE, ROBOT};

typedef struct Robot Robot;

#endif // CONFIG_H
