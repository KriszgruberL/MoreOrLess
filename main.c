#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>

/*Le principe est le suivant.
1. L'ordinateur tire au sort un nombre entre 1 et 100.
2. Il vous demande de deviner le nombre. Vous entrez donc un nombre entre 1 et 100.
3. L'ordinateur compare le nombre que vous avez entré avec le nombre « mystère » qu'il a tiré au sort. Il vous dit si le
nombre mystère est supérieur ou inférieur à celui que vous avez entré.
4. Puis l'ordinateur vous redemande le nombre.
5. … Et il vous indique si le nombre mystère est supérieur ou inférieur.
6. Et ainsi de suite, jusqu'à ce que vous trouviez le nombre mystère.

 Blindage ✅
 Difficulté avec des variables de guesses, limite supérieur de nombres ✅
 Nombre random choisi par l'ordinateur ✅
 Auto résolution par l'ordi avec recherche dichotomique ✅*/

//Macro
// Remplacer au moment de la compilation par les valeur de la macro, ne prends pas de place mémoire
#define tryPlurial cpt > 1 ? "ies" : "y"

// TODO Clean algorithm automode



void multiplayerMode();

void soloMode();

void autoMode();

int randomComputerNb(int min_i, int max_i);

void gameLevel(int min_i, int max_i, int tries_i);

int computer_nb, player_nb,
        cpt,
        tries, min, max, // Needed for the multiplayer part
modeChoice, levelChoice;

int main() {
    computer_nb = 0,
    player_nb = 0,
    cpt = 0,
    tries = 0;
    modeChoice = 0;

    do {
        printf("Choose your play mode");
        printf("\n1. Solo mode");
        printf("\n2. Multiplayer mode");
        printf("\n3. Auto mode");
        printf("\n9. Quit\n");
        scanf("%d", &modeChoice);

        switch (modeChoice) {
            case 1 :
                soloMode();
                break;
            case 2 :
                multiplayerMode();
                break;
            case 3 :
                autoMode();
                break;
            case 9 :
                modeChoice = 9;
                break;
            default:
                printf("Wrong choice, choose again!\n");
        }
    } while (modeChoice != 9);

    return 0;
}

void multiplayerMode() {
    //    Mode multiplayer (2)
    min = 0;
    max = 0;
    tries = 0;

    do {
        printf("Hello player 1, you have to make player 2 guess a number. Ready or not, let's go ! \n\n");
        printf("Please enter the minimum number to guess : \n");
        scanf("%d", &min);
        printf("Please enter the maximum number to guess : \n");
        scanf("%d", &max);

        if (max <= min) {
            printf("The maximum can't be smaller than the minimum\n\n");
        } else {
            printf("Please enter the number of tries : \n");
            scanf("%d", &tries);

            if (tries <= 0) {
                printf("The number of tries cannot be negative or 0\n\n");
            }
        }

        do {
            printf("Please enter the mysterious number between %d and %d : \n", min, max);
            scanf("%d", &computer_nb);
        } while (computer_nb < 0 || computer_nb > 100);

    } while (max <= min || tries <= 0);

//    system("cls");
//    Doesn't work for reasons I guess, create issue where the input have to be entered twice.
//    An issue with the carriage return perhaps ?

    for (int i = 0; i < 15; i++) {
        printf("\n");
    }

    printf("Hello, player 2 ! Try to guess what number player 1 choosed. \n");
    printf("The minimum is %d, the maximum is %d \n", min, max);
    printf("You have %d tr%s\n", tries, tries > 1 ? "ies" : "y");
    printf("Have fun!\n");

    gameLevel(min, max, tries);
}

void soloMode() {
    //    Mode solo against computer
    levelChoice = 0;
    do {
        printf("Choose your level");
        printf("\n1. Easy (0-20, 10 tries)");
        printf("\n2. Medium (0-50, 10 tries)");
        printf("\n3. Hard (0-1000, 5 tries)");
        printf("\n4. Impossible (0-1000, 3 tries)");
        printf("\n9. Return to mode menu\n");
        scanf("%d", &levelChoice);

        switch (levelChoice) {
            case 1 :
                gameLevel(0, 20, 10);
                break;
            case 2 :
                gameLevel(0, 50, 10);
                break;
            case 3 :
                gameLevel(0, 100, 5);
                break;
            case 4 :
                gameLevel(0, 1000, 3);
                break;
            case 9 :
                levelChoice = 9;
                break;
            default:
                printf("Wrong choice, choose again!\n");
        }
    } while (levelChoice != 9);
}

void gameLevel(int min_i, int max_i, int tries_i) {
    computer_nb = randomComputerNb(min_i, max_i);

    printf("%d\n", computer_nb);

    do {
        do {
//            Guesses
            printf("Please enter your guess between %d and %d : \n", min_i, max_i);
            scanf("%d", &player_nb);
            if (player_nb > max_i || player_nb < min_i) {
//                Verify that the number chosed is between max_i and min_i
                printf("%d is not a valid number. The guess has to be between %d and %d\n", player_nb, min_i, max_i);
            }
        } while (player_nb < min_i || player_nb > max_i);

//       Increment cpt no matter the result
        cpt++;
//        More or less check
        if (computer_nb > player_nb) {
            printf("More\n");
            printf("You tried : %d / %d\n", cpt, tries_i);
        } else if (computer_nb < player_nb) {
            printf("Less\n");
            printf("You tried : %d / %d\n", cpt, tries_i);
        }
//      Check if there are still attempts remaining and if the guessed number is incorrect
    } while ((cpt < tries_i) && (computer_nb != player_nb));

//    Print result
    if (computer_nb == player_nb) {
        printf("Congratulations, you've found the correct number in %d tr%s!\n", cpt, tryPlurial);
    } else {
        printf("\nYou loose, the number was %d", computer_nb);
    }
    printf("\n\n\n\n");
}

void autoMode() {
    //    Mode auto computer against computer with dichotomy research
    min = 0;
    max = 1000;
    computer_nb = randomComputerNb(min, max);
//computer_nb = 400;
    while ( computer_nb != player_nb ) {
        int middle = min + ((max - min) / 2);
        player_nb = middle;
        printf("middle = %d\n", middle);
        printf("computer nb : %d\n", computer_nb);
        if( player_nb > computer_nb){
            max = middle - 1;
            printf("new max : %d\n",max);
        } else {
            min = middle + 1 ;
            printf("new min : %d\n",min);
        }
        printf("------------------------------------------\n");
        cpt++;
    }

    printf("The computer found the number %d in %d turns\n", computer_nb, cpt);

}


int randomComputerNb(int min_i, int max_i) {
    srand(time(NULL));
    return (rand() % (max_i - min_i + 1)) + min_i;
}