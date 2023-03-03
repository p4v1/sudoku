#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>


/*
Pour l'exercice vous aurez besoin de generer des entiers aléatoire : rand() renvoit un entier aléatoire.
il s'utilise : rand() % NOMBREMAX + 1
Pour un entier aléatoire entre 0 et 1 il faut donc faire rand() %2
voir dans la methode main.
*/






// Ecrire la fonction generer(), elle prend en paramètre la grille et renvoie le nombre d'éléments non nuls

// Ce lien vous sera utile : https://www.geeksforgeeks.org/pass-2d-array-parameter-c/


/*Écrire une fonction saisir() qui demande à l’utilisateur de saisir au clavier les indices i et j et la valeur v à placer à l’emplacement (i,j).
La fonction doit vérifier la validité des indices et de la valeur.
Si la case n’est pas occupée, la valeur doit être placée dans la grille. remplissage est alors incrémentée*/


/*
Écrire la fonction verifierLigneColonne() qui prend en paramètre un numéro et un sens (HORIZ ou VERT)
qui vérifie que la ligne ou la colonne (suivant les cas) numéro est bien remplie.
On pourra utiliser un tableau intermédiaire pour vérifier cela. La fonction retournera 1 si tout s’est bien passé, 0 sinon.
 Les constantes HORIZ de valeur 0 et VERT de valeur 1 sont à définir.
*/

/*
Écrire la fonction verifierRegion() qui prend en paramètre deux indices k et l qui correspondent à la région (k,l)
et qui renvoie 1 si la région est correctement remplie, 0 sinon.
*/

//Écrire la fonction verifierGrille() qui renvoie 1 si la grille est correctement remplie et 0 sinon


//Écrire le programme principal, en supposant que la seule condition d’arrêt est la réussite du sudoku (ce test ne devra être fait que si nécessaire)


int main() {
    // Ne pas toucher le code entre les commentaires
    srand(time(NULL));


    int i, j, k;
    int solution[9][9];
    printf("SOLUTION");
    printf("\n");
    printf("---------------------------------");
    printf("\n");
    for (j = 0; j < 9; ++j) {
        for (i = 0; i < 9; ++i)
            solution[j][i] = (i + j * 3 + j / 3) % 9 + 1;
    }

//    for (i = 0; i < 9; ++i) {
//        for (j = 0; j < 9; ++j)
//            printf("%d ", solution[i][j]);
//        printf("\n");
//    }
//    printf("---------------------------------");
//    printf("\n");
//    //toucher le code entre les commentaires





//génère le tableau de jeu
//typedef struct {
//    int i;
//    int j;
//
//} Col;
//Col col[9][9];

    int grid[9][9];
    int x =  rand() % 1;

    for (j = 0; j < 9; ++j) {
        for (i = 0; i < 9; ++i)
            grid[j][i] = (i + j * 3 + j / 3) % 9 + 1;
    }



    srand(time(NULL));
    for (i = 0; i < 9; i++) {
        for (j = 0; j < 9; j++) {
            grid[i][j] = x;
            if (rand() % 2 == 0)
                grid[i][j] = solution[i][j];
            printf("%d ", grid[i][j]);
        }
        printf("\n");
    }

    int l, c, v;

    while (grid[9][9] != solution[9][9])
    {

        printf("Veuillez saisir la ligne\n");
        scanf("%d", &l);

        printf("Veuillez saisir la colonne\n");
        scanf("%d", &c);

        printf("Veuillez saisir la valeur\n");
        scanf("%d", &v);

        for (j = 0; j < 9; ++j) {
            for (i = 0; i < 9; ++i){
                grid[l][c]=v;
                grid[l][c] =grid[i][j] ;
            printf("%d ", grid[l][c]);
            }
            printf("\n");
        }

    }











//vérifie la colonne
    int check_col(int grid[9][9], int col) {
        for (int i = 0; i < 8; i++) {
            for (int k = i + 1; k < 9; k++) {
                if (grid[i][col] == grid[k][col]) {
                    printf("Doublon trouvé sur la colonne %d\n", col+1);
                    return 0;
                }
            }
        }
        return 1;
    }
//vérifie la ligne
    int check_row(int grid[9][9], int row) {
        for (int j = 0; j < 8; j++) {
            for (int k = j + 1; k < 9; k++) {
                if (grid[row][j] == grid[row][k]) {
                    printf("Doublon trouvé sur la ligne %d\n", row+1);
                    return 0;
                }
            }
        }
        return 1;
    }





    //Ne pas toucher au code ci dessous
    system("pause");
    return 0;

}