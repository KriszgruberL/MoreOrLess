#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/*Le principe est le suivant.
1. L'ordinateur tire au sort un nombre entre 1 et 100.
2. Il vous demande de deviner le nombre. Vous entrez donc un nombre entre 1 et 100.
3. L'ordinateur compare le nombre que vous avez entré avec le nombre « mystère » qu'il a tiré au sort. Il vous dit si le
nombre mystère est supérieur ou inférieur à celui que vous avez entré.
4. Puis l'ordinateur vous redemande le nombre.
5. … Et il vous indique si le nombre mystère est supérieur ou inférieur.
6. Et ainsi de suite, jusqu'à ce que vous trouviez le nombre mystère.

 Blindage ✅
 Difficulté avec des variables de guesses, limite supérieur de nombres
 Nombre random choisi par l'ordinateur ✅
 Auto résolution par l'ordi avec recherche dichotomique */

//Macro
// Remplacer au moment de la compilation par les valeur de la macro, ne prends pas de place mémoire
#define tryPlurial "ies" : "y"

int main() {
    int computer_nb,
        player_nb = 0,
        cpt = 5,
        min = 0,
        max = 100;

    srand(time(NULL));
    computer_nb = (rand() % (max - min + 1)) + min;

//    Mode multiplayer (2)
//    do {
//        printf("Please enter the mysterious number between 0 and 100 : \n");
//        scanf("%d", &computer_nb);
//    } while ( computer_nb < 0 || computer_nb > 100 );

//    system("cls");
    do {
        do {
            printf("Please enter your guess between %d and %d : \n", min, max);
            scanf("%d", &player_nb);
            if(player_nb > max || player_nb < min){
                printf("%d is not a valid number. The guess has to be between %d and %d\n", player_nb, min, max);
                printf("Number of tr%s left : %d \n", cpt > 1 ? "ies" : "y", cpt);
            }
        } while (player_nb < min || player_nb > max );

        if (computer_nb > player_nb){
            printf("More\n");
            cpt--;
            printf("Number of tr%s left : %d \n", cpt > 1 ? tryPlurial, cpt);
        } else if (computer_nb < player_nb){
            printf("Less\n");
            cpt--;
            printf("Number of tr%s left : %d \n", cpt > 1 ? tryPlurial, cpt);
        } else {
            printf("Congratulations, you've found it in %d tr%s!\n", cpt--, cpt > 1 ? tryPlurial);
        }
    } while (cpt != 0 && computer_nb != player_nb);

    printf("\nYou loose, the number was %d", computer_nb);

    return 0;
}

