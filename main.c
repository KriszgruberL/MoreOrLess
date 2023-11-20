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
#define tryPlurial cpt > 1 ? "ies" : "y"
#define nbTryLeft 5

//TODO function that allow for different difficulties with function that set up min, max, nbTryLeft
// TODO menu to chose said difficulty
// TODO Dichotomy search so the computer can resolve the game itself like a big boy
// TODO Multiplayer mode

int main() {
    int computer_nb,
        player_nb = 0,
        cpt = 0,
        min = 0,
        max = 100;

    srand(time(NULL));
    computer_nb = (rand() % (max - min + 1)) + min;
    printf("%d\n", computer_nb);

//    Mode multiplayer (2)
//    do {
//        printf("Please enter the mysterious number between 0 and 100 : \n");
//        scanf("%d", &computer_nb);
//    } while ( computer_nb < 0 || computer_nb > 100 );

//    system("cls");
    do {
        do {
//            Guesses
            printf("Please enter your guess between %d and %d : \n", min, max);
            scanf("%d", &player_nb);
            if(player_nb > max || player_nb < min){
//                Verify that the number chosed is between max and min
                printf("%d is not a valid number. The guess has to be between %d and %d\n", player_nb, min, max);
            }
        } while (player_nb < min || player_nb > max );

//       Increment cpt no matter the result
        cpt++;
//        More or less check
        if (computer_nb > player_nb){
            printf("More\n");
            printf("You tried : %d / %d\n", cpt, nbTryLeft);
        } else if (computer_nb < player_nb) {
            printf("Less\n");
            printf("You tried : %d / %d\n", cpt, nbTryLeft);
        }
//      Check if there are still attempts remaining and if the guessed number is incorrect
    } while ((cpt < nbTryLeft) && (computer_nb != player_nb));

//    Print result
    if (computer_nb == player_nb) {
        printf("Congratulations, you've found the correct number in %d tr%s!\n", cpt, tryPlurial);
    } else {
        printf("\nYou loose, the number was %d", computer_nb);
    }

    return 0;
}

