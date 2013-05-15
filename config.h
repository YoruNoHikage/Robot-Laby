#ifndef CONFIG_H
#define CONFIG_H

#define LARGEUR 50
#define HAUTEUR 50

struct Robot
{
    int x, y;
    float angle;
    int nbChangementDirection; // -1 pour la droite, +1 pour la gauche
};

typedef struct Robot Robot;

#endif // CONFIG_H
