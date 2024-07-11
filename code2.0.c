#include <stdio.h>
#include <stdlib.h>

#define LIGNE 10
#define COLONNE 10

//On a créé une fonction pour initialiser la feuille vide
void feuille_initiale(char grille[LIGNE][COLONNE]) {
    for (int i = 0; i < LIGNE; ++i) {
        for (int j = 0; j < COLONNE; ++j) {
            grille[i][j] = ' ';
        }
    }
}

//Ensuite, une fonction pour afficher la grille sur la feuille
void feuille(char grille[LIGNE][COLONNE]) {
    printf("\n");
    for (int i = 0; i < LIGNE; ++i) {
        for (int j = 0; j < COLONNE; ++j) {
            printf("%c ", grille[i][j]);
        }
        printf("\n");
    }
}

//Cette fonction a pour but de vérifier s'il y a une ligne alignée de 5 points
int victoire(char grille[LIGNE][COLONNE], char joueur) {
    //Celle-ci sert à vérifier les lignes horizontales
    for (int i = 0; i < LIGNE; ++i) {
        for (int j = 0; j <= COLONNE - 5; ++j) {
            int compteur = 0;
            for (int k = 0; k < 5; ++k) {
                if (grille[i][j + k] == joueur) {
                    compteur++;
                }
            }
            if (compteur == 5) {
                return 1; //Ça veut dire que le joueur gagne
            }
        }
    }

    //Cette fonction sert à vérifier les lignes verticales
    for (int i = 0; i <= LIGNE - 5; ++i) {
        for (int j = 0; j < COLONNE; ++j) {
            int compteur = 0;
            for (int k = 0; k < 5; ++k) {
                if (grille[i + k][j] == joueur) {
                    compteur++;
                }
            }
            if (compteur == 5) {
                return 1; // Le joueur a gagné
            }
        }
    }

    //Celle-ci sert à vérifier les lignes diagonales (\)
    for (int i = 0; i <= LIGNE - 5; ++i) {
        for (int j = 0; j <= COLONNE - 5; ++j) {
            int compteur = 0;
            for (int k = 0; k < 5; ++k) {
                if (grille[i + k][j + k] == joueur) {
                    compteur++;
                }
            }
            if (compteur == 5) {
                return 1; // Le joueur gagne
            }
        }
    }

    //Cette fonction sert aussi à vérifer les lignes diagonales mais de l'entre sens(/)
    for (int i = 0; i <= LIGNE - 5; ++i) {
        for (int j = 4; j < COLONNE; ++j) {
            int compteur = 0;
            for (int k = 0; k < 5; ++k) {
                if (grille[i + k][j - k] == joueur) {
                    compteur++;
                }
            }
            if (compteur == 5) {
                return 1; // Le joueur a gagné
            }
        }
    }

    return 0; //Ça veut dire q'aucune ligne n'est alignée
}

int main() {
    char grille[LIGNE][COLONNE];
    int ligne, colonne;
    char joueur_actuel = 'X';

    feuille_initiale(grille);

    do {
        feuille(grille);

        //Demander au joueur actuel de placer un point
        printf("Joueur %c, entrez la ligne et la colonne (ex: 1 2) : ", joueur_actuel);
        scanf("%d %d", &ligne, &colonne);

        //Il faut vérifier si la case est valide
        if (ligne < 0 || ligne >= LIGNE || colonne < 0 || colonne >= COLONNE || grille[ligne][colonne] != ' ') {
            printf("Case invalide. Réessayez.\n");
            continue;
        }

        // Placement du point du joueur actuel si c'est valide
        grille[ligne][colonne] = joueur_actuel;

        //Vérifier si le joueur actuel a gagné
        if (victoire(grille, joueur_actuel)) {
            feuille(grille);
            printf("Joueur %c a gagné !\n", joueur_actuel);
            break;
        }

        // Changement du joueur 1:X en joueur 2:O
        joueur_actuel = (joueur_actuel == 'X') ? 'O' : 'X';

    } while (1); // La boucle continue indéfiniment(jusqu'à ce que qu'un joueur gagne), car le jeu se termine lorsque quelqu'un gagne.

    return 0;
}
