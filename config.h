#ifndef CONFIG_H
#define CONFIG_H

#define LARGEUR 50
#define HAUTEUR 50

struct Robot
{
    int x, y;
    double angle;
    int nbChangementDirection; // -1 pour la droite, +1 pour la gauche
    int estSorti;
};

enum {MUR, VIDE, SORTIE, ROBOT};

typedef struct Robot Robot;

#endif // CONFIG_H
