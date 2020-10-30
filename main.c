#include <stdio.h>
#include <stdlib.h>

#include "game.h"

/**
*
MegaSena game application.
* The purpose of this application is to generate the desired games of an user without repeating the numbers.
* User can make as many games as he/she wants and the size of each game has to be from 6 to 15 numbers.
* The games will be generated and displayed on the console in crescent order.
* The sorted numbers must be in the 1 to 60 interval.
*
* Author: Maria Cireno
* Version: 1.0
*/


/* Variables declaration */
int n; // Number of games
int m; // Game size
Game* games; // Set of games


int main()
{
    /* Communication whit user and getting inputs */
    printf("\n----------------------------------------------------------------\n");
    printf("                    Welcome to MegaSena Game!                   \n"); // User welcome
    printf("----------------------------------------------------------------\n");
    printf("How many games do you want to make? You can make up to 20 games.\n"); // Asking for the number of games desired
    scanf("%d", &n); // Getting and storing number of games

    if (n < 0 || n > 20) return 0; // Terminate application if the number of games isn't valid

    games = (Game*) malloc (sizeof(Game)*n); // Allocating space for the n games

    // Game sizes loop - getting from the user the size of each game
    for (int i = 0; i < n; i++) {

        printf("Please enter the size of game number %d. The size must be between 6 and 15.\n", i+1); // Asking for the size of each game
        scanf("%d", &m); // Getting and storing size of the i-th game

        // If the user chooses an invalid game size, keeping asking for a valid one.
        while (m < MIN_SIZE || m > MAX_SIZE) {
            printf("This game size is not valid, please enter a number between 6 and 15\n");
            scanf("%d", &m);
        }

        games[i].m = m; // Saving sizes in the first row of bidimensional array
        games[i].numbers = (int*) malloc (sizeof(int)*games[i].m); // Allocating memory to game numbers array

        /* Generating sorted numbers */
        for (int j = 0; j < m; j++) {
            int sortedNumber = ((rand() % 60) + 1); // Calculating random number
            while (isRepNumber(games[i].numbers, games[i].m, sortedNumber)) { // Checking if the number is not repeated
                sortedNumber = ((rand() % 60) + 1); // Generating new number if repeated
            }
            games[i].numbers[j] = sortedNumber; // Storing sorted number
        }

        // Ordenating array in crescent order
        quickSort(games[i].numbers, 0, games[i].m-1);

    }


    /*  Displaying outputs */
    printf("\nGOOD LUCK! These are your games:\n");

    // Printing games
    for (int i = 0; i < n; i++) {;
        printf("\nGAME %d -> ", i+1); // Printing game number

        // Loop to print game sorted number
        for (int j = 0; j < games[i].m; j++) {
            printf("%d ", games[i].numbers[j]);
        }

    }
    printf("\n");

    // Freeing memory
    free(games);
    games = NULL;

    return 0;
}
